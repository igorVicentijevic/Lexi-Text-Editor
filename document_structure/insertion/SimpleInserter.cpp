//
// Created by Igor on 13.10.26..
//

#include "SimpleInserter.h"

namespace insertion {
    Inserter::InsertionData SimpleInserter::insertGlyph(Glyph *glyph, int i) {
        int cnt = i;
        Column* col = this->getColumn();

        InsertionData iData;

        iData.row = nullptr;
        iData.pos = -1;

        for(Row* row: col->getChildren()){
            if(row->getSize()<=cnt){
                cnt -= row->getSize();
            }
            else
            {
                iData.row = row;
                iData.pos = cnt;

                insertIntoVector(glyph,cnt,row->getChildren());
                break;
            }
        }
        return iData;
    }

    SimpleInserter::SimpleInserter(formatting::Composition *composition) : Inserter(composition) {}

    void SimpleInserter::insertIntoVector(Glyph * g, int i, std::vector<Glyph *> arr) {
        arr.insert(arr.begin()+i,g);
    }
} // insertion