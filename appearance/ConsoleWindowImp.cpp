//
// Created by Igor on 16.10.26..
//

#include "ConsoleWindowImp.h"

#include <iostream>

namespace appearance {

    namespace {
        //ANSI escape codes
        const char* ALTERNATE_SCREEN_ON = "\033[?1049h";
        const char* ALTERNATE_SCREEN_OFF = "\033[?1049l";
        const char* CLEAR_SCREEN = "\033[2J";
        const char* CURSOR_HOME = "\033[H";
        const char* INVERSE = "\033[7m";
        const char* NORMAL = "\033[0m";
    }

    ConsoleWindowImp::ConsoleWindowImp() {
        std::cout << ALTERNATE_SCREEN_ON << std::flush;
    }

    ConsoleWindowImp::~ConsoleWindowImp() {
        std::cout << ALTERNATE_SCREEN_OFF << std::flush;
    }

    void ConsoleWindowImp::DeviceText(char c, int x, int y) {
        if(x < 0 || y < 0) return;
        if((int)buffer.size() <= y) buffer.resize(y + 1);
        std::string& line = buffer[y];
        if((int)line.size() <= x) line.resize(x + 1, ' ');
        line[x] = c;
    }

    void ConsoleWindowImp::DeviceRect(int x0, int y0, int x1, int y1) {
        for(int x = x0; x < x1; x++){
            DeviceText('-', x, y0);
            DeviceText('-', x, y1 - 1);
        }
        for(int y = y0; y < y1; y++){
            DeviceText('|', x0, y);
            DeviceText('|', x1 - 1, y);
        }
    }

    void ConsoleWindowImp::DeviceLine(int x0, int y0, int x1, int y1) {
        if(y0 == y1){
            for(int x = x0; x < x1; x++){
                DeviceText('_', x, y0);
            }
        }
        else if(x0 == x1){
            for(int y = y0; y < y1; y++){
                DeviceText('|', x0, y);
            }
        }
    }

    void ConsoleWindowImp::DeviceCaret(int x, int y0, int y1) {
        if(x < 0 || y0 < 0 || y1 <= y0) return;
        hasCaret = true;
        caretX = x;
        caretY0 = y0;
        caretY1 = y1;

        //caret cells must exist to be shown, even at the end of a line
        for(int y = y0; y < y1; y++){
            if((int)buffer.size() <= y) buffer.resize(y + 1);
            if((int)buffer[y].size() <= x) buffer[y].resize(x + 1, ' ');
        }
    }

    bool ConsoleWindowImp::isCaret(int x, int y) const {
        return hasCaret && x == caretX && y >= caretY0 && y < caretY1;
    }

    void ConsoleWindowImp::DeviceFlush() {
        //the new picture replaces the old one instead of being printed below it
        std::cout << CLEAR_SCREEN << CURSOR_HOME;

        for(int y = 0; y < (int)buffer.size(); y++){
            const std::string& line = buffer[y];
            for(int x = 0; x < (int)line.size(); x++){
                if(isCaret(x, y)) std::cout << INVERSE << line[x] << NORMAL;
                else std::cout << line[x];
            }
            std::cout << std::endl;
        }
        buffer.clear();
        hasCaret = false;
    }

} // appearance
