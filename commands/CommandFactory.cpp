//
// Created by Igor on 16.10.26..
//

#include "CommandFactory.h"
#include "InsertGlyphCommand.h"
#include "MacroCommand.h"
#include "RemoveGlyphCommand.h"
#include "MoveInsertionPointCommand.h"
#include "ChangeWidthCommand.h"
#include "../document_structure/Character.h"
#include "../editor/InsertionPoint.h"

namespace commands {

    CommandFactory::CommandFactory(formatting::Composition& composition, appearance::Window& window,
                                   formatting::LineWidthSource& widthSource, editor::InsertionPoint& insertionPoint):
        composition(composition), window(window), widthSource(widthSource), insertionPoint(insertionPoint){}

    Command* CommandFactory::insertGlyph(document_structure::Glyph* g) {
        return new InsertGlyphCommand(composition, insertionPoint, g, insertionPoint.get());
    }

    Command* CommandFactory::insertString(const std::string& s) {
        MacroCommand* m = new MacroCommand();
        int pos = insertionPoint.get();
        for(char c: s){
            m->Add(new InsertGlyphCommand(composition, insertionPoint, new document_structure::Character(c), pos++));
        }
        return m;
    }

    Command* CommandFactory::removeGlyph() {
        return new RemoveGlyphCommand(composition, insertionPoint, insertionPoint.get() - 1);
    }

    Command* CommandFactory::moveInsertionPoint(int pos) {
        return new MoveInsertionPointCommand(insertionPoint, pos);
    }

    Command* CommandFactory::changeWidth(int width) {
        return new ChangeWidthCommand(window, composition, widthSource, width);
    }

} // commands
