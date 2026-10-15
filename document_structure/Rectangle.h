//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_RECTANGLE_H
#define LEXI_RECTANGLE_H

#include "Glyph.h"

namespace document_structure {
    class Rectangle: public Glyph{
        private:
            int _width, _height;
        public:
            Rectangle(int width, int height): _width(width),_height(height){}
            void Draw(Window*) override;
            void Bounds(Rect&) override;

            std::string getType() const override;
    };
}


#endif //LEXI_RECTANGLE_H
