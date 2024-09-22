
cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)

add_subdirectory(executables)
add_subdirectory(libraries)

project(emulator-chip8
    DESCRIPTION "A C++ implementation of a Chip-8 emulator."
    HOMEPAGE_URL "https://github.com/the-nexus/emulator-chip8"
    LANGUAGES CXX
)
