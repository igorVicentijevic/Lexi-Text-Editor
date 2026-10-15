//
// Created by Igor on 16.10.26..
//

#include "MenuItem.h"

namespace ui {

    MenuItem::MenuItem(const std::string& label): label(label){}

    const std::string& MenuItem::getLabel() const {
        return label;
    }

} // ui
