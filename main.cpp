#include <iostream>

#include "document_structure/Character.h"
#include "appearance/Window.h"
#include "document_structure/Row.h"
#include "document_structure/formatting/Composition.h"
#include "document_structure/formatting/SimpleCompositor.h"

using namespace document_structure;
using namespace appearance;


int main() {
    Window w(7,20);

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
    formatting::Compositor* compositor;

    formatting::SimpleCompositor* simpleCompositor = new formatting::SimpleCompositor(&composition);
    simpleCompositor->setWidth(w.getWidth());

    compositor = simpleCompositor;


    composition.setCompositor(compositor);
    for(char c: "Testiranje da li sve lepo radi nadam se da ima 20 karaktera bar!"){
        composition.Insert(new Character(c));
    }

    composition.Draw(&w);
    return 0;
}
