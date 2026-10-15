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

    void ConsoleWindowImp::DeviceFlush() {
        for(const std::string& line: buffer){
            std::cout << line << std::endl;
        }
        buffer.clear();
    }

} // appearance
