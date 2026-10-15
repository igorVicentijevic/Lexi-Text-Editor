//
// Created by Igor on 13.10.26..
//

#include "Column.h"

#include <algorithm>
using namespace document_structure;

//rows belong to the layout, glyphs inside them belong to the composition
Column::~Column() {
    for(Row* row: children){
        delete row;
    }
}

void Column::Draw(Window *window) {
        for(Glyph* curr: this->children){
            curr->Draw(window);
        }
}

void Column::Bounds(Rect &rect) {

}

bool Column::Intersects(const Point &point) {
    return false;
}

void Column::Insert(document_structure::Glyph *g) {

}

void Column::Remove(document_structure::Glyph *g) {
    auto it = std::find(children.begin(), children.end(),g);
    if(it == children.end()) return;
    children.erase(it);
    g->setParent(nullptr);
}

std::string Column::getType() const {
    return "Column";
}

void Column::insertRow(Row *row) {
    children.push_back(row);
    row->setParent(this);
}
