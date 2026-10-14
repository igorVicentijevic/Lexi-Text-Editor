//
// Created by Igor on 13.10.26..
//

#include "Composition.h"
#include "Compositor.h"

#include "../insertion/SimpleInserter.h"

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


    std::string Composition::getType() const {
        return "Composition";
    }

    void Composition::insertGlyph(Glyph * g, int insertionPoint) {
        //this->compositor->onInsert(g,insertionPoint);
        this->inserter->insertGlyph(g,insertionPoint);
        recompose();
    }

    void Composition::recompose() {
        auto flattened = this->flattendAndDeleteStructure();
        this->compositor->compose(flattened);
    }

    std::vector<Glyph *> Composition::flattendAndDeleteStructure() {
        Column* col = dynamic_cast<Column*>(this->root);
        std::vector<Glyph*> flattened;

        for(Row* row: col->getChildren()){
            for(Glyph* g: row->getChildren()){
                flattened.push_back(g);
            }
            delete row;
        }
        delete col;

        return flattened;
    }

    void Composition::environmentChanged(const EnvironmentSource &s) {
            if (compositor->dependsOn(s)) recompose();
    }
} // formatting