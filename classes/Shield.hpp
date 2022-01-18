#pragma once

#include "raylib-cpp.hpp"
#include "Collidable.hpp"
#include "PolarityHandler.hpp"
#include "Stationary.hpp"

class Shield: public Collidable, public PolarityHandler, public Stationary
{
  private:
    raylib::Rectangle goodSpriteRect;
    raylib::Rectangle evilSpriteRect;

  public:
    Shield();
    Shield(raylib::Vector2 position, raylib::Rectangle goodSpriteRect, raylib::Rectangle evilSpriteRect, EPolarity polarity);

    void Update(raylib::Vector2 position, EPolarity polarity);
    void Draw();
};