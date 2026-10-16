//
// Created by Igor on 16.10.26..
//

#include "Editor.h"
#include "InsertionPoint.h"
#include "../document_structure/formatting/Composition.h"
#include "../document_structure/formatting/FullCompositor.h"
#include "../document_structure/formatting/environment_source/LineWidthSource.h"
#include "../commands/CommandFactory.h"
#include "../view/DocumentView.h"
#include "../view/FrameDecorator.h"
#include "../view/CaretDecorator.h"

namespace editor {

    Editor::Editor(appearance::Window* window): window(window) {
        lineWidthSource = new formatting::LineWidthSource(*window);
        compositor = new formatting::FullCompositor(*lineWidthSource);
        composition = new formatting::Composition();
        composition->setCompositor(compositor);

        insertionPoint = new InsertionPoint(*composition);

        view = new view::FrameDecorator(
                   new view::CaretDecorator(new view::DocumentView(*composition), *composition, *insertionPoint));
        view->setPosition(appearance::Point(0, 0));

        //everything exists, the factory can get its receivers
        factory = new commands::CommandFactory(*composition, *window, *lineWidthSource, *insertionPoint);
    }

    Editor::~Editor() {
        //everyone is deleted before the objects it uses
        delete factory;
        delete view;
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
        view->Draw(window);
        window->Flush();
    }

    document_structure::Glyph* Editor::hitTest(const appearance::Point& p) {
        return view->HitTest(p);
    }

    int Editor::getInsertionPoint() const {
        return insertionPoint->get();
    }

    int Editor::getWidth() const {
        return window->getWidth();
    }

} // editor
