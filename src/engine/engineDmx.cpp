#include "engine.h"

using namespace Intimate;

// WIP DMX Channels
// TODO: Abstract this somehow

void Engine::update(uint8_t vals[])
{
    uint8_t i = dmx_address + 1; // Skip first value (universe data)

    for(int dot = 0; dot < NUM_LEDS; dot++) { 
        leds[dot].r = vals[i++];
        leds[dot].g = vals[i++];
        leds[dot].b = vals[i++];
    }

    // if (vals[i] != brightness)
    // {
    //     brightness = vals[i];
    //     refresh();
    // }

    // primary.id = vals[++i];
    // primary.hue = vals[++i];
    // primary.mods[0] = vals[++i];
    // primary.mods[1] = vals[++i];
    // primary.mods[2] = vals[++i];

    // accent.id = vals[++i];
    // accent.hue = vals[++i];
    // accent.mods[0] = vals[++i];
    // accent.mods[1] = vals[++i];
    // accent.mods[2] = vals[++i];
}