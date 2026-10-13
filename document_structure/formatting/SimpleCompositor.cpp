//
// Created by Igor on 13.10.26..
//

#include "SimpleCompositor.h"

#include "../Row.h"
#include <vector>

using namespace document_structure;

namespace formatting {
    void SimpleCompositor::onInsert(document_structure::Glyph *g) {
        flattened.push_back(g);

        std::vector<document_structure::Row*> currRows = this->getRowsFromComposition();
        Row* rowToAppendGlyph;

        if(currRows.empty()){
            rowToAppendGlyph = new Row();
            currRows.push_back(rowToAppendGlyph);
        }
        else
        {
            rowToAppendGlyph = currRows[currRows.size()-1];
        }

        if(rowToAppendGlyph->getSize() >= width){
            rowToAppendGlyph = splitRow(rowToAppendGlyph,currRows);
        }

        rowToAppendGlyph->Insert(g);

        this->setRowsForComposition(currRows);
    }

    SimpleCompositor::SimpleCompositor(Composition *composition) : Compositor(composition) {

    }

    document_structure::Row *
    SimpleCompositor::splitRow(document_structure::Row *rowToSplit, std::vector<document_structure::Row *> &currRows) {
        Row* row1 = new Row();
        Row* row2 = new Row();

        int addedGlyphs = 0;
        for(Glyph* curr:rowToSplit->getChildren()){
            if(addedGlyphs < width)
                row1->Insert(curr);
            else
                row2->Insert(curr);
            addedGlyphs++;
        }

        int idxToRemove = std::find(currRows.begin(),currRows.end(),rowToSplit)-currRows.begin();
        currRows.erase(currRows.begin()+idxToRemove);

        currRows.push_back(row1);
        currRows.push_back(row2);

        delete rowToSplit;
        return row2;
    }


} // formatting