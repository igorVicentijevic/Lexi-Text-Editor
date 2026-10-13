//
// Created by Igor on 13.10.26..
//

#include "SimpleCompositor.h"

#include "../Row.h"
#include <vector>
#include "../insertion/Inserter.h"

using namespace document_structure;

namespace formatting {
    void SimpleCompositor::onInsert(document_structure::Glyph *g,int insertionPoint) {
        //flattened.push_back(g);

        //std::vector<document_structure::Row*> currRows = this->getRowsFromComposition();

        insertion::Inserter::InsertionData data = this->inserter->insertGlyph(g,insertionPoint);

        handleGlyphShifting(data);

        Column* currCol =  this->getColFromComposition();

        std::vector<document_structure::Row*> currRows;
        if(currCol!= nullptr)
             currRows = this->getColFromComposition()->getChildren();

        Row* lastRow = currCol->getChildren().back();
        if(lastRow->getSize() > width){
            splitRow(lastRow,currRows);
        }

        Column* newCol = new Column();
        for(Row* curr: currRows){
            newCol->insertRow(curr);
        }

        this->setColForComposition(newCol);

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

    void SimpleCompositor::handleGlyphShifting(insertion::Inserter::InsertionData iData) {
        Column* col = this->getColFromComposition();

        auto& rows = col->getChildren();
        int rowIndx = std::find(rows.begin(), rows.end(),iData.row)-rows.begin();

        while(rowIndx < rows.size()-1){

            Row* currRow = rows[rowIndx];

            Glyph* gToTransfer = currRow->getChildren().back();

            auto& rowChildren = currRow->getChildren();
            rowChildren.erase(
                    std::find(rowChildren.begin(),rowChildren.end(),gToTransfer)
                    );

            Row* nextRow = col->getChildren()[rowIndx+1];

            auto& nextRowChildren = nextRow->getChildren();
            nextRowChildren.insert(nextRowChildren.begin()+0,gToTransfer);

            rowIndx++;
        }
    }




} // formatting