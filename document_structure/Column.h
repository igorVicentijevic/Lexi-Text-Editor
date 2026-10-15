//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_COLUMN_H
#define LEXI_COLUMN_H

#include "CompositeGlyph.h"

namespace document_structure {

    //lays out children top to bottom, owns them (rows of the layout)
    class Column : public CompositeGlyph {
    protected:
        Point nextPosition(const Point& pos, Glyph* child) override;
    public:
        ~Column() override;

        std::string getType() const override;
    };
}


#endif //LEXI_COLUMN_H
