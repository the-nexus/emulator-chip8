
#include "interpreter/components/Processor.hpp"

#include <algorithm>

using namespace interpreter::components;

void Processor::Reset()
{
    std::fill(std::begin(_stack), std::end(_stack), 0x0000);
    std::fill(std::begin(_V), std::end(_V), 0x00);
    _I = 0x0000;
    _PC = 0x0000;
    _SP = 0x0000;
    _DT = 0x00;
    _ST = 0x00;
}
