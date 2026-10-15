//
// Created by Igor on 13.10.26..
//

#include "Row.h"

namespace document_structure {

    Point Row::nextPosition(const Point& pos, Glyph* child) {
        Rect r;
        child->Bounds(r);
        return {pos.x + r.width(), pos.y};
    }

    //print
    std::string Row::getType() const {
        return "Row";
    }
} // document_structure
