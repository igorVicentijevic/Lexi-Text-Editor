//
// Created by Igor on 13.10.26..
//

#include "UI.h"
#include "../document_structure/Character.h"
#include "../document_structure/Rectangle.h"
#include "../appearance/ConsoleWindowImp.h"
#include "../commands/InsertGlyphCommand.h"
#include "../commands/MacroCommand.h"
#include "../commands/MoveInsertionPointCommand.h"
#include "../commands/ChangeWidthCommand.h"

#include <iostream>

using namespace std;

using namespace appearance;
using namespace document_structure;
using namespace commands;

ui::UI::UI(){
    this->editor = new editor::Editor(new Window(30,30, new ConsoleWindowImp()));

    //new option = new line here
    menu = {
        {"Put insertion point",                &UI::handlePutInsertionPoint},
        {"Write char on insertion point",      &UI::handleInsertCharacterOnInsertionPoint},
        {"Add string to insertion point",      &UI::handleAddStringToInsertionPoint},
        {"Quit",                               &UI::handleQuit},
        {"Change window width",                &UI::handleWidthChange},
        {"Hit test (x y)",                     &UI::handleHitTest},
        {"Add rectangle to insertion point",   &UI::handleAddRectangleToInsertionPoint},
    };
}

ui::UI::~UI() {
    delete editor;
}

void ui::UI::start() {
    while(true){
        editor->getComposition().Draw(&editor->getWindow());
        editor->getWindow().Flush();
        this->printConfig();
        this->printOptions();
        int option = this->readOption();
        this->callOption(option);

        if(quit) return;
    }
}

void ui::UI::execute(Command* c) {
    c->Execute();
    delete c;
}

void ui::UI::callOption(int option) {
    if(option < 1 || option > (int)menu.size()){
        cout << "Nevalidna opcija! Unesite ponovo!" << endl;
        return;
    }
    (this->*menu[option - 1].handler)();
}

int ui::UI::readOption() {
    int option;
    cin>>option;
    return option;
}

void ui::UI::printOptions() {
    cout<<"######################"<<endl;
    for(int i = 0; i < (int)menu.size(); i++){
        cout << i + 1 << ". " << menu[i].label << endl;
    }
    cout<<"######################"<<endl;
}

void ui::UI::printConfig() {
    cout <<"Insertion point location: "<<editor->getInsertionPoint()<<endl;
    cout <<"Width: "<<editor->getWindow().getWidth()<<endl;
}

void ui::UI::handlePutInsertionPoint() {
    cout << "Input insertion point: "<<endl;
    int pos;
    cin >> pos;
    execute(new MoveInsertionPointCommand(*editor, pos));
}

void ui::UI::handleInsertCharacterOnInsertionPoint() {
    cout << "Unesite karakter: ";
    char c;
    cin>> c;
    execute(new InsertGlyphCommand(*editor, new Character(c), editor->getInsertionPoint()));
}

void ui::UI::handleAddStringToInsertionPoint() {
    cout << "Input string: "<<endl;
    string s;
    cin >> s;

    MacroCommand* m = new MacroCommand();
    int pos = editor->getInsertionPoint();
    for(char c: s){
        m->Add(new InsertGlyphCommand(*editor, new Character(c), pos++));
    }
    execute(m);
}

void ui::UI::handleQuit() {
    quit = true;
}

void ui::UI::handleWidthChange() {
    cout << "Input new width: "<<endl;
    int newWidth;
    cin >> newWidth;
    if(newWidth < 1){
        cout << "Width must be at least 1!" << endl;
        return;
    }
    execute(new ChangeWidthCommand(*editor, newWidth));
}

void ui::UI::handleAddRectangleToInsertionPoint() {
    cout << "Input width height: "<<endl;
    int width, height;
    cin >> width >> height;
    if(width < 1 || height < 1){
        cout << "Width and height must be at least 1!" << endl;
        return;
    }
    execute(new InsertGlyphCommand(*editor, new Rectangle(width, height), editor->getInsertionPoint()));
}

void ui::UI::handleHitTest() {
    cout << "Input x y: "<<endl;
    int x, y;
    cin >> x >> y;
    Glyph* hit = editor->getComposition().HitTest(Point(x, y));
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
