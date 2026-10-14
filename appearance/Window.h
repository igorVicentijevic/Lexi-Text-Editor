//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_WINDOW_H
#define LEXI_WINDOW_H

#include "Rect.h"

namespace appearance {
    class Window {
        private:
            int width;
            int height;

        public:

            Window(int width, int height):width(width), height(height){}

            void DrawRect(int x0, int y0, int x1, int y1);
            void DrawCharacter(char c);

            int getWidth(){ return width;}
            int getHeight(){ return height;}

        void setWidth(int width);

        void setHeight(int height);
    };
}


#endif //LEXI_WINDOW_H
