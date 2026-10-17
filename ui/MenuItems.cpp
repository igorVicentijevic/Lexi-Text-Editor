//
// Created by Igor on 16.10.26..
//

#include "MenuItems.h"
#include "../document_structure/Character.h"
#include "../document_structure/Rectangle.h"
#include "../commands/CommandFactory.h"

#include <iostream>

using namespace std;
using namespace document_structure;

namespace ui {

    void EditorMenuItem::execute(commands::Command* c) {
        c->Execute();
        delete c;
    }

    void PutInsertionPointItem::select() {
        cout << "Input insertion point: "<<endl;
        int pos;
        cin >> pos;
        execute(editor.commands().moveInsertionPoint(pos));
    }

    void InsertCharacterItem::select() {
        cout << "Unesite karakter: ";
        char c;
        cin>> c;
        execute(editor.commands().insertGlyph(new Character(c)));
    }

    void InsertStringItem::select() {
        cout << "Input string: "<<endl;
        string s;
        cin >> s;
        execute(editor.commands().insertString(s));
    }

    void ChangeWidthItem::select() {
        cout << "Input new width: "<<endl;
        int newWidth;
        cin >> newWidth;
        if(newWidth < 1){
            cout << "Width must be at least 1!" << endl;
            return;
        }
        execute(editor.commands().changeWidth(newWidth));
    }

    void InsertRectangleItem::select() {
        cout << "Input width height: "<<endl;
        int width, height;
        cin >> width >> height;
        if(width < 1 || height < 1){
            cout << "Width and height must be at least 1!" << endl;
            return;
        }
        execute(editor.commands().insertGlyph(new Rectangle(width, height)));
    }

    void RemoveGlyphItem::select() {
        execute(editor.commands().removeGlyph());
    }

    void HitTestItem::select() {
        cout << "Input x y: "<<endl;
        int x, y;
        cin >> x >> y;
        Glyph* hit = editor.hitTest(Point(x, y));
        if(auto* c = dynamic_cast<Character*>(hit)){
            cout << "Hit character '" << c->getChar() << "' (id " << c->getId() << ")" << endl;
        }
        else if(hit) {
            cout << "Hit " << hit->getType() << " (id " << hit->getId() << ")" << endl;
        }
        else {
            cout << "Nothing at (" << x << "," << y << ")" << endl;
        }
    }

} // ui
