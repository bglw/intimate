#include "../engine.h"

using namespace Intimate;

namespace Intimate
{
    namespace Animations
    {
      void glitter(Engine &engine, AnimationData &data)
      {
        fadeToBlackBy(engine.leds, engine.len, (0.5*data.mods[2]));
        if (random8() < (0.5*data.mods[0]))
        {
          for (int i = 0; i < (0.25*data.mods[1]); i++)
          {
            engine.leds[random16(engine.len)] = CHSV(data.hue, 255, 255);
          }
        }
      }
    }
} // namespace Intimate