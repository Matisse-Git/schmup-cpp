#include "raylib-cpp.hpp"
#include "TextureHandler.hpp"

TextureHandler::TextureHandler(){}

void TextureHandler::SetTexture(raylib::Texture2D* texture, raylib::Rectangle spriteRect)
{
    this->texture = texture;
    this->spriteRect = spriteRect;
}

void TextureHandler::SetScale(float scale)
{
    if (scale > 0)
        this->scale = scale;
    else 
        this->scale = 1;
}

void TextureHandler::SetRotation(float rotation)
{
    if (rotation <= 360 && rotation >= -360)
        this->rotation = rotation;
    else
        this->rotation = 0;
}

raylib::Vector2 TextureHandler::GetSpriteSize()
{
    raylib::Vector2 spriteSize(this->spriteRect.GetWidth() * this->scale, this->spriteRect.GetHeight() * this->scale);
    return spriteSize;
}

float TextureHandler::GetScale()
{
    return this->scale;
}

float TextureHandler::GetRotation()
{
    return this->rotation;
}

void TextureHandler::DrawTexture(raylib::Vector2 position)
{
    raylib::Rectangle destRect(position, this->GetSpriteSize());
    raylib::Vector2 origin(this->GetSpriteSize().GetX()/2, this->GetSpriteSize().GetY()/2);
    
    this->texture->Draw(this->spriteRect, destRect, origin, this->rotation);
}