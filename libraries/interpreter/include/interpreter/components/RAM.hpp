
#pragma once

#include <cstdint>
#include <vector>

namespace interpreter
{
    struct RAM
    {
        std::vector<uint8_t> _memoryBuffer;

        RAM(size_t const memorySize);
        void Reset();
    };
}
