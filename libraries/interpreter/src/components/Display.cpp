
#include "interpreter/components/Display.hpp"

#include "interpreter/utils/Memory.hpp"

using namespace interpreter::components;

Display::Display(size_t const width, size_t const height)
    : _buffer(width * height, utils::Memory::GetFlagOff())
    , _width(width)
    , _height(height)
{}

void Display::Reset()
{
    std::fill(std::begin(_buffer), std::end(_buffer), utils::Memory::GetFlagOff());
}
