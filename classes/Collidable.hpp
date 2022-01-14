#pragma once

#include "raylib-cpp.hpp"

class Collidable
{
  private:
    raylib::Rectangle collisionRect;

  protected:
    Collidable();
    Collidable(raylib::Rectangle collisionRect);

    void UpdateCollisionRect(raylib::Vector2 position);
    void DrawCollisionRect(raylib::Color color);

  public:
    bool CheckCollision(raylib::Rectangle other);
    raylib::Rectangle GetCollisionRect();

};