//
// Created by Igor on 13.10.26..
//

#include "Glyph.h"

namespace document_structure {
    int document_structure::Glyph::ID = 0;

    std::ostream &operator<<(std::ostream &os, const Glyph &g) {
        os << g.getType() << ":" << g.getId() << std::endl;
//        for (Glyph *child: g.children) {
//            os<<*child;
//        }

        return os;
    }

    Glyph::Glyph() {
        id = ID++;
    }

    int Glyph::getId() const {
        return id;
    }

}