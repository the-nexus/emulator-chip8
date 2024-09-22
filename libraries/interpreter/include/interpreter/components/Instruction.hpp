
#pragma once

#include <cstdint>

namespace interpreter::components
{
    struct Instruction
    {
        uint16_t _value = 0x0000;
        uint16_t _NNN = 0x000;
        uint8_t _KK = 0x00;
        uint8_t _R = 0x00;
        uint8_t _X = 0x00;
        uint8_t _Y = 0x00;
        uint8_t _L = 0x00;

        Instruction() = default;
        Instruction(uint16_t const value);
        Instruction(uint8_t const highByte, uint8_t const lowByte);

        void Reset();
    };
}