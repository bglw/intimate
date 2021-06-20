#include "engine.h"

using namespace Intimate;

// WIP DMX Channels
// TODO: Abstract this somehow

void Engine::update(uint8_t vals[])
{
    uint16_t i = dmx_address;

    for(int dot = 0; dot < NUM_LEDS; dot+=1) { 
        leds_b[dot].r = vals[i];
        leds_a[dot].r = vals[i++];

        leds_b[dot].g = vals[i];
        leds_a[dot].g = vals[i++];

        leds_b[dot].b = vals[i];
        leds_a[dot].b = vals[i++];
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