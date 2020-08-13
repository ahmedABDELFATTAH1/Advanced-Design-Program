cmake_minimum_required(VERSION 3.16)
project(untitled2)

set(CMAKE_CXX_STANDARD 20)
set(SFML_INCLUDE_DIR "/home/rewieer/Libraries/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "/home/rewieer/Libraries/SFML-2.5.1/lib")
set(SFML_DIR "/home/rewieer/Libraries/SFML-2.5.1/lib/cmake/SFML")
link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

include_directories(.)
include_directories(Figures)
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
add_executable(untitled2
    Figures/Page.cpp
    Figures/Page.h
    Figures/Text.cpp
    Figures/Text.h
    Application.cpp
    Application.h
    common.h
    Element.cpp
    Element.h
    main.cpp)

target_link_libraries (untitled2 sfml-graphics sfml-window sfml-system)