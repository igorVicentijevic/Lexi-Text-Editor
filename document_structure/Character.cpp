//
// Created by Igor on 13.10.26..
//

#include "Character.h"

namespace document_structure {

    Character::Character(char c):c(c){}

    void Character::Draw(Window* w){
        w->DrawCharacter(this->c, position.x, position.y);
    }

    void Character::Bounds(Rect& r){
        r = Rect(position.x, position.y, position.x + WIDTH, position.y + HEIGHT);
    }


    //print

    std::string Character::getType() const{
        return "C";
    }


} // document_structure
