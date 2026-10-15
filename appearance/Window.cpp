//
// Created by Igor on 13.10.26..
//

#include "Window.h"

appearance::Window::Window(int width, int height, WindowImp* imp):
    width(width), height(height), imp(imp){}

appearance::Window::~Window() {
    delete imp;
}

void appearance::Window::DrawCharacter(char c, int x, int y){
    imp->DeviceText(c, x, y);
}

void appearance::Window::DrawRect(int x0, int y0, int x1, int y1){
    imp->DeviceRect(x0, y0, x1, y1);
}

void appearance::Window::Flush() {
    imp->DeviceFlush();
}

void appearance::Window::setWidth(int width) {
    Window::width = width;
}

void appearance::Window::setHeight(int height) {
    Window::height = height;
}
