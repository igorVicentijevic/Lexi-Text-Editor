//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_COMPOSITOR_H
#define LEXI_COMPOSITOR_H

#include "../Glyph.h"
#include "../Row.h"
#include "../Column.h"

namespace insertion  { class Inserter; }


namespace formatting {

    class Composition;

    class Compositor {
        protected:
           Composition* composition;
           insertion::Inserter* inserter;


        public:
            Compositor(Composition* composition):composition(composition){}
            virtual void onInsert(document_structure::Glyph* g,int)=0;

            void setInserter(insertion::Inserter* inserter){
                this->inserter = inserter;
            }
        protected:

        document_structure::Column* getColFromComposition();

        void setColForComposition(document_structure::Column* col);
    };

} // formatting

#endif //LEXI_COMPOSITOR_H
