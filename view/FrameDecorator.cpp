//
// Created by Igor on 16.10.26..
//

#include "FrameDecorator.h"
#include "../document_structure/Character.h"

#include <algorithm>

using namespace appearance;

namespace view {

    //two lines on every side, each as thick as one character
    static const int SIDE_WIDTH = 2 * document_structure::Character::WIDTH;
    static const int TOP_HEIGHT = 2 * document_structure::Character::HEIGHT;
    static const int MIN_CONTENT_HEIGHT = document_structure::Character::HEIGHT;

    void FrameDecorator::Draw(Window* w) {
        Decorator::Draw(w);
        DrawFrame(w);
    }

    void FrameDecorator::DrawFrame(Window* w) {
        Rect r;
        Bounds(r);

        //top and bottom over the whole width
        for(int x = r.x0; x < r.x1; x++){
            for(int i = 0; i < TOP_HEIGHT; i++){
                w->DrawCharacter('_', x, r.y0 + i);
                w->DrawCharacter('_', x, r.y1 - TOP_HEIGHT + i);
            }
        }

        //left and right between them
        for(int y = r.y0 + TOP_HEIGHT; y < r.y1 - TOP_HEIGHT; y++){
            for(int i = 0; i < SIDE_WIDTH; i++){
                w->DrawCharacter('|', r.x0 + i, y);
                w->DrawCharacter('|', r.x1 - SIDE_WIDTH + i, y);
            }
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
