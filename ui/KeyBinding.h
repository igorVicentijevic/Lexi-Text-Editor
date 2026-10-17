//
// Created by Igor on 17.10.26..
//

#ifndef LEXI_KEYBINDING_H
#define LEXI_KEYBINDING_H

#include "RawTerminal.h"

namespace ui {

    //What happens when a key is pressed - the keyboard counterpart of MenuItem.
    class KeyBinding {
        public:
            virtual ~KeyBinding() = default;

            //key is passed because some bindings need it (which character was typed)
            virtual void pressed(const Key& key) = 0;
    };

} // ui

#endif //LEXI_KEYBINDING_H
