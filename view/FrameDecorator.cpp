//
// Created by Igor on 16.10.26..
//

#include "FrameDecorator.h"
#include "../document_structure/Character.h"

#include <algorithm>

using namespace appearance;

namespace view {

    //number of lines on each side, every line is as thick as one character
    static const int SIDE_WIDTH = 2 * document_structure::Character::WIDTH;
    static const int TOP_HEIGHT = 1 * document_structure::Character::HEIGHT;
    static const int MIN_CONTENT_HEIGHT = document_structure::Character::HEIGHT;

    void FrameDecorator::Draw(Window* w) {
        Decorator::Draw(w);
        DrawFrame(w);
    }

    void FrameDecorator::DrawFrame(Window* w) {
        Rect r;
        Bounds(r);

        //top and bottom over the whole width
        for(int i = 0; i < TOP_HEIGHT; i++){
            w->DrawLine(r.x0, r.y0 + i, r.x1, r.y0 + i);
            w->DrawLine(r.x0, r.y1 - 1 - i, r.x1, r.y1 - 1 - i);
        }

        //left and right between them
        for(int i = 0; i < SIDE_WIDTH; i++){
            w->DrawLine(r.x0 + i, r.y0 + TOP_HEIGHT, r.x0 + i, r.y1 - TOP_HEIGHT);
            w->DrawLine(r.x1 - 1 - i, r.y0 + TOP_HEIGHT, r.x1 - 1 - i, r.y1 - TOP_HEIGHT);
        }
    }

    void FrameDecorator::Bounds(Rect& r) {
        Rect inner;
        Decorator::Bounds(inner);

        Point contentOrigin = position + Point(SIDE_WIDTH, TOP_HEIGHT);
        int contentRight = std::max(inner.x1, contentOrigin.x);
        int contentBottom = std::max(inner.y1, contentOrigin.y + MIN_CONTENT_HEIGHT);
        r = Rect(position.x, position.y, contentRight + SIDE_WIDTH, contentBottom + TOP_HEIGHT);
    }

    void FrameDecorator::setPosition(const Point& p) {
        position = p;
        Decorator::setPosition(p + Point(SIDE_WIDTH, TOP_HEIGHT));
    }

} // view
