#pragma once

#include "raylib-cpp.hpp"

enum EPolarity { GOOD, EVIL };

class PolarityHandler
{
  private:
    EPolarity polarity;

  protected:
    PolarityHandler();
    PolarityHandler(EPolarity polarity);

    void TogglePolarity();

  public:
    EPolarity GetPolarity();
};