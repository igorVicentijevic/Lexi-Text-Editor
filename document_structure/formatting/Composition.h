//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_COMPOSITION_H
#define LEXI_COMPOSITION_H

#include "../Glyph.h"
#include "../Row.h"

#include <vector>

namespace formatting {

    class Composition: public document_structure::Glyph {
        private:
            std::vector<document_structure::Row*> childrenRows;

        public:
            void Draw(Window* ) override;

            //returns the opposite corners of the smallest rectangle that contains glyph
            void Bounds(Rect&) override;

            //hit detection
            bool Intersects(const Point&) override;

            //structure
            void Insert(Glyph*) override;
            void Remove(Glyph*) override;

            std::string getType() const override;
    };

} // formatting

#endif //LEXI_COMPOSITION_H
