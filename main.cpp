#include <iostream>

#include "document_structure/Character.h"
#include "appearance/Window.h"
#include "document_structure/Row.h"

using namespace document_structure;
using namespace appearance;


int main() {
    Window w;

    Character t('t');
    Character e('e');
    Character s('s');

    Row r;

    r.Insert(&t);
    r.Insert(&e);
    r.Insert(&s);
    r.Insert(&t);

    r.Draw(&w);
    return 0;
}
