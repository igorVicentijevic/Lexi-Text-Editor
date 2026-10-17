//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_COMMANDFACTORY_H
#define LEXI_COMMANDFACTORY_H

#include "Command.h"

#include <string>

namespace appearance { class Window; }
namespace document_structure { class Glyph; }
namespace formatting {
    class Composition;
    class LineWidthSource;
}
namespace editor { class InsertionPoint; }

namespace commands {

    //Creates commands with their receivers, so the caller doesn't have to know about them.
    //Returned commands are owned by the caller and must not outlive the receivers.
    class CommandFactory {
        private:
            formatting::Composition& composition;
            appearance::Window& window;
            formatting::LineWidthSource& widthSource;
            editor::InsertionPoint& insertionPoint;

        public:
            CommandFactory(formatting::Composition& composition, appearance::Window& window,
                           formatting::LineWidthSource& widthSource, editor::InsertionPoint& insertionPoint);

            //inserts at the current insertion point, takes ownership of the glyph
            Command* insertGlyph(document_structure::Glyph* g);
            //inserts characters of the string at the current insertion point
            Command* insertString(const std::string& s);
            //removes the glyph in front of the insertion point (Backspace)
            Command* removeGlyph();
            Command* moveInsertionPoint(int pos);
            Command* changeWidth(int width);
    };

} // commands

#endif //LEXI_COMMANDFACTORY_H
