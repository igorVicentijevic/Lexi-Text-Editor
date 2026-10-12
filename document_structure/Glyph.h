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
            virtual void Draw(Window* );
            virtual void Bounds(Rect&);

            //hit detection
            virtual bool Intersects(const Point&);

            //structure
            virtual void Insert(Glyph* ,int);
            virtual void Remove(Glyph*);
            virtual Glyph* Child(int);
            virtual Glyph* Parent();

            virtual ~Glyph()=0;
    };

}


#endif //LEXI_GLYPH_H
