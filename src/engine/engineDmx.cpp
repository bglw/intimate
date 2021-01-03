#include "engine.h"

using namespace Intimate;

void Engine::update(uint8_t vals[])
{
    uint8_t i = dmx_address + 1; // Skip first value (universe data)

    if (vals[i] != brightness)
    {
        brightness = vals[i++];
        refresh();
    }

    primary.mods[0] = vals[i++];
    primary.mods[1] = vals[i++];
    primary.mods[2] = vals[i++];
}