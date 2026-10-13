//
// Created by Igor on 13.10.26..
//

#include "Composition.h"

namespace formatting {

    void Composition::Draw(Window * w) {

    }

    void Composition::Bounds(Rect &) {

    }

    bool Composition::Intersects(const Point &) {
        return false;
    }

    void Composition::Insert(document_structure::Glyph *) {

    }

    void Composition::Remove(document_structure::Glyph *) {

    }

    std::string Composition::getType() const {
        return "Composition";
    }
} // formatting