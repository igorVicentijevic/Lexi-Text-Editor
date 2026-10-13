//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_INSERTER_H
#define LEXI_INSERTER_H

#include "../Glyph.h"
#include "../formatting/Composition.h"

using namespace document_structure;
namespace insertion {

    class Inserter {
    public:
        struct InsertionData{
            Row* row;
            int pos;
        };

    protected:
        formatting::Composition* composition;
    public:
        Inserter(formatting::Composition* composition): composition(composition){}
        virtual InsertionData insertGlyph(Glyph*, int) = 0;


    };

} // insertion

#endif //LEXI_INSERTER_H
