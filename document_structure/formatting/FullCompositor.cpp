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

        int rowWidth = 0;
        Row* row = nullptr;
        for(Glyph* g: glyphs){
            Rect r;
            g->Bounds(r);

            //glyph doesn't fit - start a new row (a glyph wider than the line gets a row of its own)
            if(row != nullptr && rowWidth + r.width() > width){
                col->Insert(row, col->ChildCount());
                row = nullptr;
            }

            if(row == nullptr){
                row = new Row();
                rowWidth = 0;
            }

            row->Insert(g, row->ChildCount());
            rowWidth += r.width();
        }

        if(row!= nullptr)
            col->Insert(row, col->ChildCount());
        return col;
    }


} // formatting
