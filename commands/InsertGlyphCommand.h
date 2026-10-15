//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_INSERTGLYPHCOMMAND_H
#define LEXI_INSERTGLYPHCOMMAND_H

#include "Command.h"
#include "../editor/Editor.h"

namespace commands {

    //Inserts a glyph at the given position and moves the insertion point after it.
    //After Execute the composition owns the glyph, before that the command does.
    class InsertGlyphCommand: public Command {
        private:
            editor::Editor& editor;
            document_structure::Glyph* glyph;
            int pos;
            bool executed = false;

        public:
            InsertGlyphCommand(editor::Editor& editor, document_structure::Glyph* glyph, int pos);
            ~InsertGlyphCommand() override;

            InsertGlyphCommand(const InsertGlyphCommand&) = delete;
            InsertGlyphCommand& operator=(const InsertGlyphCommand&) = delete;

            void Execute() override;
    };

} // commands

#endif //LEXI_INSERTGLYPHCOMMAND_H
