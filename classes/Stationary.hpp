#pragma once

#include "raylib-cpp.hpp"
#include "TextureHandler.hpp"

class Stationary: public TextureHandler
{
  private:
    raylib::Vector2 position;

  protected:
    Stationary();
    Stationary(raylib::Vector2 position);

    void SetPosition(raylib::Vector2 position);

  public:
    raylib::Vector2 GetPosition();
};