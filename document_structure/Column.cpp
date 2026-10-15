//
// Created by Igor on 13.10.26..
//

#include "Column.h"
using namespace document_structure;

//rows belong to the layout, glyphs inside them belong to the composition
Column::~Column() {
    for(Glyph* row: children){
        delete row;
    }
}

Point Column::nextPosition(const Point& pos, Glyph* child) {
    Rect r;
    child->Bounds(r);
    return {pos.x, pos.y + r.height()};
}

std::string Column::getType() const {
    return "Column";
}
