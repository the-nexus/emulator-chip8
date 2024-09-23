
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

    ExecuteInstruction();
}

void Interpreter::ExecuteInstruction()
{
    switch(_instruction._L)
    {
        case 0x0: ExecuteInstruction_0x0(); break;
        case 0x1: ExecuteInstruction_0x1(); break;
        case 0x2: ExecuteInstruction_0x2(); break;
        case 0x3: ExecuteInstruction_0x3(); break;
        case 0x4: ExecuteInstruction_0x4(); break;
        case 0x5: ExecuteInstruction_0x5(); break;
        case 0x6: ExecuteInstruction_0x6(); break;
        case 0x7: ExecuteInstruction_0x7(); break;
        case 0x8: ExecuteInstruction_0x8(); break;
        case 0x9: ExecuteInstruction_0x9(); break;
        case 0xA: ExecuteInstruction_0xA(); break;
        case 0xB: ExecuteInstruction_0xB(); break;
        case 0xC: ExecuteInstruction_0xC(); break;
        case 0xD: ExecuteInstruction_0xD(); break;
        case 0xE: ExecuteInstruction_0xE(); break;
        case 0xF: ExecuteInstruction_0xF(); break;
    }
}

void Interpreter::ExecuteInstruction_0x0()
{
    if (_instruction._value == 0x00E0)
    {
        CLS();
    }
    else if (_instruction._value == 0x00EE)
    {
        RET();
    }
    else
    {
        SYS(_instruction._NNN);
    }
}

void Interpreter::ExecuteInstruction_0x1()
{
   JP(_instruction._NNN);
}

void Interpreter::ExecuteInstruction_0x2()
{
   CALL(_instruction._NNN);
}

void Interpreter::ExecuteInstruction_0x3()
{
    /*
    3xkk - SE Vx, byte
    */
}

void Interpreter::ExecuteInstruction_0x4()
{
    /*
    4xkk - SNE Vx, byte
    */
}

void Interpreter::ExecuteInstruction_0x5()
{
    /*
    5xy0 - SE Vx, Vy
    */
}

void Interpreter::ExecuteInstruction_0x6()
{
    /*
    6xkk - LD Vx, byte
    */
}

void Interpreter::ExecuteInstruction_0x7()
{
    /*
    7xkk - ADD Vx, byte
    */
}

void Interpreter::ExecuteInstruction_0x8()
{
    /*
    8xy0 - LD Vx, Vy
    8xy1 - OR Vx, Vy
    8xy2 - AND Vx, Vy
    8xy3 - XOR Vx, Vy
    8xy4 - ADD Vx, Vy
    8xy5 - SUB Vx, Vy
    8xy6 - SHR Vx {, Vy}
    8xy7 - SUBN Vx, Vy
    8xyE - SHL Vx {, Vy}
    */
}

void Interpreter::ExecuteInstruction_0x9()
{
    /*
    9xy0 - SNE Vx, Vy
    */
}

void Interpreter::ExecuteInstruction_0xA()
{
    /*
    Annn - LD I, addr
    */
}

void Interpreter::ExecuteInstruction_0xB()
{
    /*
    Bnnn - JP V0, addr
    */
}

void Interpreter::ExecuteInstruction_0xC()
{
    /*
    Cxkk - RND Vx, byte
    */
}

void Interpreter::ExecuteInstruction_0xD()
{
    /*
    Dxyn - DRW Vx, Vy, nibble
    */
}

void Interpreter::ExecuteInstruction_0xE()
{
    /*
    Ex9E - SKP Vx
    ExA1 - SKNP Vx
    */
}

void Interpreter::ExecuteInstruction_0xF()
{
    /*
    Fx07 - LD Vx, DT
    Fx0A - LD Vx, K
    Fx15 - LD DT, Vx
    Fx18 - LD ST, Vx
    Fx1E - ADD I, Vx
    Fx29 - LD F, Vx
    Fx33 - LD B, Vx
    Fx55 - LD [I], Vx
    Fx65 - LD Vx, [I]
    */
}

void Interpreter::CLS()
{
    _display.Reset();
}

void Interpreter::RET()
{
    
}

void Interpreter::SYS(uint16_t const address)
{
    _processor._PC = address;
}

void Interpreter::JP(uint16_t const address)
{
    
}

void Interpreter::CALL(uint16_t const address)
{
    
}

void Interpreter::SE(uint8_t const lhs, uint8_t const rhs)
{
    if (lhs == rhs)
    {
        _processor._PC += 2;
    }
}

void Interpreter::SNE(uint8_t const lhs, uint8_t const rhs)
{
    if (lhs != rhs)
    {
        _processor._PC += 2;
    }
}
