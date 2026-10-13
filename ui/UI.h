//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_UI_H
#define LEXI_UI_H

#include "../document_structure/formatting/Composition.h"
#include "../appearance/Window.h"

namespace ui{
    class UI {
        private:
            formatting::Composition* composition;
            appearance::Window* window;

            int insertionPoint  = 0;
            bool quit = false;

        private:
            void printConfig();
            void printOptions();
            int readOption();
            void callOption(int);
            void handlePutInsertionPoint();
            void handleInsertCharacterOnInsertionPoint();
        public:
            UI();
            void start();

    };
}


#endif //LEXI_UI_H
