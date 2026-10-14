//
// Created by Igor on 13.10.26..
//

#include "SimpleInserter.h"

namespace insertion {
    Inserter::InsertionData SimpleInserter::insertGlyph(Glyph *glyph, int i) {
        int cnt = i;
        Column* col = dynamic_cast<Column*> (this->getRoot());

        if (col == nullptr) {
            col = new Column();
        }

        InsertionData iData;
        iData.row = nullptr;
        iData.pos = -1;

        bool isInserted = false;

        for (Row* row : col->getChildren()) {
            if (row->getSize() <= cnt) {
                cnt -= row->getSize();
            }
            else {
                iData.row = row;
                iData.pos = cnt;

                insertIntoVector(glyph, cnt, row->getChildren());


                isInserted = true;
                break;
            }
        }

        if (!isInserted) {
            Row* lastRow = nullptr;
            if (col->getChildren().size() > 0) {
                lastRow = col->getChildren().back();
            }
            else {
                lastRow = new Row();
                col->insertRow(lastRow);
            }
            lastRow->insertGlyph(glyph, lastRow->getChildren().size());
            iData.row = lastRow;
            iData.pos = lastRow->getChildren().size() - 1;
        }

        this->setRoot(col);
        return iData;
    }

    SimpleInserter::SimpleInserter(formatting::Composition *composition) : Inserter(composition) {}

    void SimpleInserter::insertIntoVector(Glyph* g, int i, std::vector<Glyph*>& arr) {
        arr.insert(arr.begin() + i, g);
    }
} // insertion