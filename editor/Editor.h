//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_EDITOR_H
#define LEXI_EDITOR_H

#include "../appearance/Window.h"
#include "../appearance/Point.h"
#include "../document_structure/Glyph.h"

namespace formatting {
    class Composition;
    class Compositor;
    class LineWidthSource;
}
namespace commands {
    class Command;
    class CommandFactory;
}
namespace view { class VisualComponent; }

namespace editor {

    class InsertionPoint;
    class PositionLocator;

    //Creates and connects everything the editor is made of and owns it.
    //Changes are made through commands, the rest is what the UI needs to show the document.
    class Editor {
        private:
            appearance::Window* window;
            formatting::LineWidthSource* lineWidthSource;
            formatting::Compositor* compositor;
            formatting::Composition* composition;
            //what is drawn on the window - the document with its decorations
            view::VisualComponent* view;
            InsertionPoint* insertionPoint;
            PositionLocator* locator;
            commands::CommandFactory* factory;

        public:
            //takes ownership of the window
            explicit Editor(appearance::Window* window);
            ~Editor();

            Editor(const Editor&) = delete;
            Editor& operator=(const Editor&) = delete;

            commands::CommandFactory& commands();
            //every command goes through here, so command history (undo) can be added in one place;
            //takes ownership of the command
            void execute(commands::Command* c);

            //draws the document and shows it in the window
            void redraw();
            //deepest glyph at the point, nullptr if there is none
            document_structure::Glyph* hitTest(const appearance::Point& p);

            int getInsertionPoint() const;
            int getWidth() const;
    };

} // editor

#endif //LEXI_EDITOR_H
