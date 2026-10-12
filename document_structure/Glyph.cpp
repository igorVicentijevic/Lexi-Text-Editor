//
// Created by Igor on 13.10.26..
//

#include "Glyph.h"
using namespace document_structure;

std::ostream& operator<<(std::ostream& os, const Glyph& g){
     os << g.getType();
    return os;
}