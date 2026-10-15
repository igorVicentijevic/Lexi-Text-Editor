//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_COMPOSITOR_H
#define LEXI_COMPOSITOR_H

#include "../Glyph.h"

#include "environment_source/EnvironmentSource.h"

#include <vector>


namespace formatting {

    class Compositor {
        public:
            virtual ~Compositor() = default;

            //builds physical structure (rows and columns) from logical content
            //returned layout is owned by the caller, glyphs are not
            virtual document_structure::Glyph* compose(const std::vector<document_structure::Glyph*>& glyphs)=0;

            //called from composition to know if the recomposition is needed
            virtual bool dependsOn(const EnvironmentSource&) const {return false;}
    };

} // formatting

#endif //LEXI_COMPOSITOR_H
