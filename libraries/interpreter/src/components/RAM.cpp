
#include "interpreter/components/RAM.hpp"

using namespace interpreter;

RAM::RAM(size_t const memorySize)
    : _memoryBuffer(memorySize)
{}

void RAM::Reset()
{
    std::fill(std::begin(_memoryBuffer), std::end(_memoryBuffer), 0x00);
}
