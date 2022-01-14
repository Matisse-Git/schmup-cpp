#include "raylib-cpp.hpp"
#include "Stationary.hpp"
#include "TextureHandler.hpp"

Stationary::Stationary(){}

Stationary::Stationary(raylib::Vector2 position)
{
    this->position = position;
}

void Stationary::SetPosition(raylib::Vector2 position)
{
    this->position = position;
}

raylib::Vector2 Stationary::GetPosition()
{
    return this->position;
}