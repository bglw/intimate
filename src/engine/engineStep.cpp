#include "engine.h"

using namespace Intimate;

void Engine::step()
{
    animationStep(primary);
    if (accent.id > 0)
    {
        animationStep(accent);
    }
}

void Engine::animationStep(AnimationData &data)
{
    switch (data.id)
    {
        case 0:
            Animations::blank(*this, data);
            break;
        case 1:
            Animations::glitter(*this, data);
            break;
        case 2:
            Animations::glitter(*this, data);
            break;
        case 3:
            Animations::glitter(*this, data);
            break;
    }
}