//
// Created by Igor on 17.10.26..
//

#ifndef LEXI_MENU_H
#define LEXI_MENU_H

#include "MenuItem.h"

#include <vector>

namespace ui {

    //numbered list of menu items; owns them
    class Menu {
        private:
            std::vector<MenuItem*> items;

        public:
            Menu() = default;
            ~Menu();

            Menu(const Menu&) = delete;
            Menu& operator=(const Menu&) = delete;

            //takes ownership; items are shown in the order they are added
            void add(MenuItem* item);

            void show() const;
            //reads the number of an item and selects it;
            //the whole input line is consumed, also when the option is invalid
            void choose();
    };

} // ui

#endif //LEXI_MENU_H
