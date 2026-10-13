//
// Created by Igor on 13.10.26..
//

#include "Inserter.h"
#include "../formatting/Composition.h"

namespace insertion {
    Column *Inserter::getColumn() {
        return this->composition->column;
    }
} // insertion