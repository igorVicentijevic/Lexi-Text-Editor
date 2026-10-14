//
// Created by Igor on 13.10.26..
//

#include "Composition.h"
#include "Compositor.h"

using namespace document_structure;

namespace formatting {

    void Composition::Draw(Window * w) {
        if(root)
            root->Draw(w);
    }

    void Composition::Bounds(Rect &) {

    }

    bool Composition::Intersects(const Point &) {
        return false;
    }

    void Composition::Insert(document_structure::Glyph * g) {
        //this->compositor->onInsert(g);

    }

    void Composition::Remove(document_structure::Glyph *) {

    }

    std::string Composition::getType() const {
        return "Composition";
    }

    void Composition::insertGlyph(Glyph * g, int insertionPoint) {
        this->compositor->onInsert(g,insertionPoint);
    }
} // formatting