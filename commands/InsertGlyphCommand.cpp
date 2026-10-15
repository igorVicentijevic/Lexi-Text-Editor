//
// Created by Igor on 16.10.26..
//

#include "InsertGlyphCommand.h"

namespace commands {

    InsertGlyphCommand::InsertGlyphCommand(formatting::Composition& composition, editor::InsertionPoint& insertionPoint,
                                           document_structure::Glyph* glyph, int pos):
        composition(composition), insertionPoint(insertionPoint), glyph(glyph), pos(pos){}

    InsertGlyphCommand::~InsertGlyphCommand() {
        if(!executed) delete glyph;
    }

    void InsertGlyphCommand::Execute() {
        if(executed) return;

        composition.insertGlyph(glyph, pos);
        executed = true;
        insertionPoint.set(pos + 1);
    }

} // commands
