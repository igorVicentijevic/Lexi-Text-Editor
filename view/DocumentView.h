//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_DOCUMENTVIEW_H
#define LEXI_DOCUMENTVIEW_H

#include "VisualComponent.h"

namespace formatting { class Composition; }

namespace view {

    //shows the document - forwards everything to the composition
    class DocumentView: public VisualComponent {
        private:
            formatting::Composition& composition;

        public:
            explicit DocumentView(formatting::Composition& composition): composition(composition){}

            void Draw(appearance::Window*) override;
            void Bounds(appearance::Rect&) override;
            void setPosition(const appearance::Point&) override;
            document_structure::Glyph* HitTest(const appearance::Point&) override;
    };

} // view

#endif //LEXI_DOCUMENTVIEW_H
