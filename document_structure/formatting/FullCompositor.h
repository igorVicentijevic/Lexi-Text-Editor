//
// Created by Igor on 14.10.26..
//

#ifndef LEXI_FULLCOMPOSITOR_H
#define LEXI_FULLCOMPOSITOR_H

#include "Compositor.h"
#include "../Glyph.h"
#include "../Column.h"

#include "environment_source/LineWidthSource.h"
#include <vector>


namespace formatting {

    class FullCompositor: public Compositor {
            private:
                LineWidthSource& widthSource;

            public:
                explicit FullCompositor(LineWidthSource& widthSource);
                document_structure::Glyph* compose(const std::vector<document_structure::Glyph *>& glyphs) override;

                bool dependsOn(const EnvironmentSource &source) const override;

    };

} // formatting

#endif //LEXI_FULLCOMPOSITOR_H
