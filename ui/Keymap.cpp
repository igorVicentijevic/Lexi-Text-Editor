//
// Created by Igor on 17.10.26..
//

#include "Keymap.h"

namespace ui {

    Keymap::~Keymap() {
        for(auto& entry: bindings){
            delete entry.second;
        }
    }

    void Keymap::bind(Key::Type type, KeyBinding* binding) {
        auto it = bindings.find(type);
        if(it != bindings.end()){
            delete it->second;
            it->second = binding;
        }
        else {
            bindings[type] = binding;
        }
    }

    void Keymap::pressed(const Key& key) {
        auto it = bindings.find(key.type);
        if(it != bindings.end()) it->second->pressed(key);
    }

} // ui
