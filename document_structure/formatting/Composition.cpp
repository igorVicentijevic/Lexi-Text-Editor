//
// Created by Igor on 13.10.26..
//

#include "Composition.h"

using namespace document_structure;

namespace formatting {

    void Composition::Draw(Window * w) {

        column->Draw(w);
    }

    void Composition::Bounds(Rect &) {

    }

    bool Composition::Intersects(const Point &) {
        return false;
    }

    void Composition::Insert(document_structure::Glyph * g) {
        this->compositor->onInsert(g);

    }

    void Composition::Remove(document_structure::Glyph *) {

    }

    std::string Composition::getType() const {
        return "Composition";
    }
} // formatting