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

        rowToAppendGlyph->Insert(g);

        this->setRowsForComposition(currRows);
    }

    SimpleCompositor::SimpleCompositor(Composition *composition) : Compositor(composition) {

    }
} // formatting