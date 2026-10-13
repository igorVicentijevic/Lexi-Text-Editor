//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_GLYPH_H
#define LEXI_GLYPH_H

#include "../appearance/Window.h"
#include "../appearance/Rect.h"
#include "../appearance/Point.h"

#include <ostream>
#include <string>

using namespace appearance;


namespace document_structure {
    class Glyph {
        private:
            int id;
            static int ID;
            Glyph* parent;


        public:
            Glyph();
            //appearance
            virtual void Draw(Window* )=0;
            //returns the opposite corners of the smallest rectangle that contains glyph
            virtual void Bounds(Rect&)=0;

            //hit detection
            virtual bool Intersects(const Point&)=0;

            //structure
            virtual void Insert(Glyph*)=0;
            virtual void Remove(Glyph*)=0;
            Glyph* getParent();
            void setParent(Glyph* g);

            //print

            virtual std::string getType() const = 0;
            int getId() const;

            friend std::ostream& operator<<(std::ostream& os, const Glyph& g);


    };

}


#endif //LEXI_GLYPH_H
