//
// Created by Igor on 16.10.26..
//

#include "InsertGlyphCommand.h"

namespace commands {

    InsertGlyphCommand::InsertGlyphCommand(editor::Editor& editor, document_structure::Glyph* glyph, int pos):
        editor(editor), glyph(glyph), pos(pos){}

    InsertGlyphCommand::~InsertGlyphCommand() {
        if(!executed) delete glyph;
    }

    void InsertGlyphCommand::Execute() {
        if(executed) return;

        editor.getComposition().insertGlyph(glyph, pos);
        executed = true;
        editor.setInsertionPoint(pos + 1);
    }

} // commands
