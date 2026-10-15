//
// Created by Igor on 16.10.26..
//

#include "Editor.h"
#include "../document_structure/formatting/FullCompositor.h"

namespace editor {

    Editor::Editor(appearance::Window* window): window(window) {
        lineWidthSource = new formatting::LineWidthSource(*window);
        compositor = new formatting::FullCompositor(*lineWidthSource);
        composition = new formatting::Composition();
        composition->setCompositor(compositor);
    }

    Editor::~Editor() {
        //composition uses the compositor, compositor uses the width source, width source uses the window
        delete composition;
        delete compositor;
        delete lineWidthSource;
        delete window;
    }

    void Editor::setInsertionPoint(int pos) {
        if(pos < 0) pos = 0;
        if(pos > composition->ChildCount()) pos = composition->ChildCount();
        insertionPoint = pos;
    }

    void Editor::setWidth(int width) {
        window->setWidth(width);
        composition->environmentChanged(*lineWidthSource);
    }

} // editor
