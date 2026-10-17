//
// Created by Igor on 17.10.26..
//

#include "RemoveGlyphCommand.h"

namespace commands {

    RemoveGlyphCommand::RemoveGlyphCommand(formatting::Composition& composition, editor::InsertionPoint& insertionPoint,
                                           int pos):
        composition(composition), insertionPoint(insertionPoint), pos(pos){}

    RemoveGlyphCommand::~RemoveGlyphCommand() {
        delete removed;
    }

    void RemoveGlyphCommand::Execute() {
        if(removed) return;

        removed = composition.removeGlyph(pos);
        //nothing at pos (e.g. Backspace at the beginning) - insertion point stays
        if(removed) insertionPoint.set(pos);
    }

} // commands
