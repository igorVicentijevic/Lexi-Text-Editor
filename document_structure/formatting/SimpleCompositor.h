//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_SIMPLECOMPOSITOR_H
#define LEXI_SIMPLECOMPOSITOR_H

#include "Compositor.h"
#include "../Glyph.h"

#include <vector>

namespace formatting {

    class SimpleCompositor: public Compositor {
    private:
        std::vector<document_structure::Glyph*> flattened;
    private:

    public:
        explicit SimpleCompositor(Composition *composition);
        void onInsert(document_structure::Glyph *g) override;
    };

} // formatting

#endif //LEXI_SIMPLECOMPOSITOR_H
