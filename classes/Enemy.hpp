#pragma once

#include "raylib-cpp.hpp"
#include "Spaceship.hpp"
#include "PolarityHandler.hpp"

class Enemy: public Spaceship
{
  private:
    raylib::Vector2 direction;

  public:
    Enemy();
    Enemy(raylib::Vector2 position, float speed, float fireRate, float bulletSpeed, int HP, EPolarity polarity);

    void Update() override;
    void Draw() override;
};