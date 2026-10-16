//
// Created by Igor on 16.10.26..
//

#include "CaretDecorator.h"
#include "../document_structure/Character.h"
#include "../document_structure/formatting/Composition.h"
#include "../editor/InsertionPoint.h"

#include <algorithm>

using namespace appearance;
using document_structure::Glyph;

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
        int pos = insertionPoint.get();
        int count = composition.ChildCount();

        if(pos < count){
            //in front of the glyph that is at the insertion point
            composition.Child(pos)->Bounds(r);
        }
        else if(count > 0){
            //after the last glyph
            Rect last;
            composition.Child(count - 1)->Bounds(last);
            r = Rect(last.x1, last.y0, last.x1 + document_structure::Character::WIDTH, last.y1);
        }
        else {
            //empty document - at its beginning, one line high
            Rect doc;
            composition.Bounds(doc);
            r = Rect(doc.x0, doc.y0, doc.x0 + document_structure::Character::WIDTH,
                     doc.y0 + document_structure::Character::HEIGHT);
        }
    }

} // view
