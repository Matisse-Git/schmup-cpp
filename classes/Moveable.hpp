#pragma once

#include "raylib-cpp.hpp"
#include "Stationary.hpp"

class Moveable: public Stationary
{
  private:
    float speed;

  protected:
    Moveable();
    Moveable(raylib::Vector2 position, float speed);

    void Move(raylib::Vector2 direction);
    void MoveTo(raylib::Vector2 position);
};