//
// Created by Igor on 13.10.26..
//

#include "Compositor.h"
#include "Composition.h"

namespace formatting {
    void Compositor::onInsert(document_structure::Glyph *g) {

    }

    document_structure::Column* Compositor::getColFromComposition() {
        return this->composition->column;
    }

    void Compositor::setColForComposition(Column* col) {
        this->composition->column = col;
    }
} // formatting