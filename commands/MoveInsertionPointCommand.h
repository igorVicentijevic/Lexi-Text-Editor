//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_MOVEINSERTIONPOINTCOMMAND_H
#define LEXI_MOVEINSERTIONPOINTCOMMAND_H

#include "Command.h"
#include "../editor/Editor.h"

namespace commands {

    class MoveInsertionPointCommand: public Command {
        private:
            editor::Editor& editor;
            int pos;

        public:
            MoveInsertionPointCommand(editor::Editor& editor, int pos): editor(editor), pos(pos){}

            void Execute() override { editor.setInsertionPoint(pos); }
    };

} // commands

#endif //LEXI_MOVEINSERTIONPOINTCOMMAND_H
