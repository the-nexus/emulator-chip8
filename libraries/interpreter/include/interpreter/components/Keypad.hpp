
#pragma once

#include <array>
#include <cstdint>

namespace interpreter::components
{
    struct Keypad
    {
        struct Key
        {
            uint8_t _flagIsPressed = 0x00;
        };

        std::array<Key, 16> _keys = {};

        Keypad() = default;
    };
}