//
// Created by Igor on 13.10.26..
//

#include "Composition.h"
#include "Compositor.h"
#include "../Character.h"

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

    Glyph* Composition::removeGlyph(int pos) {
        if(pos < 0 || pos >= (int)glyphs.size()) return nullptr;

        Glyph* g = glyphs[pos];
        glyphs.erase(glyphs.begin() + pos);
        g->setParent(nullptr);
        recompose();
        return g;
    }

    void Composition::positionBounds(int pos, Rect& r) {
        int count = glyphs.size();
        if(pos < 0) pos = 0;
        if(pos > count) pos = count;

        if(pos < count){
            //in front of the glyph that is at the position
            glyphs[pos]->Bounds(r);
        }
        else if(count > 0){
            //after the last glyph
            Rect last;
            glyphs[count - 1]->Bounds(last);
            r = Rect(last.x1, last.y0, last.x1 + Character::WIDTH, last.y1);
        }
        else {
            //empty document - at its beginning, one line high
            r = Rect(position.x, position.y, position.x + Character::WIDTH, position.y + Character::HEIGHT);
        }
    }

    int Composition::verticalPosition(int pos, int direction) {
        int count = glyphs.size();
        if(count == 0 || direction == 0) return pos;

        Rect from;
        positionBounds(pos, from);

        //glyphs of one row have the same top, the target row is the nearest top above/below
        bool found = false;
        int targetY = 0;
        for(Glyph* g: glyphs){
            Rect r;
            g->Bounds(r);
            bool inDirection = direction < 0 ? r.y0 < from.y0 : r.y0 > from.y0;
            bool nearer = direction < 0 ? r.y0 > targetY : r.y0 < targetY;
            if(inDirection && (!found || nearer)){
                targetY = r.y0;
                found = true;
            }
        }
        if(!found) return pos;

        //in front of the first glyph of the target row that reaches past x
        int lastInRow = -1;
        for(int i = 0; i < count; i++){
            Rect r;
            glyphs[i]->Bounds(r);
            if(r.y0 != targetY) continue;
            if(r.x1 > from.x0) return i;
            lastInRow = i;
        }

        //the row is shorter: after its last glyph is the beginning of the next row,
        //so only for the last row the position can be after its last glyph
        return lastInRow == count - 1 ? count : lastInRow;
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
