//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_UI_H
#define LEXI_UI_H

#include "../editor/Editor.h"
#include "../commands/Command.h"

#include <string>
#include <vector>

namespace ui{
    //Console input/output: reads what the user wants, turns it into a command and executes it.
    class UI {
        private:
            struct MenuItem {
                std::string label;
                void (UI::*handler)();
            };

            editor::Editor* editor;
            std::vector<MenuItem> menu;

            bool quit = false;

        private:
            void printConfig();
            void printOptions();
            int readOption();
            void callOption(int);

            //executes and deletes the command
            void execute(commands::Command* c);

            void handlePutInsertionPoint();
            void handleInsertCharacterOnInsertionPoint();
            void handleAddStringToInsertionPoint();
            void handleQuit();
            void handleWidthChange();
            void handleHitTest();
            void handleAddRectangleToInsertionPoint();
        public:
            UI();
            ~UI();

            UI(const UI&) = delete;
            UI& operator=(const UI&) = delete;

            void start();

    };
}


#endif //LEXI_UI_H
