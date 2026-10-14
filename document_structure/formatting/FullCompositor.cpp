//
// Created by Igor on 14.10.26..
//

#include "FullCompositor.h"
#include "../insertion/SimpleInserter.h"

namespace formatting {

    FullCompositor::FullCompositor(Composition *composition, LineWidthSource &widthSource):
    Compositor(composition),widthSource(widthSource){
        //this->inserter = new insertion::SimpleInserter();
    }


    void FullCompositor::compose(std::vector<document_structure::Glyph *>  flattened) {
        Column* newColumn = this->createNewStructure(flattened);
        this->setRootForComposition(newColumn);
    }

    bool FullCompositor::dependsOn(const EnvironmentSource &source) {
        //TODO change to not compare by referance because maybe this two can be coppies of the same source
        return &source == &this->widthSource;
    }





    Column *FullCompositor::createNewStructure(const std::vector<Glyph *> & flattened) {
        Column* col = new Column();
        int currInRow = 0;

        Row* row = nullptr;
        for(Glyph* g: flattened){

            if(currInRow == widthSource.width()){
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