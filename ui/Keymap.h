//
// Created by Igor on 17.10.26..
//

#ifndef LEXI_KEYMAP_H
#define LEXI_KEYMAP_H

#include "KeyBinding.h"

#include <map>

namespace ui {

    //which binding is triggered by which key; owns its bindings
    class Keymap {
        private:
            std::map<Key::Type, KeyBinding*> bindings;

        public:
            Keymap() = default;
            ~Keymap();

            Keymap(const Keymap&) = delete;
            Keymap& operator=(const Keymap&) = delete;

            //takes ownership; a binding already on that key is deleted
            void bind(Key::Type type, KeyBinding* binding);

            //keys without a binding are ignored
            void pressed(const Key& key);
    };

} // ui

#endif //LEXI_KEYMAP_H
