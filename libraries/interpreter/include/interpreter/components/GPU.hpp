
#pragma once

#include <cstdint>
#include <tuple>
#include <vector>

namespace interpreter
{
    struct GPU
    {
        static uint8_t constexpr _PIXEL_ON = 0x01;
        static uint8_t constexpr _PIXEL_OFF = 0x00;

        std::vector<uint8_t> _displayBuffer;
        std::pair<size_t, size_t> _displayDimensions;

        GPU(std::pair<size_t, size_t> const displayDimensions);
        void Reset();
    };
}
