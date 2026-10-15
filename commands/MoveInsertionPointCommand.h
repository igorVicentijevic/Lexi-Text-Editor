//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_MOVEINSERTIONPOINTCOMMAND_H
#define LEXI_MOVEINSERTIONPOINTCOMMAND_H

#include "Command.h"
#include "../editor/InsertionPoint.h"

namespace commands {

    class MoveInsertionPointCommand: public Command {
        private:
            editor::InsertionPoint& insertionPoint;
            int pos;

        public:
            MoveInsertionPointCommand(editor::InsertionPoint& insertionPoint, int pos):
                insertionPoint(insertionPoint), pos(pos){}

            void Execute() override { insertionPoint.set(pos); }
    };

} // commands

#endif //LEXI_MOVEINSERTIONPOINTCOMMAND_H
