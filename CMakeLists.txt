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
        appearance/Point.h)
