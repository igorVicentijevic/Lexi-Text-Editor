//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_UI_H
#define LEXI_UI_H

#include "../document_structure/formatting/Composition.h"
#include "../document_structure/formatting/SimpleCompositor.h"
#include "../appearance/Window.h"
#include "../document_structure/formatting/FullCompositor.h"

namespace ui{
    class UI {
        private:
            formatting::Composition* composition;
            formatting::FullCompositor* compositor;
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
            void handleAddStringToInsertionPoint();
            void handleWidthChange();
        public:
            UI();
            void start();

    };
}


#endif //LEXI_UI_H
