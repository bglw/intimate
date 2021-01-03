#include "engine.h"

using namespace Intimate;

void Engine::setup(uint8_t addr)
{
    dmx_address = addr;

    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, len).setCorrection(TypicalLEDStrip);
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
    fill_solid(leds, len, color);
}

void Engine::blank()
{
    fill(CRGB::Black);
    render();
}