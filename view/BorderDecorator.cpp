//
// Created by Igor on 16.10.26..
//

#include "BorderDecorator.h"
#include "../document_structure/Character.h"

#include <algorithm>

using namespace appearance;

namespace view {

    //line is as wide and as high as one character
    static const int THICKNESS = document_structure::Character::WIDTH;
    static const int MIN_HEIGHT = document_structure::Character::HEIGHT;

    void BorderDecorator::Draw(Window* w) {
        Decorator::Draw(w);
        DrawBorder(w);
    }

    void BorderDecorator::DrawBorder(Window* w) {
        Rect r;
        Bounds(r);
        for(int y = r.y0; y < r.y1; y++){
            w->DrawCharacter('|', r.x0, y);
            w->DrawCharacter('|', r.x1 - THICKNESS, y);
        }
    }

    void BorderDecorator::Bounds(Rect& r) {
        Rect inner;
        Decorator::Bounds(inner);

        int contentRight = std::max(inner.x1, position.x + THICKNESS);
        int bottom = std::max(inner.y1, position.y + MIN_HEIGHT);
        r = Rect(position.x, position.y, contentRight + THICKNESS, bottom);
    }

    void BorderDecorator::setPosition(const Point& p) {
        position = p;
        Decorator::setPosition(p + Point(THICKNESS, 0));
    }

} // view
