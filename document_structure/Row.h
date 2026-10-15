//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_ROW_H
#define LEXI_ROW_H

#include "CompositeGlyph.h"

namespace document_structure {

    //lays out children left to right
    class Row: public CompositeGlyph{
        protected:
            Point nextPosition(const Point& pos, Glyph* child) override;
        public:
            //print
            std::string getType() const override;
    };

} // document_structure

#endif //LEXI_ROW_H
