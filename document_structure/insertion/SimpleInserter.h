//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_SIMPLEINSERTER_H
#define LEXI_SIMPLEINSERTER_H

#include "Inserter.h"
namespace insertion {

    class SimpleInserter: public Inserter {
    private:
        void insertIntoVector(Glyph*, int , std::vector<Glyph*>);
    public:
        explicit SimpleInserter(formatting::Composition *composition);

        InsertionData insertGlyph(Glyph *glyph, int i) override;
    };

} // insertion

#endif //LEXI_SIMPLEINSERTER_H
