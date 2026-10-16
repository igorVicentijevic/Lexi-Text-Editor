//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_FRAMEDECORATOR_H
#define LEXI_FRAMEDECORATOR_H

#include "Decorator.h"

namespace view {

    //draws double lines on every side of the component:
    //"||" left and right, two rows of '_' above and below (they also cover the corners)
    class FrameDecorator: public Decorator {
        private:
            appearance::Point position;

            void DrawFrame(appearance::Window*);

        public:
            explicit FrameDecorator(VisualComponent* component): Decorator(component){}

            void Draw(appearance::Window*) override;
            //bounds of the component widened by the frame on every side, content at least one line high
            void Bounds(appearance::Rect&) override;
            //component is moved right and down to make room for the left and top lines
            void setPosition(const appearance::Point&) override;
    };

} // view

#endif //LEXI_FRAMEDECORATOR_H
