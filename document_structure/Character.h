//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_CHARACTER_H
#define LEXI_CHARACTER_H

#include "Glyph.h"

namespace document_structure {

    class Character: public Glyph {
        private:
            char c;
        public:
            Character(char c);
            void Draw(Window* ) override;
            //returns the opposite corners of the smallest rectangle that contains glyph
            void Bounds(Rect&) override;

            //hit detection
            bool Intersects(const Point&) override;




            //print

            std::string getType() const override;
    };

} // document_structure

#endif //LEXI_CHARACTER_H
