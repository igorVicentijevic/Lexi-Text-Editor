//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_CHANGEWIDTHCOMMAND_H
#define LEXI_CHANGEWIDTHCOMMAND_H

#include "Command.h"
#include "../editor/Editor.h"

namespace commands {

    //changes window width and reformats the document
    class ChangeWidthCommand: public Command {
        private:
            editor::Editor& editor;
            int width;

        public:
            ChangeWidthCommand(editor::Editor& editor, int width): editor(editor), width(width){}

            void Execute() override { editor.setWidth(width); }
    };

} // commands

#endif //LEXI_CHANGEWIDTHCOMMAND_H
