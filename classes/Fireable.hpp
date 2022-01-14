#pragma once

#include "raylib-cpp.hpp"
#include "Bullet.hpp"
#include "PolarityHandler.hpp"
#include "Damageable.hpp"

//class Damageable;

#include <vector>

class Fireable
{
  private:
    double whenLastFired = 0;
    float fireRate;
    float bulletSpeed;
    std::vector<Bullet> bullets;
    raylib::Texture2D* bulletTexture;
    raylib::Rectangle bulletSpriteRect;
    float bulletRotation;
    float bulletScale;

    bool CheckCanFire();
    void DestroyBullet(Bullet bulletToDestroy);

  protected:
    Fireable();
    Fireable(float fireRate, float bulletSpeed);

    void Fire(raylib::Vector2 position, raylib::Vector2 direction, EPolarity polarity);
    void UpdateBullets();
    void DrawBullets();

  public:
    void SetBulletsTexture(raylib::Texture2D* bulletTexture, raylib::Rectangle bulletSpriteRect, float rotation, float scale);
    void CheckBulletsCollision(std::vector<Damageable*> targets);
};