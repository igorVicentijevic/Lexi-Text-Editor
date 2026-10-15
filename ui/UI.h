//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_UI_H
#define LEXI_UI_H

#include "../editor/Editor.h"
#include "MenuItem.h"

#include <vector>

namespace ui{
    //Console loop: shows the document and the menu and selects the chosen item.
    class UI {
        private:
            editor::Editor* editor;
            //owned
            std::vector<MenuItem*> menu;

            bool quit = false;

        private:
            void printConfig();
            void printOptions();
            int readOption();
            void callOption(int);

        public:
            UI();
            ~UI();

            UI(const UI&) = delete;
            UI& operator=(const UI&) = delete;

            void start();

    };
}


#endif //LEXI_UI_H
