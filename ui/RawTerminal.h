//
// Created by Igor on 17.10.26..
//

#ifndef LEXI_RAWTERMINAL_H
#define LEXI_RAWTERMINAL_H

#include <termios.h>

namespace ui {

    //one pressed key; c is set only for Char
    struct Key {
        enum Type { Char, Left, Right, Up, Down, Backspace, Enter, Menu, Quit, Other };

        Type type;
        char c;

        Key(Type type, char c = 0): type(type), c(c) {}
    };

    //Switches the terminal to raw mode while it exists: keys arrive immediately,
    //without Enter, and are not echoed. The original mode is restored in the destructor.
    class RawTerminal {
        private:
            termios original;
            termios raw;
            //false when stdin is not a terminal (e.g. input from a file)
            bool active = false;

            void enableRaw();
            void restoreOriginal();

        public:
            //Normal mode while it exists (e.g. for reading whole lines with cin), raw mode again after it.
            class Pause {
                private:
                    RawTerminal& terminal;
                public:
                    explicit Pause(RawTerminal& terminal): terminal(terminal) { terminal.restoreOriginal(); }
                    ~Pause() { terminal.enableRaw(); }

                    Pause(const Pause&) = delete;
                    Pause& operator=(const Pause&) = delete;
            };

            RawTerminal();
            ~RawTerminal();

            RawTerminal(const RawTerminal&) = delete;
            RawTerminal& operator=(const RawTerminal&) = delete;

            //waits for one key; end of input is reported as Quit
            Key readKey();
    };

} // ui

#endif //LEXI_RAWTERMINAL_H
