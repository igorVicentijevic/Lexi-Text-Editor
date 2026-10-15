//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_INSERTIONPOINT_H
#define LEXI_INSERTIONPOINT_H

#include "../document_structure/formatting/Composition.h"

namespace editor {

    //position in the document where the next glyph is inserted, always inside the document
    class InsertionPoint {
        private:
            formatting::Composition& composition;
            int pos = 0;

        public:
            explicit InsertionPoint(formatting::Composition& composition): composition(composition){}

            int get() const { return pos; }
            //clamped to the document
            void set(int pos);
    };

} // editor

#endif //LEXI_INSERTIONPOINT_H
