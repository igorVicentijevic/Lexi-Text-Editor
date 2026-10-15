//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_WINDOW_H
#define LEXI_WINDOW_H

#include "Rect.h"

#include <string>
#include <vector>

namespace appearance {
    //console window: drawing goes into a character buffer, Flush prints it
    class Window {
        private:
            int width;
            int height;

            std::vector<std::string> buffer;

        public:

            Window(int width, int height):width(width), height(height){}

            void DrawRect(int x0, int y0, int x1, int y1);
            //coordinates are in document units (one character = one cell)
            void DrawCharacter(char c, int x, int y);

            //prints everything drawn since the last flush
            void Flush();

            int getWidth(){ return width;}
            int getHeight(){ return height;}

        void setWidth(int width);

        void setHeight(int height);
    };
}


#endif //LEXI_WINDOW_H
