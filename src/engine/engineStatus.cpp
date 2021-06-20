#include "engine.h"

using namespace Intimate;

void Engine::wifi_wait()
{
    leds_a[0] = utility_toggle ? CRGB::LightSlateGray : CRGB::Black;
    leds_a[1] = utility_toggle ? CRGB::Black : CRGB::LightSlateGray;
    utility_toggle = !utility_toggle;
    render();
}

void Engine::wifi_done()
{
    leds_a[0] = CRGB::LightSlateGray;
    leds_a[1] = CRGB::LightSlateGray;
    render();
}

void Engine::error()
{
    FastLED.setBrightness(5);
    leds_a[0] = CRGB::Red;
    leds_a[2] = CRGB::Red;
    leds_a[4] = CRGB::Red;
    leds_a[NUM_LEDS - 1] = CRGB::Red;
    leds_a[NUM_LEDS - 3] = CRGB::Red;
    leds_a[NUM_LEDS - 5] = CRGB::Red;
    render();
}
