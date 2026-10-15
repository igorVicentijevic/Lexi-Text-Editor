//
// Created by Igor on 13.10.26..
//

#include "UI.h"
#include "MenuItems.h"
#include "../appearance/ConsoleWindowImp.h"

#include <iostream>

using namespace std;

using namespace appearance;

ui::UI::UI(){
    this->editor = new editor::Editor(new Window(30,30, new ConsoleWindowImp()));

    //new option = new line here
    menu = {
        new PutInsertionPointItem(*editor),
        new InsertCharacterItem(*editor),
        new InsertStringItem(*editor),
        new QuitItem(quit),
        new ChangeWidthItem(*editor),
        new HitTestItem(*editor),
        new InsertRectangleItem(*editor),
    };
}

ui::UI::~UI() {
    //menu items use the editor
    for(MenuItem* item: menu){
        delete item;
    }
    delete editor;
}

void ui::UI::start() {
    while(true){
        editor->redraw();
        this->printConfig();
        this->printOptions();
        int option = this->readOption();
        this->callOption(option);

        if(quit) return;
    }
}

void ui::UI::callOption(int option) {
    if(option < 1 || option > (int)menu.size()){
        cout << "Nevalidna opcija! Unesite ponovo!" << endl;
        return;
    }
    menu[option - 1]->select();
}

int ui::UI::readOption() {
    int option;
    cin>>option;
    return option;
}

void ui::UI::printOptions() {
    cout<<"######################"<<endl;
    for(int i = 0; i < (int)menu.size(); i++){
        cout << i + 1 << ". " << menu[i]->getLabel() << endl;
    }
    cout<<"######################"<<endl;
}

void ui::UI::printConfig() {
    cout <<"Insertion point location: "<<editor->getInsertionPoint()<<endl;
    cout <<"Width: "<<editor->getWidth()<<endl;
}
