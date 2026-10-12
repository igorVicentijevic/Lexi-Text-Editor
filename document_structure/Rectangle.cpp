//
// Created by Igor on 13.10.26..
//

#include "Rectangle.h"

void Rectangle::Draw(Window * w) {
    w->DrawRect(_x0,_y0,_x1,_y1);
}