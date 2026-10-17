//
// Created by Igor on 17.10.26..
//

#include "PositionLocator.h"
#include "../document_structure/Character.h"
#include "../document_structure/formatting/Composition.h"

using namespace appearance;
using document_structure::Character;

namespace editor {

    void PositionLocator::Bounds(int pos, Rect& r) const {
        int count = composition.ChildCount();
        if(pos < 0) pos = 0;
        if(pos > count) pos = count;

        if(pos < count){
            //in front of the glyph that is at the position
            composition.Child(pos)->Bounds(r);
        }
        else if(count > 0){
            //after the last glyph - the cell where the next character comes
            Rect last;
            composition.Child(count - 1)->Bounds(last);
            r = Rect(last.x1, last.y0, last.x1 + Character::WIDTH, last.y1);
        }
        else {
            //empty document - at its beginning, one line high
            Rect doc;
            composition.Bounds(doc);
            r = Rect(doc.x0, doc.y0, doc.x0 + Character::WIDTH, doc.y0 + Character::HEIGHT);
        }
    }

    int PositionLocator::vertical(int pos, int direction) const {
        int count = composition.ChildCount();
        if(count == 0 || direction == 0) return pos;

        Rect from;
        Bounds(pos, from);

        //glyphs of one row have the same top, the target row is the nearest top above/below
        bool found = false;
        int targetY = 0;
        for(int i = 0; i < count; i++){
            Rect r;
            composition.Child(i)->Bounds(r);
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
            composition.Child(i)->Bounds(r);
            if(r.y0 != targetY) continue;
            if(r.x1 > from.x0) return i;
            lastInRow = i;
        }

        //the row is shorter: after its last glyph is the beginning of the next row,
        //so only for the last row the position can be after its last glyph
        return lastInRow == count - 1 ? count : lastInRow;
    }

} // editor
