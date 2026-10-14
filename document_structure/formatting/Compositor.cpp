//
// Created by Igor on 13.10.26..
//

#include "Compositor.h"
#include "Composition.h"

namespace formatting {


    document_structure::Glyph* Compositor::getRootFromComposition() {
        return this->composition->root;
    }

    void Compositor::setRootForComposition(Glyph* root) {
        this->composition->root = root;
    }
} // formatting