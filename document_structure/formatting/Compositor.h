//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_COMPOSITOR_H
#define LEXI_COMPOSITOR_H

#include "../Glyph.h"
#include "../Row.h"
#include "../Column.h"

#include "environment_source/EnvironmentSource.h"

#include <vector>

namespace insertion  { class Inserter; }


namespace formatting {

    class Composition;

    class Compositor {
        protected:
           Composition* composition;
        public:
            Compositor(Composition* composition):composition(composition){}

            virtual void compose(std::vector<document_structure::Glyph*>)=0;

            //called from composition to know if the recomposition is needed
            virtual bool dependsOn(const EnvironmentSource&){return false;}

        protected:

        document_structure::Glyph* getRootFromComposition();
        void setRootForComposition(document_structure::Glyph* root);
    };

} // formatting

#endif //LEXI_COMPOSITOR_H
