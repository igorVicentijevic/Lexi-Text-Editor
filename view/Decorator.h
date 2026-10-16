//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_DECORATOR_H
#define LEXI_DECORATOR_H

#include "VisualComponent.h"

namespace view {

    //Base for decorators: wraps one component and forwards everything to it.
    //Subclasses override only what they embellish. Owns the component.
    class Decorator: public VisualComponent {
        protected:
            VisualComponent* component;

        public:
            explicit Decorator(VisualComponent* component): component(component){}
            ~Decorator() override;

            Decorator(const Decorator&) = delete;
            Decorator& operator=(const Decorator&) = delete;

            void Draw(appearance::Window*) override;
            void Bounds(appearance::Rect&) override;
            void setPosition(const appearance::Point&) override;
            document_structure::Glyph* HitTest(const appearance::Point&) override;
    };

} // view

#endif //LEXI_DECORATOR_H
