
#pragma once

#include <cstdint>
#include <tuple>
#include <vector>

namespace interpreter::components
{
    struct Display
    {
        std::vector<uint8_t> _buffer = {};
        size_t const _width = 0;
        size_t const _height = 0;

        Display(size_t const width, size_t const height);
        void Reset();
    };
}
