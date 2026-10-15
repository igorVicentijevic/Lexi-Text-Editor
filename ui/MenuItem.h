//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_MENUITEM_H
#define LEXI_MENUITEM_H

#include <string>

namespace ui {

    //one option of the console menu: what is shown and what happens when it is selected
    class MenuItem {
        private:
            std::string label;

        public:
            explicit MenuItem(const std::string& label);
            virtual ~MenuItem() = default;

            const std::string& getLabel() const;

            virtual void select() = 0;
    };

} // ui

#endif //LEXI_MENUITEM_H
