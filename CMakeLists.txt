cmake_minimum_required(VERSION 3.26)
project(Lexi)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lexi main.cpp
        document_structure/Glyph.cpp
        document_structure/Glyph.h
        appearance/Window.cpp
        appearance/Window.h
        appearance/WindowImp.h
        appearance/ConsoleWindowImp.cpp
        appearance/ConsoleWindowImp.h
        appearance/Rect.cpp
        appearance/Rect.h
        appearance/Point.cpp
        appearance/Point.h
        document_structure/Rectangle.cpp
        document_structure/Rectangle.h
        document_structure/Character.cpp
        document_structure/Character.h
        document_structure/Row.cpp
        document_structure/Row.h
        document_structure/formatting/Composition.cpp
        document_structure/formatting/Composition.h
        document_structure/formatting/Compositor.cpp
        document_structure/formatting/Compositor.h
        document_structure/Column.cpp
        document_structure/Column.h
        document_structure/CompositeGlyph.cpp
        document_structure/CompositeGlyph.h
        ui/UI.cpp
        ui/UI.h
        ui/MenuItem.cpp
        ui/MenuItem.h
        editor/Editor.cpp
        editor/Editor.h
        editor/InsertionPoint.cpp
        editor/InsertionPoint.h
        commands/CommandFactory.cpp
        commands/CommandFactory.h
        commands/Command.h
        commands/InsertGlyphCommand.cpp
        commands/InsertGlyphCommand.h
        commands/MacroCommand.cpp
        commands/MacroCommand.h
        commands/MoveInsertionPointCommand.h
        commands/ChangeWidthCommand.h
        document_structure/formatting/FullCompositor.cpp
        document_structure/formatting/FullCompositor.h
        document_structure/formatting/environment_source/EnvironmentSource.cpp
        document_structure/formatting/environment_source/EnvironmentSource.h
        document_structure/formatting/environment_source/LineWidthSource.cpp
        document_structure/formatting/environment_source/LineWidthSource.h
)
