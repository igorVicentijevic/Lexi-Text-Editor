//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_UI_H
#define LEXI_UI_H

#include "../editor/Editor.h"
#include "RawTerminal.h"
#include "Menu.h"
#include "Keymap.h"

namespace ui{
    //Console loop: shows the document and passes every pressed key to its binding.
    //The rest of the options are in the menu (Ctrl+O).
    class UI {
        private:
            //first member - raw mode is turned off last, after everything that uses it
            RawTerminal terminal;

            editor::Editor* editor;
            //menu items and key bindings use the editor, so they are deleted before it
            Menu* menu;
            Keymap* keymap;

            bool quit = false;

        private:
            void printConfig();

        public:
            UI();
            ~UI();

            UI(const UI&) = delete;
            UI& operator=(const UI&) = delete;

            void start();

    };
}


#endif //LEXI_UI_H
