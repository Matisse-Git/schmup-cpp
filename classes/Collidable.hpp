#pragma once

#include "raylib-cpp.hpp"

class Collidable
{
  private:
    raylib::Rectangle collisionRect;

  protected:
    Collidable();
    Collidable(raylib::Rectangle collisionRect);

    void UpdateCollisionRect(raylib::Rectangle collisionRect);
    void DrawCollisionRect(raylib::Color color);

  public:
    bool CheckCollision(raylib::Rectangle other);
    raylib::Rectangle GetCollisionRect();

};