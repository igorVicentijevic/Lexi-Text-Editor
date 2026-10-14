//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_COMPOSITION_H
#define LEXI_COMPOSITION_H

#include "../Glyph.h"
#include "../Row.h"

#include "../Column.h"
#include "../insertion/Inserter.h"
#include "../insertion/SimpleInserter.h"
#include "environment_source/EnvironmentSource.h"


#include <vector>

using namespace document_structure;

namespace formatting {
    class Compositor;
    class Composition: public document_structure::Glyph {
        private:
            Glyph* root = nullptr;
            Compositor* compositor = nullptr;
            insertion::Inserter* inserter = new insertion::SimpleInserter(this);

            void recompose();
            std::vector<Glyph*> flattendAndDeleteStructure();

        public:

            void Draw(Window* ) override;

            //returns the opposite corners of the smallest rectangle that contains glyph
            void Bounds(Rect&) override;

            //hit detection
            bool Intersects(const Point&) override;

            //structure
            void Insert(Glyph*) override;
            void Remove(Glyph*) override;

            void insertGlyph(Glyph*,int);

            //compositor
            void setCompositor(Compositor* compositor){
                this->compositor = compositor;
            }

            void environmentChanged(const EnvironmentSource& s);

            friend class Compositor;
            friend class insertion::Inserter;

            std::string getType() const override;
    };

} // formatting

#endif //LEXI_COMPOSITION_H
