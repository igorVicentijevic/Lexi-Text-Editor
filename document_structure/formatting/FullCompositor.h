//
// Created by Igor on 14.10.26..
//

#ifndef LEXI_FULLCOMPOSITOR_H
#define LEXI_FULLCOMPOSITOR_H

#include "Compositor.h"
#include "../Glyph.h"
#include "../Row.h"
#include "../insertion/Inserter.h"

#include "environment_source/LineWidthSource.h"
#include <vector>


namespace formatting {

    class FullCompositor: public Compositor {
            private:
                LineWidthSource& widthSource;

            private:
                Column *createNewStructure(const std::vector<Glyph *> & flattened);
            public:
                explicit FullCompositor(Composition *composition,LineWidthSource& widthSource );
                void compose(std::vector<document_structure::Glyph *> vector) override;

                bool dependsOn(const EnvironmentSource &source) override;

    };

} // formatting

#endif //LEXI_FULLCOMPOSITOR_H
