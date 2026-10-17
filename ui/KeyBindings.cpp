//
// Created by Igor on 17.10.26..
//

#include "KeyBindings.h"
#include "../document_structure/Character.h"
#include "../commands/CommandFactory.h"

#include <iostream>
#include <limits>

using namespace std;

namespace ui {

    void TypeCharacterBinding::pressed(const Key& key) {
        editor.execute(editor.commands().insertGlyph(new document_structure::Character(key.c)));
    }

    void RemoveGlyphBinding::pressed(const Key&) {
        editor.execute(editor.commands().removeGlyph());
    }

    void MoveInsertionPointBinding::pressed(const Key&) {
        editor.execute(editor.commands().moveInsertionPoint(editor.getInsertionPoint() + delta));
    }

    void MoveInsertionPointVerticallyBinding::pressed(const Key&) {
        editor.execute(editor.commands().moveInsertionPointVertically(direction));
    }

    void OpenMenuBinding::pressed(const Key&) {
        RawTerminal::Pause pause(terminal);

        menu.show();
        menu.choose();

        //the next redraw clears the screen, so messages of the item are read first
        cout << "Pritisnite Enter za nastavak..." << flush;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

} // ui
