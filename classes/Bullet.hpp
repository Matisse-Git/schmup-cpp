#pragma once

#include "raylib-cpp.hpp"
#include "PolarityHandler.hpp"
#include "Collidable.hpp"
#include "Moveable.hpp"

class Bullet: public Moveable, public Collidable, public PolarityHandler
{
  private:
    raylib::Vector2 direction;
  
  public:
    Bullet(raylib::Vector2 position, float speed, raylib::Vector2 direction, EPolarity polarity);

    void Update();
    void Draw();
};