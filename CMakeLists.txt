cmake_minimum_required(VERSION 3.26)
project(Lexi)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lexi main.cpp
        document_structure/Glyph.cpp
        document_structure/Glyph.h
        appearance/Window.cpp
        appearance/Window.h
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
        document_structure/formatting/SimpleCompositor.cpp
        document_structure/formatting/SimpleCompositor.h
        document_structure/Column.cpp
        document_structure/Column.h
        document_structure/insertion/Inserter.cpp
        document_structure/insertion/Inserter.h
        document_structure/insertion/SimpleInserter.cpp
        document_structure/insertion/SimpleInserter.h
)
