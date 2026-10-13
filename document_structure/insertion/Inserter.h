//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_INSERTER_H
#define LEXI_INSERTER_H

#include "../Glyph.h"
#include "../Row.h"
#include "../Column.h"

namespace formatting { class Composition; }

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

        Column* getColumn();
    public:

        Inserter(formatting::Composition* composition): composition(composition){}
        virtual InsertionData insertGlyph(Glyph*, int) = 0;


    };

} // insertion

#endif //LEXI_INSERTER_H
