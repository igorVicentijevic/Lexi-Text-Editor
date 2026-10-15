//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_CHANGEWIDTHCOMMAND_H
#define LEXI_CHANGEWIDTHCOMMAND_H

#include "Command.h"
#include "../appearance/Window.h"
#include "../document_structure/formatting/Composition.h"
#include "../document_structure/formatting/environment_source/LineWidthSource.h"

namespace commands {

    //changes window width and reformats the document
    class ChangeWidthCommand: public Command {
        private:
            appearance::Window& window;
            formatting::Composition& composition;
            formatting::LineWidthSource& widthSource;
            int width;

        public:
            ChangeWidthCommand(appearance::Window& window, formatting::Composition& composition,
                               formatting::LineWidthSource& widthSource, int width):
                window(window), composition(composition), widthSource(widthSource), width(width){}

            void Execute() override {
                window.setWidth(width);
                composition.environmentChanged(widthSource);
            }
    };

} // commands

#endif //LEXI_CHANGEWIDTHCOMMAND_H
