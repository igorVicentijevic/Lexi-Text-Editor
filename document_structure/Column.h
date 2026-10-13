//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_COLUMN_H
#define LEXI_COLUMN_H

#include "Glyph.h"
#include "Row.h"

#include <vector>

namespace document_structure {
    class Column : public document_structure::Glyph {

    private:
        std::vector<document_structure::Row*> children;
    public:
        void Draw(Window *window) override;

        void Bounds(Rect &rect) override;

        bool Intersects(const Point &point) override;

        void Insert(Glyph *glyph) override;
        void insertRow(Row* row);

        void Remove(Glyph *glyph) override;

        std::string getType() const override;

        std::vector<Row*> getChildren(){
            return children;
        }
    };
}


#endif //LEXI_COLUMN_H
