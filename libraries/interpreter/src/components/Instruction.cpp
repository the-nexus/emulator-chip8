
#include "interpreter/components/Instruction.hpp"

using namespace interpreter::components;

Instruction::Instruction(uint16_t const value)
    : _value(value)
    , _NNN(value & 0x0FFF)
    , _KK(static_cast<uint8_t>(value & 0x00FF))
    , _R(static_cast<uint8_t>((value & 0x000F)))
    , _X(static_cast<uint8_t>((value & 0x00F0) >> 4))
    , _Y(static_cast<uint8_t>((value & 0x0F00) >> 8))
    , _L(static_cast<uint8_t>((value & 0xF000) >> 12))
{}

Instruction::Instruction(uint8_t const highByte, uint8_t const lowByte)
    : Instruction(static_cast<uint16_t>(highByte) << 8 | static_cast<uint16_t>(lowByte))
{}
