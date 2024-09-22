
project(Chip8_Emulator)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/Main.cpp)

target_link_libraries(${PROJECT_NAME}
    PRIVATE chip8::interpreter
)
