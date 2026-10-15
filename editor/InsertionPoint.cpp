//
// Created by Igor on 16.10.26..
//

#include "InsertionPoint.h"

namespace editor {

    void InsertionPoint::set(int pos) {
        if(pos < 0) pos = 0;
        if(pos > composition.ChildCount()) pos = composition.ChildCount();
        this->pos = pos;
    }

} // editor
