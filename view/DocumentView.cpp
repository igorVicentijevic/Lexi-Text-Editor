//
// Created by Igor on 16.10.26..
//

#include "DocumentView.h"
#include "../document_structure/formatting/Composition.h"

namespace view {

    void DocumentView::Draw(appearance::Window* w) {
        composition.Draw(w);
    }

    void DocumentView::Bounds(appearance::Rect& r) {
        composition.Bounds(r);
    }

    void DocumentView::setPosition(const appearance::Point& p) {
        composition.setPosition(p);
    }

    document_structure::Glyph* DocumentView::HitTest(const appearance::Point& p) {
        return composition.HitTest(p);
    }

} // view
