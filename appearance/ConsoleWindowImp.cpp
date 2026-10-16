//
// Created by Igor on 16.10.26..
//

#include "ConsoleWindowImp.h"

#include <iostream>

namespace appearance {

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
        //ANSI escape codes for inverse colors and back to normal
        const char* INVERSE = "\033[7m";
        const char* NORMAL = "\033[0m";

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
