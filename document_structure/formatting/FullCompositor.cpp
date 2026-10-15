//
// Created by Igor on 14.10.26..
//

#include "FullCompositor.h"
#include "../Row.h"

using namespace document_structure;

namespace formatting {

    FullCompositor::FullCompositor(LineWidthSource &widthSource): widthSource(widthSource){}

    bool FullCompositor::dependsOn(const EnvironmentSource &source) const {
        //TODO change to not compare by referance because maybe this two can be coppies of the same source
        return &source == &this->widthSource;
    }

    Glyph* FullCompositor::compose(const std::vector<Glyph *> & glyphs) {
        Column* col = new Column();
        int width = widthSource.width();
        if(width < 1) width = 1;

        int currInRow = 0;
        Row* row = nullptr;
        for(Glyph* g: glyphs){

            if(currInRow == width){
                col->Insert(row, col->ChildCount());
                currInRow = 0;
            }

            if(currInRow == 0){
                row = new Row();
            }

            row->Insert(g,currInRow);
            currInRow ++;
        }

        if(row!= nullptr)
            col->Insert(row, col->ChildCount());
        return col;
    }


} // formatting
