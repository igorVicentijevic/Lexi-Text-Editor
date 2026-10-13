//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_COMPOSITOR_H
#define LEXI_COMPOSITOR_H

#include "../Glyph.h"

namespace formatting {

    class Composition;

    class Compositor {
        private:
           Composition* composition;

        public:
            Compositor(Composition* composition):composition(composition){}
            void onInsert(document_structure::Glyph* g);
    };

} // formatting

#endif //LEXI_COMPOSITOR_H
