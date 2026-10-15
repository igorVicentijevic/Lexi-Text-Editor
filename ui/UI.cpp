//
// Created by Igor on 13.10.26..
//

#include "UI.h"
#include "../document_structure/Character.h"
#include "../document_structure/formatting/FullCompositor.h"
#include "../appearance/ConsoleWindowImp.h"

#include <iostream>

using namespace std;

using namespace appearance;
using namespace document_structure;
using namespace formatting;

void ui::UI::start() {
    while(true){
        this->composition->Draw(this->window);
        this->window->Flush();
        this->printConfig();
        this->printOptions();
        int option = this->readOption();
        this->callOption(option);

        if(quit) return;
    }
}

void ui::UI::handleInsertCharacterOnInsertionPoint() {
    cout << "Unesite karakter: ";
    char c;
    cin>> c;

    composition->insertGlyph(new Character(c),insertionPoint);
    insertionPoint++;
}

void ui::UI::handlePutInsertionPoint() {
    cout << "Input insertion point: "<<endl;
    cin >> insertionPoint;
}

void ui::UI::callOption(int option) {
    switch (option) {
        case 1:
            handlePutInsertionPoint();
            break;
        case 2:
            handleInsertCharacterOnInsertionPoint();
            break;
        case 3:
            handleAddStringToInsertionPoint();
            break;
        case 4:
            quit = true;
            break;
        case 5:
            handleWidthChange();
            break;
        case 6:
            handleHitTest();
            break;
        default:
            cout << "Nevalidna opcija! Unesite ponovo!";
    }
}

int ui::UI::readOption() {
    int option;
    cin>>option;
    return option;
}

void ui::UI::printOptions() {
    cout<<"######################"<<endl;
    cout<<"1. Put insertion point"<<endl;
    cout<<"2. Write char on insertion point"<<endl;
    cout<<"3. Add string to insertion point"<<endl;
    cout<<"4. Quit"<<endl;
    cout<<"5. Change window width"<<endl;
    cout<<"6. Hit test (x y)"<<endl;
    cout<<"######################"<<endl;
}

void ui::UI::printConfig() {
    cout <<"Insertion point location: "<<insertionPoint<<endl;
    cout <<"Width: "<<window->getWidth()<<endl;
}

ui::UI::UI(){
    this->window = new Window(30,30, new ConsoleWindowImp());
    this->composition = new Composition();

    lineWidthSource = new LineWidthSource(*window);
    composition->setCompositor(new formatting::FullCompositor(*lineWidthSource));

}

void ui::UI::handleAddStringToInsertionPoint() {
    cout << "Input string: "<<endl;
    string s;
    cin >> s;
    for(char c: s){
        composition->insertGlyph(new Character(c),insertionPoint);
        insertionPoint++;
    }
}

void ui::UI::handleWidthChange() {
    cout << "Input new width: "<<endl;
    int newWidth;
    cin >> newWidth;
    this->window->setWidth(newWidth);
    this->composition->environmentChanged(*lineWidthSource);

}

void ui::UI::handleHitTest() {
    cout << "Input x y: "<<endl;
    int x, y;
    cin >> x >> y;
    Glyph* hit = composition->HitTest(Point(x, y));
    if(auto* c = dynamic_cast<Character*>(hit)){
        cout << "Hit character '" << c->getChar() << "' (id " << c->getId() << ")" << endl;
    }
    else {
        cout << "Nothing at (" << x << "," << y << ")" << endl;
    }
}
