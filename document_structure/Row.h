//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_ROW_H
#define LEXI_ROW_H

#include "Glyph.h"

#include <vector>

namespace document_structure {

    class Row: public Glyph{
        private:
            std::vector<Glyph*> children;
        public:
            //appearance
            void Draw(Window* ) override;
            //returns the opposite corners of the smallest rectangle that contains glyph
            void Bounds(Rect&) override;

            //hit detection
            bool Intersects(const Point&) override;

            //structure
            void Insert(Glyph*) override;
            void Remove(Glyph*) override;

            void insertGlyph(Glyph*, int pos);

            //print
            std::string getType() const override;

            int getSize(){
                return this->children.size();
            }

            std::vector<Glyph*>& getChildren(){
                return children;
            }
    };

} // document_structure

#endif //LEXI_ROW_H
