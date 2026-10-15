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

    void Composition::Bounds(Rect & r) {
        if(layout)
            layout->Bounds(r);
        else
            r = Rect(position.x, position.y, position.x, position.y);
    }

    Glyph* Composition::HitTest(const Point & p) {
        return layout ? layout->HitTest(p) : nullptr;
    }

    void Composition::setPosition(const Point & p) {
        Glyph::setPosition(p);
        if(layout)
            layout->setPosition(p);
    }

    Glyph* Composition::Child(int i) const {
        if(i < 0 || i >= (int)glyphs.size()) return nullptr;
        return glyphs[i];
    }

    int Composition::ChildCount() const {
        return glyphs.size();
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
        if(layout){
            layout->setParent(this);
            layout->setPosition(position);
        }
    }

    void Composition::environmentChanged(const EnvironmentSource &s) {
        if (compositor && compositor->dependsOn(s)) recompose();
    }
} // formatting
