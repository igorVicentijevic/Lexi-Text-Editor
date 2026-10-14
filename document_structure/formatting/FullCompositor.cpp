//
// Created by Igor on 14.10.26..
//

#include "FullCompositor.h"

namespace formatting {


    FullCompositor::FullCompositor(Composition *composition) : Compositor(composition) {

    }

    void FullCompositor::onInsert(document_structure::Glyph *g, int insertionPoint) {
        this->inserter->insertGlyph(g,insertionPoint);
        const auto flattend = this->flattenAndDeleteStructure(this->getColFromComposition());
        Column* newColumn = this->createNewStructure(flattend);
        this->setColForComposition(newColumn);

    }

    std::vector<Glyph *> FullCompositor::flattenAndDeleteStructure(Column *col) {
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

    Column *FullCompositor::createNewStructure(const std::vector<Glyph *> & flattened) {
        Column* col = new Column();
        int currInRow = 0;

        Row* row = nullptr;
        for(Glyph* g: flattened){

            if(currInRow == width){
                col->insertRow(row);
                currInRow = 0;
            }

            if(currInRow == 0){
                row = new Row();
            }

            row->insertGlyph(g,currInRow);
            currInRow ++;
        }

        if(row!= nullptr)
            col->insertRow(row);
        return col;
    }


} // formatting