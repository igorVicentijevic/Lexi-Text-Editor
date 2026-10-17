//
// Created by Igor on 17.10.26..
//

#include "Menu.h"

#include <iostream>
#include <limits>

using namespace std;

namespace ui {

    Menu::~Menu() {
        for(MenuItem* item: items){
            delete item;
        }
    }

    void Menu::add(MenuItem* item) {
        items.push_back(item);
    }

    void Menu::show() const {
        cout<<"######################"<<endl;
        for(int i = 0; i < (int)items.size(); i++){
            cout << i + 1 << ". " << items[i]->getLabel() << endl;
        }
        cout<<"######################"<<endl;
    }

    void Menu::choose() {
        int option;
        if(!(cin >> option)){
            //not a number
            option = 0;
        }

        if(option < 1 || option > (int)items.size()){
            cout << "Nevalidna opcija!" << endl;
        }
        else {
            items[option - 1]->select();
        }

        //items read with >>, which leaves the end of the line unread;
        //it is consumed here, so the next read starts on a new line.
        //An item could also have failed to read a number, that must not break the next read.
        if(!cin.eof()) cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

} // ui
