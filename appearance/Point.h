//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_POINT_H
#define LEXI_POINT_H

namespace appearance {

    class Point {
        public:
            int x;
            int y;

            Point(int x = 0, int y = 0): x(x), y(y){}

            Point operator+(const Point& p) const { return {x + p.x, y + p.y}; }
            Point operator-(const Point& p) const { return {x - p.x, y - p.y}; }
    };

} // appearance

#endif //LEXI_POINT_H
