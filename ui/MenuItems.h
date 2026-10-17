//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_MENUITEMS_H
#define LEXI_MENUITEMS_H

#include "MenuItem.h"
#include "../editor/Editor.h"
#include "../commands/Command.h"

namespace ui {

    //menu item that works with the editor
    class EditorMenuItem: public MenuItem {
        protected:
            editor::Editor& editor;

            //executes and deletes the command
            void execute(commands::Command* c);

        public:
            EditorMenuItem(const std::string& label, editor::Editor& editor): MenuItem(label), editor(editor){}
    };

    class PutInsertionPointItem: public EditorMenuItem {
        public:
            explicit PutInsertionPointItem(editor::Editor& editor): EditorMenuItem("Put insertion point", editor){}
            void select() override;
    };

    class InsertCharacterItem: public EditorMenuItem {
        public:
            explicit InsertCharacterItem(editor::Editor& editor): EditorMenuItem("Write char on insertion point", editor){}
            void select() override;
    };

    class InsertStringItem: public EditorMenuItem {
        public:
            explicit InsertStringItem(editor::Editor& editor): EditorMenuItem("Add string to insertion point", editor){}
            void select() override;
    };

    class ChangeWidthItem: public EditorMenuItem {
        public:
            explicit ChangeWidthItem(editor::Editor& editor): EditorMenuItem("Change window width", editor){}
            void select() override;
    };

    class HitTestItem: public EditorMenuItem {
        public:
            explicit HitTestItem(editor::Editor& editor): EditorMenuItem("Hit test (x y)", editor){}
            void select() override;
    };

    class InsertRectangleItem: public EditorMenuItem {
        public:
            explicit InsertRectangleItem(editor::Editor& editor): EditorMenuItem("Add rectangle to insertion point", editor){}
            void select() override;
    };

    class RemoveGlyphItem: public EditorMenuItem {
        public:
            explicit RemoveGlyphItem(editor::Editor& editor): EditorMenuItem("Remove glyph before insertion point", editor){}
            void select() override;
    };

    class QuitItem: public MenuItem {
        private:
            bool& quit;
        public:
            explicit QuitItem(bool& quit): MenuItem("Quit"), quit(quit){}
            void select() override { quit = true; }
    };

} // ui

#endif //LEXI_MENUITEMS_H
