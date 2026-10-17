//
// Created by Igor on 17.10.26..
//

#ifndef LEXI_POSITIONLOCATOR_H
#define LEXI_POSITIONLOCATOR_H

#include "../appearance/Rect.h"

namespace formatting { class Composition; }

namespace editor {

    //Translates between positions in the document and places on the screen.
    //Positions are between glyphs: 0 is in front of the first, ChildCount() after the last.
    class PositionLocator {
        private:
            formatting::Composition& composition;

        public:
            explicit PositionLocator(formatting::Composition& composition): composition(composition){}

            //where the position is on the screen: bounds of the glyph after it,
            //one character cell after the last glyph, or at the beginning of an empty document
            void Bounds(int pos, appearance::Rect& r) const;
            //position in the row above (direction < 0) or below (direction > 0) at the same x;
            //the same position if there is no such row
            int vertical(int pos, int direction) const;
    };

} // editor

#endif //LEXI_POSITIONLOCATOR_H
