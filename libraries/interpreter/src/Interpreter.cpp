
#include "interpreter/Interpreter.hpp"

#include <algorithm>

#include "interpreter/systems/FontLoader.hpp"

using namespace interpreter;

Interpreter::Interpreter()
{
    Reset();
}

void Interpreter::Reset()
{
    _processor.Reset();
    _instruction = {};
    _memory.Reset();
    _display.Reset();

    systems::FontLoader::LoadSprite(components::Processor::GetFontAddress(), _memory);
    _processor._PC = components::Processor::GetProgramAddress();
}

void Interpreter::Step()
{
    _instruction = {
        _memory._buffer[_processor._PC++],
        _memory._buffer[_processor._PC++]
    };

    
}
