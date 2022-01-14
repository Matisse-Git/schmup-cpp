#pragma once

#include "raylib-cpp.hpp"
#include "Spaceship.hpp"
#include "PolarityHandler.hpp"

class Player: public Spaceship
{
  public:
    Player();
    Player(raylib::Vector2 position, float speed, float fireRate, float bulletSpeed, int HP, EPolarity polarity);

    void Update() override;
    void Draw() override;
};