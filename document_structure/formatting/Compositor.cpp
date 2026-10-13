//
// Created by Igor on 13.10.26..
//

#include "Compositor.h"
#include "Composition.h"

namespace formatting {
    void Compositor::onInsert(document_structure::Glyph *g) {

    }

    std::vector<document_structure::Row*> Compositor::getRowsFromComposition() {
        return this->composition->childrenRows;
    }

    void Compositor::setRowsForComposition(std::vector<document_structure::Row *> rows) {
        this->composition->childrenRows=rows;
    }
} // formatting