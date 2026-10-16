//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_WINDOW_H
#define LEXI_WINDOW_H

#include "Rect.h"
#include "WindowImp.h"

namespace appearance {
    //Abstraction part of the Bridge: what glyphs draw on.
    //Platform specific work is forwarded to WindowImp.
    class Window {
        private:
            int width;
            int height;

            //owned
            WindowImp* imp;

        public:

            Window(int width, int height, WindowImp* imp);
            ~Window();

            Window(const Window&) = delete;
            Window& operator=(const Window&) = delete;

            void DrawRect(int x0, int y0, int x1, int y1);
            //horizontal or vertical line from (x0,y0) to (x1,y1), the end is exclusive
            void DrawLine(int x0, int y0, int x1, int y1);
            //coordinates are in document units (one character = one cell)
            void DrawCharacter(char c, int x, int y);

            //shows everything drawn since the last flush
            void Flush();

            int getWidth(){ return width;}
            int getHeight(){ return height;}

        void setWidth(int width);

        void setHeight(int height);
    };
}


#endif //LEXI_WINDOW_H
