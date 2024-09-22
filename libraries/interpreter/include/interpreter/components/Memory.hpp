
#pragma once

#include <cstdint>
#include <vector>

namespace interpreter::components
{
    struct Memory
    {
        std::vector<uint8_t> _buffer;

        Memory(size_t const size);
        void Reset();
    };
}
