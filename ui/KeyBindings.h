//
// Created by Igor on 17.10.26..
//

#ifndef LEXI_KEYBINDINGS_H
#define LEXI_KEYBINDINGS_H

#include "KeyBinding.h"
#include "Menu.h"
#include "../editor/Editor.h"

namespace ui {

    //key binding that works with the editor
    class EditorKeyBinding: public KeyBinding {
        protected:
            editor::Editor& editor;

        public:
            explicit EditorKeyBinding(editor::Editor& editor): editor(editor){}
    };

    //any printable character, inserted at the insertion point
    class TypeCharacterBinding: public EditorKeyBinding {
        public:
            explicit TypeCharacterBinding(editor::Editor& editor): EditorKeyBinding(editor){}
            void pressed(const Key& key) override;
    };

    //Backspace
    class RemoveGlyphBinding: public EditorKeyBinding {
        public:
            explicit RemoveGlyphBinding(editor::Editor& editor): EditorKeyBinding(editor){}
            void pressed(const Key& key) override;
    };

    //moves the insertion point by delta (-1 left, +1 right)
    class MoveInsertionPointBinding: public EditorKeyBinding {
        private:
            int delta;
        public:
            MoveInsertionPointBinding(editor::Editor& editor, int delta): EditorKeyBinding(editor), delta(delta){}
            void pressed(const Key& key) override;
    };

    //moves the insertion point to the row above (direction -1) or below (direction +1)
    class MoveInsertionPointVerticallyBinding: public EditorKeyBinding {
        private:
            int direction;
        public:
            MoveInsertionPointVerticallyBinding(editor::Editor& editor, int direction):
                EditorKeyBinding(editor), direction(direction){}
            void pressed(const Key& key) override;
    };

    //shows the menu in normal terminal mode, raw mode again after it
    class OpenMenuBinding: public KeyBinding {
        private:
            Menu& menu;
            RawTerminal& terminal;
        public:
            OpenMenuBinding(Menu& menu, RawTerminal& terminal): menu(menu), terminal(terminal){}
            void pressed(const Key& key) override;
    };

    class QuitBinding: public KeyBinding {
        private:
            bool& quit;
        public:
            explicit QuitBinding(bool& quit): quit(quit){}
            void pressed(const Key&) override { quit = true; }
    };

} // ui

#endif //LEXI_KEYBINDINGS_H
