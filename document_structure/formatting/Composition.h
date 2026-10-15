//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_COMPOSITION_H
#define LEXI_COMPOSITION_H

#include "../Glyph.h"
#include "environment_source/EnvironmentSource.h"

#include <vector>

namespace formatting {
    class Compositor;
    class Composition: public document_structure::Glyph {
        private:
            //logical structure - owned glyphs in document order
            std::vector<document_structure::Glyph*> glyphs;
            //physical structure - built by compositor, owned
            document_structure::Glyph* layout = nullptr;

            Compositor* compositor = nullptr;

            void recompose();

        public:
            ~Composition() override;

            void Draw(Window* ) override;

            //returns the opposite corners of the smallest rectangle that contains glyph
            void Bounds(Rect&) override;

            //hit detection
            bool Intersects(const Point&) override;
            void insertGlyph(document_structure::Glyph*,int);

            //compositor
            void setCompositor(Compositor* compositor);

            void environmentChanged(const EnvironmentSource& s);

            std::string getType() const override;
    };

} // formatting

#endif //LEXI_COMPOSITION_H
