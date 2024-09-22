
#include "interpreter/Interpreter.hpp"

#include <algorithm>

using namespace interpreter;

Interpreter::Interpreter()
{
    Reset();
}

void Interpreter::Reset()
{
    _cpu.Reset();
    _gpu.Reset();
    _ram.Reset();

    _cpu.InitializeMemory(_ram._memoryBuffer);
}

void Interpreter::Step()
{
    _cpu.Step(_ram._memoryBuffer, _gpu._displayBuffer);
}
