
#pragma once

#include <cstdint>

namespace interpreter::components
{
    struct Memory;
}

namespace interpreter::systems
{
    struct FontLoader
    {
        static void LoadSprite(uint16_t const address, components::Memory& memory);
    };
}
