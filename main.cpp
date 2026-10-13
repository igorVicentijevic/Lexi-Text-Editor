#include <iostream>

#include "document_structure/Character.h"
#include "appearance/Window.h"
#include "document_structure/Row.h"
#include "document_structure/formatting/Composition.h"
#include "document_structure/formatting/SimpleCompositor.h"

using namespace document_structure;
using namespace appearance;


int main() {
    Window w(20,20);

    Character t('t');
    Character e('e');
    Character s('s');

//    Row r;
//
//    r.Insert(&t);
//    r.Insert(&e);
//    r.Insert(&s);
//    r.Insert(&t);
//
//    r.Draw(&w);
    formatting::Composition composition;
    formatting::Compositor* compositor = new formatting::SimpleCompositor(&composition);
    composition.setCompositor(compositor);

    composition.Insert(&t);
    composition.Insert(&e);
    composition.Insert(&s);
    composition.Insert(&t);

    composition.Draw(&w);
    return 0;
}
