//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_INSERTGLYPHCOMMAND_H
#define LEXI_INSERTGLYPHCOMMAND_H

#include "Command.h"
#include "../document_structure/formatting/Composition.h"
#include "../editor/InsertionPoint.h"

namespace commands {

    //Inserts a glyph at the given position and moves the insertion point after it.
    //After Execute the composition owns the glyph, before that the command does.
    class InsertGlyphCommand: public Command {
        private:
            formatting::Composition& composition;
            editor::InsertionPoint& insertionPoint;
            document_structure::Glyph* glyph;
            int pos;
            bool executed = false;

        public:
            InsertGlyphCommand(formatting::Composition& composition, editor::InsertionPoint& insertionPoint,
                               document_structure::Glyph* glyph, int pos);
            ~InsertGlyphCommand() override;

            InsertGlyphCommand(const InsertGlyphCommand&) = delete;
            InsertGlyphCommand& operator=(const InsertGlyphCommand&) = delete;

            void Execute() override;
    };

} // commands

#endif //LEXI_INSERTGLYPHCOMMAND_H
