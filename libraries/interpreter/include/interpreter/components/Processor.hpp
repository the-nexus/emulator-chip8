
#pragma once

#include <array>
#include <cstdint>
#include <vector>

namespace interpreter::components
{
    struct Processor
    {
        std::array<uint8_t, 16> _stack = {};     // Limited to depth of 16 addresses
        std::array<uint8_t, 16> _V = {};         // Register at 0xF is for instruction flags, not for data storage
        uint16_t _I = 0x0000;   // Address register, 12 bits (0xFFF mask)
        uint16_t _PC = 0x0000;  // Program counter (address pointer)
        uint8_t _SP = 0x0000;   // Stack pointer (address pointer)
        uint8_t _DT = 0x00;     // Delay timer, decremented at rate of 60 Hz
        uint8_t _ST = 0x00;     // Sound timer, decremented at rate of 60 Hz

        Processor() = default;
        void Reset();

        static uint16_t constexpr GetFontAddress() { return 0x01B0; }
        static uint16_t constexpr GetProgramAddress() { return 0x0200; }
    };
}
