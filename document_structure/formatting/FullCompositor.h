//
// Created by Igor on 14.10.26..
//

#ifndef LEXI_FULLCOMPOSITOR_H
#define LEXI_FULLCOMPOSITOR_H

#include "Compositor.h"
#include "../Glyph.h"
#include "../Row.h"
#include "../insertion/Inserter.h"

#include <vector>


namespace formatting {

    class FullCompositor: public Compositor {
            private:

                int width;
            private:
                Column* createNewStructure(const std::vector<Glyph*>&);
                std::vector<Glyph*> flattenAndDeleteStructure(Column* col);
            public:
                explicit FullCompositor(Composition *composition);
                void onInsert(document_structure::Glyph *g,int) override;
                void setWidth(int width){
                    this->width = width;
                }


    };

} // formatting

#endif //LEXI_FULLCOMPOSITOR_H
