
#include "interpreter/systems/FontLoader.hpp"

#include <algorithm>
#include <array>
#include <iterator>

#include "interpreter/components/Memory.hpp"

using namespace interpreter::systems;

void FontLoader::LoadSprite(uint16_t const address, components::Memory& memory)
{
    static std::array<uint8_t, 5 * 16> constexpr fontBuffer =
    {
        0xF0, 0x90, 0x90, 0x90, 0xF0,   // 0
        0x20, 0x60, 0x20, 0x20, 0x70,   // 1
        0xF0, 0x10, 0xF0, 0x80, 0xF0,   // 2
        0xF0, 0x10, 0xF0, 0x10, 0xF0,   // 3
        0x90, 0x90, 0xF0, 0x10, 0x10,   // 4
        0xF0, 0x80, 0xF0, 0x10, 0xF0,   // 5
        0xF0, 0x80, 0xF0, 0x90, 0xF0,   // 6
        0xF0, 0x10, 0x20, 0x40, 0x40,   // 7
        0xF0, 0x90, 0xF0, 0x90, 0xF0,   // 8
        0xF0, 0x90, 0xF0, 0x10, 0xF0,   // 9
        0xF0, 0x90, 0xF0, 0x90, 0x90,   // A
        0xE0, 0x90, 0xE0, 0x90, 0xE0,   // B
        0xF0, 0x80, 0x80, 0x80, 0xF0,   // C
        0xE0, 0x90, 0x90, 0x90, 0xE0,   // D
        0xF0, 0x80, 0xF0, 0x80, 0xF0,   // E
        0xF0, 0x80, 0xF0, 0x80, 0x80    // F
    };

    size_t const memoryIndex = static_cast<size_t>(address);
    if (memoryIndex >= memory._buffer.size())
    {
        return;
    }

    auto memoryBeginIt = std::begin(memory._buffer);
    std::advance(memoryBeginIt, memoryIndex);

    auto fontEndIt = std::end(fontBuffer);
    size_t const remainingMemorySize = std::distance(memoryBeginIt, std::end(memory._buffer));
    if (remainingMemorySize < fontBuffer.size())
    {
        std::advance(fontEndIt, remainingMemorySize - fontBuffer.size());
    }

    std::copy(std::begin(fontBuffer), fontEndIt, memoryBeginIt);
}
