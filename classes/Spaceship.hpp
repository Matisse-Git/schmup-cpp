#pragma once

#include "raylib-cpp.hpp"
#include "Moveable.hpp"
#include "Fireable.hpp"
#include "Damageable.hpp"
#include "PolarityHandler.hpp"

class Spaceship: public Moveable, public Fireable, public Damageable
{
  protected:
    Spaceship();
    Spaceship(raylib::Vector2 position, float speed, float fireRate, float bulletSpeed, int HP, EPolarity polarity);

  public:
    virtual void Update();
    virtual void Draw();
};