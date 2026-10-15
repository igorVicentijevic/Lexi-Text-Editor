//
// Created by Igor on 16.10.26..
//

#include "MenuItem.h"
#include "UI.h"

namespace ui {

    MenuItem::MenuItem(const std::string& label, Handler handler): label(label), handler(handler){}

    const std::string& MenuItem::getLabel() const {
        return label;
    }

    void MenuItem::select(UI& ui) const {
        (ui.*handler)();
    }

} // ui
