//
// Created by Igor on 13.10.26..
//

#include "Window.h"
#include <iostream>

void appearance::Window::DrawCharacter(char c){
    std::cout<<c;
}
void appearance::Window::DrawRect(int x0, int y0, int x1, int y1){
    std::cout<<"DrawRect: ("<<x0<<","<<y0<<")"<<"-("<<x1<<","<<y1<<")"<<std::endl;
}