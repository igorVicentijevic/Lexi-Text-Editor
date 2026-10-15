//
// Created by Igor on 13.10.26..
//

#include "Window.h"
#include <iostream>

void appearance::Window::DrawCharacter(char c, int x, int y){
    if(x < 0 || y < 0) return;
    if((int)buffer.size() <= y) buffer.resize(y + 1);
    std::string& line = buffer[y];
    if((int)line.size() <= x) line.resize(x + 1, ' ');
    line[x] = c;
}

void appearance::Window::DrawRect(int x0, int y0, int x1, int y1){
    for(int x = x0; x < x1; x++){
        DrawCharacter('-', x, y0);
        DrawCharacter('-', x, y1 - 1);
    }
    for(int y = y0; y < y1; y++){
        DrawCharacter('|', x0, y);
        DrawCharacter('|', x1 - 1, y);
    }
}

void appearance::Window::Flush() {
    for(const std::string& line: buffer){
        std::cout << line << std::endl;
    }
    buffer.clear();
}

void appearance::Window::setWidth(int width) {
    Window::width = width;
}

void appearance::Window::setHeight(int height) {
    Window::height = height;
}
