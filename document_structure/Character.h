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
            //character is the smallest unit of the document, other sizes are expressed in characters
            static constexpr int WIDTH = 1;
            static constexpr int HEIGHT = 1;

            Character(char c);
            void Draw(Window*) override;
            //returns the opposite corners of the smallest rectangle that contains glyph
            void Bounds(Rect&) override;

            char getChar() const { return c; }

            //print

            std::string getType() const override;
    };

} // document_structure

#endif //LEXI_CHARACTER_H
