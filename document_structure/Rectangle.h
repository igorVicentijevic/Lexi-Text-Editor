//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_RECTANGLE_H
#define LEXI_RECTANGLE_H

#include "Glyph.h"
using namespace document_structure;

namespace document_structure {
    class Rectangle: public Glyph{
        private:
            int _x0, _y0, _x1, _y1;
        public:
            Rectangle(int x0, int y0, int x1, int y1): _x0(x0),_y0(y0),_x1(x1),_y1(y1){}
            void Draw(Window* ) override;
    };
}


#endif //LEXI_RECTANGLE_H
