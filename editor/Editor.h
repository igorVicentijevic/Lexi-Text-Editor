//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_EDITOR_H
#define LEXI_EDITOR_H

#include "../appearance/Window.h"
#include "../document_structure/formatting/Composition.h"
#include "../document_structure/formatting/Compositor.h"
#include "../document_structure/formatting/environment_source/LineWidthSource.h"

namespace editor {

    //State of the editor that commands work on.
    //Owns the window, the document and everything needed to format it.
    class Editor {
        private:
            appearance::Window* window;
            formatting::LineWidthSource* lineWidthSource;
            formatting::Compositor* compositor;
            formatting::Composition* composition;

            int insertionPoint = 0;

        public:
            //takes ownership of the window
            explicit Editor(appearance::Window* window);
            ~Editor();

            Editor(const Editor&) = delete;
            Editor& operator=(const Editor&) = delete;

            formatting::Composition& getComposition() { return *composition; }
            appearance::Window& getWindow() { return *window; }

            int getInsertionPoint() const { return insertionPoint; }
            //clamped to the document
            void setInsertionPoint(int pos);

            //changes window width and reformats the document
            void setWidth(int width);
    };

} // editor

#endif //LEXI_EDITOR_H
