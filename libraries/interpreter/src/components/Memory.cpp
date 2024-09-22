
#include "interpreter/components/Memory.hpp"

using namespace interpreter::components;

Memory::Memory(size_t const size)
    : _buffer(size, 0x00)
{}

void Memory::Reset()
{
    std::fill(std::begin(_buffer), std::end(_buffer), 0x00);
}
