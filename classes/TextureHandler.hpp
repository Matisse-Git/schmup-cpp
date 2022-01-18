#pragma once

#include "raylib-cpp.hpp"

class TextureHandler{
  private:
    raylib::Texture2D* texture;
    raylib::Rectangle spriteRect;
    float scale = 1;
    float rotation = 0;

  protected:
    TextureHandler();

    void DrawTexture(raylib::Vector2 position);
    raylib::Texture2D* GetTexture();

  public:
    void SetTexture(raylib::Texture2D* texture, raylib::Rectangle spriteRect);
    void SetScale(float scale);
    void SetRotation(float rotation);
    raylib::Vector2 GetSpriteSize();
    float GetRotation();
    float GetScale();
};