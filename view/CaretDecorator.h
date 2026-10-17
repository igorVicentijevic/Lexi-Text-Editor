//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_CARETDECORATOR_H
#define LEXI_CARETDECORATOR_H

#include "Decorator.h"

namespace editor {
    class InsertionPoint;
    class PositionLocator;
}

namespace view {

    //draws the text cursor in front of the glyph at the insertion point
    class CaretDecorator: public Decorator {
        private:
            const editor::PositionLocator& locator;
            editor::InsertionPoint& insertionPoint;

            //where the caret is: x of its cell and its height
            void caretBounds(appearance::Rect& r);

        public:
            CaretDecorator(VisualComponent* component, const editor::PositionLocator& locator,
                           editor::InsertionPoint& insertionPoint):
                Decorator(component), locator(locator), insertionPoint(insertionPoint){}

            void Draw(appearance::Window*) override;
            //caret can be after the last glyph, so it is included in the bounds
            void Bounds(appearance::Rect&) override;
    };

} // view

#endif //LEXI_CARETDECORATOR_H
