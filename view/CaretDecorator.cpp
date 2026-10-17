//
// Created by Igor on 16.10.26..
//

#include "CaretDecorator.h"
#include "../editor/InsertionPoint.h"
#include "../editor/PositionLocator.h"

#include <algorithm>

using namespace appearance;

namespace view {

    void CaretDecorator::Draw(Window* w) {
        Decorator::Draw(w);

        Rect r;
        caretBounds(r);
        w->DrawCaret(r.x0, r.y0, r.y1);
    }

    void CaretDecorator::Bounds(Rect& r) {
        Decorator::Bounds(r);

        Rect caret;
        caretBounds(caret);
        r.x0 = std::min(r.x0, caret.x0);
        r.y0 = std::min(r.y0, caret.y0);
        r.x1 = std::max(r.x1, caret.x1);
        r.y1 = std::max(r.y1, caret.y1);
    }

    void CaretDecorator::caretBounds(Rect& r) {
        locator.Bounds(insertionPoint.get(), r);
    }

} // view
