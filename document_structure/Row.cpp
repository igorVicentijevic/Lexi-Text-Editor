//
// Created by Igor on 13.10.26..
//

#include "Row.h"

namespace document_structure {


    //appearance
    void Row::Draw(Window* w){
        for(Glyph* child: children){
            child->Draw(w);
        }
    }
    //returns the opposite corners of the smallest rectangle that contains glyph
    void Row::Bounds(Rect& r){
        //TODO
    }

    //hit detection
    bool Row::Intersects(const Point& p){
        //TODO
        return false;
    }

    //structure
    void Row::Insert(Glyph* g){
        children.push_back(g);
        g->setParent(this);
    }

    void Row::Remove(Glyph* g){
        int i = std::find(children.begin(), children.end(),g)-children.begin();
        children.erase(children.begin()+i);
        g->setParent(nullptr);
    }


    //print
    std::string Row::getType() const {
        return "Row";
    }
} // document_structure