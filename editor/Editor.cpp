//
// Created by Igor on 16.10.26..
//

#include "Editor.h"
#include "InsertionPoint.h"
#include "../document_structure/formatting/Composition.h"
#include "../document_structure/formatting/FullCompositor.h"
#include "../document_structure/formatting/environment_source/LineWidthSource.h"
#include "../commands/CommandFactory.h"

namespace editor {

    Editor::Editor(appearance::Window* window): window(window) {
        lineWidthSource = new formatting::LineWidthSource(*window);
        compositor = new formatting::FullCompositor(*lineWidthSource);
        composition = new formatting::Composition();
        composition->setCompositor(compositor);
        insertionPoint = new InsertionPoint(*composition);

        //everything exists, the factory can get its receivers
        factory = new commands::CommandFactory(*composition, *window, *lineWidthSource, *insertionPoint);
    }

    Editor::~Editor() {
        //everyone is deleted before the objects it uses
        delete factory;
        delete insertionPoint;
        delete composition;
        delete compositor;
        delete lineWidthSource;
        delete window;
    }

    commands::CommandFactory& Editor::commands() {
        return *factory;
    }

    void Editor::redraw() {
        composition->Draw(window);
        window->Flush();
    }

    document_structure::Glyph* Editor::hitTest(const appearance::Point& p) {
        return composition->HitTest(p);
    }

    int Editor::getInsertionPoint() const {
        return insertionPoint->get();
    }

    int Editor::getWidth() const {
        return window->getWidth();
    }

} // editor
