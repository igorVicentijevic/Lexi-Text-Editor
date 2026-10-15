//
// Created by Igor on 13.10.26..
//

#include "Rectangle.h"

using namespace document_structure;

void Rectangle::Draw(Window * w) {
    w->DrawRect(position.x, position.y, position.x + _width, position.y + _height);
}

void Rectangle::Bounds(Rect& r) {
    r = Rect(position.x, position.y, position.x + _width, position.y + _height);
}

std::string Rectangle::getType() const {
    return "Rectangle";
}
