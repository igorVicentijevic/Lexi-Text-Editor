//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_SIMPLECOMPOSITOR_H
#define LEXI_SIMPLECOMPOSITOR_H

#include "Compositor.h"

namespace formatting {

    class SimpleCompositor: public Compositor {
    public:
        explicit SimpleCompositor(Composition *composition);

    public:
        void onInsert(document_structure::Glyph *g) override;
    };

} // formatting

#endif //LEXI_SIMPLECOMPOSITOR_H
