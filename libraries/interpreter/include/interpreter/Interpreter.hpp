
#pragma once

#include "interpreter/components/CPU.hpp"
#include "interpreter/components/GPU.hpp"
#include "interpreter/components/RAM.hpp"

namespace interpreter
{
    class Interpreter
    {
        CPU _cpu;
        GPU _gpu = { std::make_pair(64, 32) };  // 64x32
        RAM _ram = { 4 * 1024 };                // 4kB

    public:
        Interpreter();

        void Reset();
        void Step();
    };
}
