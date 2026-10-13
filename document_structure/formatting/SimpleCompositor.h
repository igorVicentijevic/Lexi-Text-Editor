//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_SIMPLECOMPOSITOR_H
#define LEXI_SIMPLECOMPOSITOR_H

#include "Compositor.h"
#include "../Glyph.h"
#include "../Row.h"

#include <vector>

namespace formatting {

    class SimpleCompositor: public Compositor {
    private:
        std::vector<document_structure::Glyph*> flattened;
        int width;
    private:
        document_structure::Row* splitRow(document_structure::Row* rowToSplit, std::vector<document_structure::Row*>& currRows);

    public:
        explicit SimpleCompositor(Composition *composition);
        void onInsert(document_structure::Glyph *g,int) override;
        void setWidth(int width){
            this->width = width;
        }


    };

} // formatting

#endif //LEXI_SIMPLECOMPOSITOR_H
