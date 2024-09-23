
#pragma once

#include <functional>

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

    private:
        void ExecuteInstruction();
        void ExecuteInstruction_0x0();
        void ExecuteInstruction_0x1();
        void ExecuteInstruction_0x2();
        void ExecuteInstruction_0x3();
        void ExecuteInstruction_0x4();
        void ExecuteInstruction_0x5();
        void ExecuteInstruction_0x6();
        void ExecuteInstruction_0x7();
        void ExecuteInstruction_0x8();
        void ExecuteInstruction_0x9();
        void ExecuteInstruction_0xA();
        void ExecuteInstruction_0xB();
        void ExecuteInstruction_0xC();
        void ExecuteInstruction_0xD();
        void ExecuteInstruction_0xE();
        void ExecuteInstruction_0xF();

        void CLS();
        void RET();
        void SYS(uint16_t const address);
        void JP(uint16_t const address);
        void CALL(uint16_t const address);
        void SE(uint8_t const lhs, uint8_t const rhs);
        void SNE(uint8_t const lhs, uint8_t const rhs);
        // void LD(src, dst);
        // void ADD(lhs, rhs);
        // void OR(lhs, rhs);
        // void AND(lhs, rhs);
        // void XOR(lhs, rhs);
        // void SUB(lhs, rhs);
        // void SHR(lhs, ???);
        // void SUBN(lhs, rhs);
        // void SHL(lhs, ???);
        // void RND(lhs, rhs);
        // void DRW(lhs, rhs, nib);
        // void SKP(lhs);
        // void SKNP(lhs);
    };
}
