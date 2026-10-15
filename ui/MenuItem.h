//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_MENUITEM_H
#define LEXI_MENUITEM_H

#include <string>

namespace ui {

    class UI;

    //one option of the console menu: what is shown and which UI handler is called
    class MenuItem {
        public:
            typedef void (UI::*Handler)();

        private:
            std::string label;
            Handler handler;

        public:
            MenuItem(const std::string& label, Handler handler);

            const std::string& getLabel() const;

            //calls the handler on the given ui
            void select(UI& ui) const;
    };

} // ui

#endif //LEXI_MENUITEM_H
