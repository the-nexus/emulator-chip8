
#include "interpreter/components/GPU.hpp"

using namespace interpreter;

void GPU::Reset()
{
    std::fill(std::begin(_displayBuffer), std::end(_displayBuffer), GPU::_PIXEL_OFF);
}
