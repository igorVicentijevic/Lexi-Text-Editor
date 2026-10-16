//
// Created by Igor on 16.10.26..
//

#include "Decorator.h"

namespace view {

    Decorator::~Decorator() {
        delete component;
    }

    void Decorator::Draw(appearance::Window* w) {
        component->Draw(w);
    }

    void Decorator::Bounds(appearance::Rect& r) {
        component->Bounds(r);
    }

    void Decorator::setPosition(const appearance::Point& p) {
        component->setPosition(p);
    }

    document_structure::Glyph* Decorator::HitTest(const appearance::Point& p) {
        return component->HitTest(p);
    }

} // view
