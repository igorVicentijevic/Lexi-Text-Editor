//
// Created by Igor on 13.10.26..
//

#include "Character.h"

namespace document_structure {

    Character::Character(char c):c(c){}

    void Character::Draw(Window* w){
        w->DrawCharacter(this->c);
    }

    void Character::Bounds(Rect& r){
        //TODO
    }

    bool Character::Intersects(const Point&){
        //TODO
        return true;
    }


    //print

    std::string Character::getType() const{
        return "C";
    }


} // document_structure