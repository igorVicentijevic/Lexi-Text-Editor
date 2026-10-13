//
// Created by Igor on 13.10.26..
//

#include "Column.h"
using namespace document_structure;

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
    int i = std::find(children.begin(), children.end(),g)-children.begin();
    children.erase(children.begin()+i);
    g->setParent(nullptr);
}

std::string Column::getType() const {
    return "Column";
}

void Column::insertRow(Row *row) {
    children.push_back(row);
    row->setParent(this);
}
