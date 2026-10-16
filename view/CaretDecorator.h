//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_CARETDECORATOR_H
#define LEXI_CARETDECORATOR_H

#include "Decorator.h"

namespace formatting { class Composition; }
namespace editor { class InsertionPoint; }

namespace view {

    //draws the text cursor in front of the glyph at the insertion point
    class CaretDecorator: public Decorator {
        private:
            formatting::Composition& composition;
            editor::InsertionPoint& insertionPoint;

            //where the caret is: x of its cell and its height
            void caretBounds(appearance::Rect& r);

        public:
            CaretDecorator(VisualComponent* component, formatting::Composition& composition,
                           editor::InsertionPoint& insertionPoint):
                Decorator(component), composition(composition), insertionPoint(insertionPoint){}

            void Draw(appearance::Window*) override;
            //caret can be after the last glyph, so it is included in the bounds
            void Bounds(appearance::Rect&) override;
    };

} // view

#endif //LEXI_CARETDECORATOR_H
