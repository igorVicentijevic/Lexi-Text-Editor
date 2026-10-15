#include <iostream>

#include "document_structure/Character.h"
#include "appearance/Window.h"
#include "document_structure/Row.h"
#include "document_structure/formatting/Composition.h"


#include "ui/UI.h"

using namespace document_structure;
using namespace appearance;
using namespace formatting;

using namespace ui;


//void test(){
//    Window w(9,20);
//    Composition composition;
//    formatting::Compositor* compositor;
//
//    insertion::Inserter* inserter = new insertion::SimpleInserter(&composition);
//
//
//    formatting::SimpleCompositor* simpleCompositor = new formatting::SimpleCompositor(&composition);
//    simpleCompositor->setWidth(w.getWidth());
//
//    compositor = simpleCompositor;
//    compositor->setInserter(inserter);
//
//    composition.setCompositor(compositor);
//
//    int cnt = 0;
//    for(char c: "Testiranje da li sve lepo radi nadam se da ima 20 karaktera bar!"){
//        composition.insertGlyph(new Character(c),cnt++);
//    }
//
//    composition.insertGlyph(new Character('T'),6);
//    composition.insertGlyph(new Character('A'),6);
//    composition.insertGlyph(new Character('%'),25);
//
//
//    composition.Draw(&w);
//
//}
//
void testWithUI(){
    UI ui;
    ui.start();
}

int main() {
//    Window w(14,20);
//
//
////    Row r;
////
////    r.Insert(&t);
////    r.Insert(&e);
////    r.Insert(&s);
////    r.Insert(&t);
////
////    r.Draw(&w);
//    formatting::Composition composition;
//    formatting::Compositor* compositor;
//
//    formatting::SimpleCompositor* simpleCompositor = new formatting::SimpleCompositor(&composition);
//    simpleCompositor->setWidth(w.getWidth());
//
//    compositor = simpleCompositor;
//
//
//    composition.setCompositor(compositor);
//    for(char c: "Testiranje da li sve lepo radi nadam se da ima 20 karaktera bar!"){
//        composition.Insert(new Character(c));
//    }
//
//    composition.Draw(&w);

    testWithUI();
    return 0;
}
