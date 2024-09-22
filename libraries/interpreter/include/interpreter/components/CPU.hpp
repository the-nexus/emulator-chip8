
#pragma once

#include <array>
#include <cstdint>
#include <vector>

namespace interpreter
{
    struct CPU
    {
        struct InstructionData
        {
            uint16_t _value = 0x0000;
            uint16_t _NNN = 0x000;
            uint8_t _KK = 0x00;
            uint8_t _R = 0x0;
            uint8_t _X = 0x0;
            uint8_t _Y = 0x0;
            uint8_t _L = 0x0;

            InstructionData(uint16_t const value);
            InstructionData(uint8_t const highByte, uint8_t const lowByte);
        };

        static uint16_t constexpr _FONT_ADDRESS = 0x1B0;
        static uint16_t constexpr _START_ADDRESS = 0x200;

        InstructionData _instruction = { 0x0000 };

        std::array<uint8_t, 16> _stack;     // Limited to depth of 16 addresses
        std::array<uint8_t, 16> _V;         // Register at 0xF is for instruction flags, not for data storage
        uint16_t _I = 0X0000;   // Address register, 12 bits (0xFFF mask)
        uint16_t _PC = 0x0000;  // Program counter (address pointer)
        uint8_t _SP = 0x0000;   // Stack pointer (address pointer)
        uint8_t _DT = 0x00;     // Delay timer, decremented at rate of 60 Hz
        uint8_t _ST = 0x00;     // Sound timer, decremented at rate of 60 Hz

        void InitializeMemory(std::vector<uint8_t>& memoryBuffer) const;

        void Reset();
        void Step(std::vector<uint8_t>& memoryBuffer, std::vector<uint8_t>& displayBuffer);
    };
}
