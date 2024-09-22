
#pragma once

#include <cstddef>
#include <cstdint>

namespace interpreter::utils
{
    struct Memory
    {
        static size_t constexpr ToKilobytes(size_t const value) { return value * 1024; }
        static uint8_t constexpr GetFlagOff() { return 0x00; }
        static uint8_t constexpr GetFlagOn() { return 0x0F; }
    };
}