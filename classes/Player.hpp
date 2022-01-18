#pragma once

#include "raylib-cpp.hpp"
#include "Spaceship.hpp"
#include "PolarityHandler.hpp"
#include "Shield.hpp"

class Player: public Spaceship
{
  Shield shield;

  public:
    Player();
    Player(raylib::Vector2 position, float speed, float fireRate, float bulletSpeed, int HP, EPolarity polarity);

    Shield GetShield();
    void SetShieldTextures(raylib::Texture2D* shieldTexture, raylib::Rectangle goodShieldSpriteRect, raylib::Rectangle evilShieldSpriteRect);
    void Update() override;
    void Draw() override;
};