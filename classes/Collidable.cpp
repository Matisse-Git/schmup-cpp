#include "raylib-cpp.hpp"
#include "Collidable.hpp"

Collidable::Collidable(){}

Collidable::Collidable(raylib::Rectangle collisionRect)
{
    raylib::Vector2 adjustedPos;
    adjustedPos.SetX(collisionRect.GetX() - collisionRect.GetWidth()/2);
    adjustedPos.SetY(collisionRect.GetY() - collisionRect.GetHeight()/2);
    this->collisionRect = raylib::Rectangle(adjustedPos, collisionRect.GetSize());
}

bool Collidable::CheckCollision(raylib::Rectangle other)
{
    return this->collisionRect.CheckCollision(other);
}

void Collidable::UpdateCollisionRect(raylib::Rectangle collisionRect)
{
    raylib::Rectangle adjustedRect(0,0,0,0);
    adjustedRect.SetX(collisionRect.GetX() - this->collisionRect.GetWidth()/2);
    adjustedRect.SetY(collisionRect.GetY() - this->collisionRect.GetHeight()/2);
    adjustedRect.SetSize(collisionRect.GetSize());
    this->collisionRect = adjustedRect;
}

raylib::Rectangle Collidable::GetCollisionRect()
{
    return this->collisionRect;
}

void Collidable::DrawCollisionRect(raylib::Color color)
{
    color.DrawRectangleLines(this->collisionRect, 2);
}