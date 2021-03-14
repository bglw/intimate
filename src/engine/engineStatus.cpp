#include "engine.h"

using namespace Intimate;

void Engine::wifi_wait()
{
    leds[0] = utility_toggle ? CRGB::LightSlateGray : CRGB::Black;
    leds[1] = utility_toggle ? CRGB::Black : CRGB::LightSlateGray;
    utility_toggle = !utility_toggle;
    render();
}

void Engine::wifi_done()
{
    leds[0] = CRGB::LightSlateGray;
    leds[1] = CRGB::LightSlateGray;
    render();
}

void Engine::error()
{
    FastLED.setBrightness(5);
    leds[0] = CRGB::Red;
    leds[2] = CRGB::Red;
    leds[4] = CRGB::Red;
    leds[NUM_LEDS - 1] = CRGB::Red;
    leds[NUM_LEDS - 3] = CRGB::Red;
    leds[NUM_LEDS - 5] = CRGB::Red;
    render();
}
