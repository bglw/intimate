#include "../engine.h"

using namespace Intimate;

namespace Intimate
{
    namespace Animations
    {
      void glitter(Engine &engine, AnimationData &data)
      {
        fadeToBlackBy(engine.leds, engine.len, data.mods[2]);
        if (random8() < data.mods[0])
        {
          for (int i = 0; i < data.mods[1]; i++)
          {
            engine.leds[random16(engine.len)] = CRGB::Pink;
          }
        }
      }
    }
} // namespace Intimate