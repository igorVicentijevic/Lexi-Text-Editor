//
// Created by Igor on 17.10.26..
//

#include "RawTerminal.h"

#include <unistd.h>

namespace ui {

    namespace {
        const char ESC = 27;
        const char DEL = 127;    //Backspace on macOS
        const char CTRL_O = 15;
        const char CTRL_Q = 17;
    }

    RawTerminal::RawTerminal() {
        if(tcgetattr(STDIN_FILENO, &original) != 0) return;

        termios raw = original;
        //no waiting for Enter, no echo, Ctrl+O is not swallowed by the terminal
        raw.c_lflag &= ~(ICANON | ECHO | IEXTEN);
        //Ctrl+Q/Ctrl+S are not used for flow control
        raw.c_iflag &= ~IXON;
        //read returns as soon as one byte arrives
        raw.c_cc[VMIN] = 1;
        raw.c_cc[VTIME] = 0;

        active = tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == 0;
    }

    RawTerminal::~RawTerminal() {
        if(active) tcsetattr(STDIN_FILENO, TCSAFLUSH, &original);
    }

    Key RawTerminal::readKey() {
        char c;
        if(read(STDIN_FILENO, &c, 1) != 1) return Key(Key::Quit);

        if(c == ESC){
            //arrows arrive as ESC [ A/B/C/D
            char seq[2];
            if(read(STDIN_FILENO, &seq[0], 1) != 1 || seq[0] != '[') return Key(Key::Other);
            if(read(STDIN_FILENO, &seq[1], 1) != 1) return Key(Key::Other);

            switch(seq[1]){
                case 'A': return Key(Key::Up);
                case 'B': return Key(Key::Down);
                case 'C': return Key(Key::Right);
                case 'D': return Key(Key::Left);
                default: return Key(Key::Other);
            }
        }

        if(c == DEL || c == '\b') return Key(Key::Backspace);
        if(c == '\n' || c == '\r') return Key(Key::Enter);
        if(c == CTRL_O) return Key(Key::Menu);
        if(c == CTRL_Q) return Key(Key::Quit);
        if(c >= 32 && c < 127) return Key(Key::Char, c);

        return Key(Key::Other);
    }

} // ui
