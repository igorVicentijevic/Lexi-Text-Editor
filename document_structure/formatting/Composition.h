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

            void Draw(appearance::Window* ) override;

            //returns the opposite corners of the smallest rectangle that contains glyph
            void Bounds(appearance::Rect&) override;

            //hit detection
            document_structure::Glyph* HitTest(const appearance::Point&) override;

            //places the layout at the given point
            void setPosition(const appearance::Point& p) override;

            //logical structure
            document_structure::Glyph* Child(int) const override;
            int ChildCount() const override;

            void insertGlyph(document_structure::Glyph*,int);
            //takes the glyph out of the document and gives its ownership to the caller,
            //nullptr if there is no glyph at the position
            document_structure::Glyph* removeGlyph(int);

            //positions are between glyphs: 0 is in front of the first, ChildCount() after the last

            //where the position is on the screen: bounds of the glyph after it,
            //one character cell after the last glyph, or at the beginning of an empty document
            void positionBounds(int pos, appearance::Rect& r);
            //position in the row above (direction < 0) or below (direction > 0) at the same x;
            //the same position if there is no such row
            int verticalPosition(int pos, int direction);

            //compositor
            void setCompositor(Compositor* compositor);

            void environmentChanged(const EnvironmentSource& s);

            std::string getType() const override;
    };

} // formatting

#endif //LEXI_COMPOSITION_H
