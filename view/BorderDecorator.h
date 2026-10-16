//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_BORDERDECORATOR_H
#define LEXI_BORDERDECORATOR_H

#include "Decorator.h"

namespace view {

    //draws vertical lines left and right of the component
    class BorderDecorator: public Decorator {
        private:
            appearance::Point position;

            void DrawBorder(appearance::Window*);

        public:
            explicit BorderDecorator(VisualComponent* component): Decorator(component){}

            void Draw(appearance::Window*) override;
            //bounds of the component widened by the lines on both sides, at least one line high
            void Bounds(appearance::Rect&) override;
            //component is moved right to make room for the left line
            void setPosition(const appearance::Point&) override;
    };

} // view

#endif //LEXI_BORDERDECORATOR_H
