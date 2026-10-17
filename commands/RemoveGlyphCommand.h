//
// Created by Igor on 17.10.26..
//

#ifndef LEXI_REMOVEGLYPHCOMMAND_H
#define LEXI_REMOVEGLYPHCOMMAND_H

#include "Command.h"
#include "../document_structure/formatting/Composition.h"
#include "../editor/InsertionPoint.h"

namespace commands {

    //Removes the glyph at the given position and puts the insertion point where it was.
    //The removed glyph is owned by the command, same as before an insert.
    class RemoveGlyphCommand: public Command {
        private:
            formatting::Composition& composition;
            editor::InsertionPoint& insertionPoint;
            int pos;
            document_structure::Glyph* removed = nullptr;

        public:
            RemoveGlyphCommand(formatting::Composition& composition, editor::InsertionPoint& insertionPoint, int pos);
            ~RemoveGlyphCommand() override;

            RemoveGlyphCommand(const RemoveGlyphCommand&) = delete;
            RemoveGlyphCommand& operator=(const RemoveGlyphCommand&) = delete;

            void Execute() override;
    };

} // commands

#endif //LEXI_REMOVEGLYPHCOMMAND_H
