//
// Created by Igor on 13.10.26..
//

#include "UI.h"
#include "../document_structure/Character.h"
#include "../document_structure/formatting/SimpleCompositor.h"
#include "../document_structure/insertion/SimpleInserter.h"

#include <iostream>

using namespace std;

using namespace appearance;
using namespace formatting;

void ui::UI::start() {
    while(true){
        this->composition->Draw(this->window);
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
            quit = true;
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
    cout<<"3. Quit"<<endl;
    cout<<"######################"<<endl;
}

void ui::UI::printConfig() {
    cout <<"Insertion point location: "<<insertionPoint<<endl;
    cout <<"Width: "<<window->getWidth()<<endl;
}

ui::UI::UI() {
    this->window = new Window(30,30);
    this->composition = new Composition();
    formatting::Compositor* compositor;

    insertion::Inserter* inserter = new insertion::SimpleInserter(composition);


    formatting::SimpleCompositor* simpleCompositor = new formatting::SimpleCompositor(composition);
    simpleCompositor->setWidth(window->getWidth());

    compositor = simpleCompositor;
    compositor->setInserter(inserter);

    composition->setCompositor(compositor);

}
