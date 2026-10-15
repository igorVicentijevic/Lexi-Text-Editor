//
// Created by Igor on 15.10.26..
//

#include "CompositeGlyph.h"

#include <algorithm>

namespace document_structure {

    void CompositeGlyph::Draw(Window* w) {
        for(Glyph* child: children){
            child->Draw(w);
        }
    }

    void CompositeGlyph::Bounds(Rect& r) {
        r = Rect(position.x, position.y, position.x, position.y);
        for(Glyph* child: children){
            Rect childRect;
            child->Bounds(childRect);
            r.x0 = std::min(r.x0, childRect.x0);
            r.y0 = std::min(r.y0, childRect.y0);
            r.x1 = std::max(r.x1, childRect.x1);
            r.y1 = std::max(r.y1, childRect.y1);
        }
    }

    Glyph* CompositeGlyph::HitTest(const Point& p) {
        for(Glyph* child: children){
            Glyph* hit = child->HitTest(p);
            if(hit) return hit;
        }
        return nullptr;
    }

    void CompositeGlyph::setPosition(const Point& p) {
        Glyph::setPosition(p);
        Point pos = p;
        for(Glyph* child: children){
            child->setPosition(pos);
            pos = nextPosition(pos, child);
        }
    }

    void CompositeGlyph::Insert(Glyph* g, int pos) {
        if(pos < 0) pos = 0;
        if(pos > (int)children.size()) pos = children.size();
        children.insert(children.begin() + pos, g);
        g->setParent(this);
    }

    void CompositeGlyph::Remove(Glyph* g) {
        auto it = std::find(children.begin(), children.end(), g);
        if(it == children.end()) return;
        children.erase(it);
        g->setParent(nullptr);
    }

    Glyph* CompositeGlyph::Child(int i) const {
        if(i < 0 || i >= (int)children.size()) return nullptr;
        return children[i];
    }

    int CompositeGlyph::ChildCount() const {
        return children.size();
    }

} // document_structure
