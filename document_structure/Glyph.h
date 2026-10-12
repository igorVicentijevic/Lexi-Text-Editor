//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_GLYPH_H
#define LEXI_GLYPH_H

#include "../appearance/Window.h"
#include "../appearance/Rect.h"
#include "../appearance/Point.h"

using namespace appearance;

namespace document_structure {
    class Glyph {
        public:
            //appearance
            virtual void Draw(Window* )=0;
            virtual void Bounds(Rect&)=0;

            //hit detection
            virtual bool Intersects(const Point&)=0;

            //structure
            virtual void Insert(Glyph* ,int)=0;
            virtual void Remove(Glyph*)=0;
            virtual Glyph* Child(int)=0;
            virtual Glyph* Parent()=0;

            virtual ~Glyph()=0;
    };

}


#endif //LEXI_GLYPH_H
