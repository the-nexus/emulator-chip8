
#pragma once

#include "interpreter/components/Display.hpp"
#include "interpreter/components/Instruction.hpp"
#include "interpreter/components/Memory.hpp"
#include "interpreter/components/Processor.hpp"
#include "interpreter/utils/Memory.hpp"

namespace interpreter
{
    class Interpreter
    {
        components::Processor _processor = {};
        components::Instruction _instruction = {};
        components::Memory _memory = { utils::Memory::ToKilobytes(4) };
        components::Display _display = { 64, 32 };

    public:
        Interpreter();

        void Reset();
        void Step();
    };
}
