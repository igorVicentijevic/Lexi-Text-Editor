//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_RECT_H
#define LEXI_RECT_H

#include "Point.h"

namespace appearance {

    //(x0,y0) is inclusive, (x1,y1) is exclusive
    class Rect {
        public:
            int x0 = 0, y0 = 0, x1 = 0, y1 = 0;

            Rect() = default;
            Rect(int x0, int y0, int x1, int y1): x0(x0), y0(y0), x1(x1), y1(y1){}

            int width() const { return x1 - x0; }
            int height() const { return y1 - y0; }

            bool contains(const Point& p) const {
                return p.x >= x0 && p.x < x1 && p.y >= y0 && p.y < y1;
            }
    };

} // appearance

#endif //LEXI_RECT_H
