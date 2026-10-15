//
// Created by Igor on 15.10.26..
//

#ifndef LEXI_COMPOSITEGLYPH_H
#define LEXI_COMPOSITEGLYPH_H

#include "Glyph.h"

#include <vector>

namespace document_structure {

    //Glyph that contains other glyphs and lays them out one after another.
    //Subclasses only decide where the next child starts (Template Method).
    //Children are not owned.
    class CompositeGlyph: public Glyph {
        protected:
            std::vector<Glyph*> children;

            //position of the child after `child`, if `child` starts at `pos`
            virtual Point nextPosition(const Point& pos, Glyph* child) = 0;

        public:
            void Draw(Window*) override;
            void Bounds(Rect&) override;
            Glyph* HitTest(const Point&) override;

            //places itself and lays out all children
            void setPosition(const Point& p) override;

            //structure - positions are updated on the next setPosition
            void Insert(Glyph*, int pos);
            void Remove(Glyph*);
            Glyph* Child(int) const override;
            int ChildCount() const override;
    };

} // document_structure

#endif //LEXI_COMPOSITEGLYPH_H
