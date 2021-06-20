#pragma once

#define FASTLED_INTERNAL
#include <FastLED.h>
#include "animations.h"

// LED config
#define DATA_PIN_A 7
#define DATA_PIN_B 1
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS 60

namespace Intimate
{

    // void glitter(AnimationData &a);

    struct AnimationData
    {
        uint8_t id;
        uint8_t hue;
        uint8_t mods[3];
    };

    class Engine
    {
    public:
        CRGB leds_a[NUM_LEDS];
        CRGB leds_b[NUM_LEDS];
        uint8_t len;
        uint8_t brightness;
        bool utility_toggle;
        AnimationData primary;
        AnimationData accent;
        uint16_t dmx_address;

        Engine()
            : len(NUM_LEDS), brightness(100), utility_toggle(false), primary{0, 0, {0, 0, 0}}, accent{0, 0, {0, 0, 0}}
        {
            // TODO: malloc led array here to accept a dynamic config value for led count
        }

        // Engine core
        void setup(uint16_t addr);
        void ready();
        void refresh();
        void render();
        void fill(CRGB::HTMLColorCode color);
        void blank();

        // Engine step
        void step();
        void animationStep(AnimationData &data);

        // Engine DMX
        void update(uint8_t vals[]);

        // Engine status
        void wifi_wait();
        void wifi_done();
        void error();
    };
} // namespace Intimate