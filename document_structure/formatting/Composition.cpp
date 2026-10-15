//
// Created by Igor on 13.10.26..
//

#include "Composition.h"
#include "Compositor.h"

using namespace document_structure;

namespace formatting {

    Composition::~Composition() {
        delete layout;
        for(Glyph* g: glyphs){
            delete g;
        }
    }

    void Composition::Draw(Window * w) {
        if(layout)
            layout->Draw(w);
    }

    void Composition::Bounds(Rect &) {

    }

    bool Composition::Intersects(const Point &) {
        return false;
    }


    std::string Composition::getType() const {
        return "Composition";
    }

    void Composition::insertGlyph(Glyph * g, int insertionPoint) {
        if(insertionPoint < 0) insertionPoint = 0;
        if(insertionPoint > (int)glyphs.size()) insertionPoint = glyphs.size();

        glyphs.insert(glyphs.begin() + insertionPoint, g);
        g->setParent(this);
        recompose();
    }

    void Composition::setCompositor(Compositor *compositor) {
        this->compositor = compositor;
        recompose();
    }

    void Composition::recompose() {
        delete layout;
        layout = compositor ? compositor->compose(glyphs) : nullptr;
    }

    void Composition::environmentChanged(const EnvironmentSource &s) {
        if (compositor && compositor->dependsOn(s)) recompose();
    }
} // formatting
