#pragma once

#include "raylib-cpp.hpp"
#include "Collidable.hpp"
#include "PolarityHandler.hpp"

class Damageable: public Collidable, public PolarityHandler
{
  private:
    int HP;
    bool isDead;

  protected:
    Damageable();
    Damageable(int HP, EPolarity polarity, raylib::Rectangle collisionRect);

    void DrawHP(raylib::Vector2 position, raylib::Color color, float fontSize);

  public:
    void Damage(int amount);
    bool IsDead();
};