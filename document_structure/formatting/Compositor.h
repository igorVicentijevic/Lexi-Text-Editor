//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_COMPOSITOR_H
#define LEXI_COMPOSITOR_H

#include "../Glyph.h"
#include "../Row.h"

namespace formatting {

    class Composition;

    class Compositor {
        private:
           Composition* composition;


        public:
            Compositor(Composition* composition):composition(composition){}
            virtual void onInsert(document_structure::Glyph* g)=0;
        protected:

            std::vector<document_structure::Row*> getRowsFromComposition();
            void setRowsForComposition( std::vector<document_structure::Row*> );
    };

} // formatting

#endif //LEXI_COMPOSITOR_H
