#include "engine.h"

using namespace Intimate;

void Engine::setup(uint16_t addr)
{
    dmx_address = addr;

    FastLED.addLeds<LED_TYPE, DATA_PIN_A, COLOR_ORDER>(leds_a, len).setCorrection(TypicalLEDStrip);
    FastLED.addLeds<LED_TYPE, DATA_PIN_B, COLOR_ORDER>(leds_b, len).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(5);
    render();
}

void Engine::ready()
{
    blank();
    refresh();
    render();
}

void Engine::refresh()
{
    FastLED.setBrightness(brightness);
}

void Engine::render()
{
    FastLED.show();
}

void Engine::fill(CRGB::HTMLColorCode color)
{
    fill_solid(leds_a, len, color);
    fill_solid(leds_b, len, color);
}

void Engine::blank()
{
    fill(CRGB::Black);
}
