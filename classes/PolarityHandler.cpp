#include "raylib-cpp.hpp"
#include "PolarityHandler.hpp"

PolarityHandler::PolarityHandler(){}

PolarityHandler::PolarityHandler(EPolarity polarity)
{
    this->polarity = polarity;
}

void PolarityHandler::TogglePolarity()
{
    if (this->polarity == GOOD)
        this->polarity = EVIL;
    else
        this->polarity = GOOD;
}

EPolarity PolarityHandler::GetPolarity()
{
    return this->polarity;
}