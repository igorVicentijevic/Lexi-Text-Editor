//
// Created by Igor on 13.10.26..
//

#include "Inserter.h"
#include "../formatting/Composition.h"

namespace insertion {
    Glyph* Inserter::getRoot() {
        return this->composition->root;
    }

    void Inserter::setRoot(Glyph* root) {
        this->composition->root = root;
    }
} // insertion