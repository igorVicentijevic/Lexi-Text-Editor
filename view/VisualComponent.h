//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_VISUALCOMPONENT_H
#define LEXI_VISUALCOMPONENT_H

#include "../appearance/Window.h"
#include "../appearance/Rect.h"
#include "../appearance/Point.h"

namespace document_structure { class Glyph; }

namespace view {

    //Anything drawn on the window around and including the document.
    //Unlike glyphs it is not part of the document content.
    class VisualComponent {
        public:
            virtual ~VisualComponent() = default;

            virtual void Draw(appearance::Window*) = 0;
            //returns the opposite corners of the smallest rectangle that contains the component
            virtual void Bounds(appearance::Rect&) = 0;
            //top left corner
            virtual void setPosition(const appearance::Point&) = 0;

            //glyph of the document at the point, nullptr if there is none
            virtual document_structure::Glyph* HitTest(const appearance::Point&) = 0;
    };

} // view

#endif //LEXI_VISUALCOMPONENT_H
