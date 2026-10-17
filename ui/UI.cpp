//
// Created by Igor on 13.10.26..
//

#include "UI.h"
#include "MenuItems.h"
#include "KeyBindings.h"
#include "../appearance/ConsoleWindowImp.h"

#include <iostream>

using namespace std;

using namespace appearance;

ui::UI::UI(){
    this->editor = new editor::Editor(new Window(30,30, new ConsoleWindowImp()));

    //new option = new line here
    menu = new Menu();
    menu->add(new PutInsertionPointItem(*editor));
    menu->add(new InsertCharacterItem(*editor));
    menu->add(new InsertStringItem(*editor));
    menu->add(new QuitItem(quit));
    menu->add(new ChangeWidthItem(*editor));
    menu->add(new HitTestItem(*editor));
    menu->add(new InsertRectangleItem(*editor));
    menu->add(new RemoveGlyphItem(*editor));

    //new key = new line here
    keymap = new Keymap();
    keymap->bind(Key::Char,      new TypeCharacterBinding(*editor));
    keymap->bind(Key::Backspace, new RemoveGlyphBinding(*editor));
    keymap->bind(Key::Left,      new MoveInsertionPointBinding(*editor, -1));
    keymap->bind(Key::Right,     new MoveInsertionPointBinding(*editor, +1));
    keymap->bind(Key::Menu,      new OpenMenuBinding(*menu, terminal));
    keymap->bind(Key::Quit,      new QuitBinding(quit));
}

ui::UI::~UI() {
    //bindings use the menu, everything uses the editor
    delete keymap;
    delete menu;
    delete editor;
}

void ui::UI::start() {
    while(!quit){
        editor->redraw();
        this->printConfig();
        keymap->pressed(terminal.readKey());
    }
}

void ui::UI::printConfig() {
    cout <<"Insertion point location: "<<editor->getInsertionPoint()<<endl;
    cout <<"Width: "<<editor->getWidth()<<endl;
    cout <<"Ctrl+O meni, Ctrl+Q izlaz"<<endl;
}
