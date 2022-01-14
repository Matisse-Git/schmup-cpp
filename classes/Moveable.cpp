#include "raylib-cpp.hpp"
#include "Moveable.hpp"
#include "Stationary.hpp"

Moveable::Moveable(){}

Moveable::Moveable(raylib::Vector2 position, float speed): Stationary(position)
{
    this->speed = speed;
}

void Moveable::Move(raylib::Vector2 direction)
{
    raylib::Vector2 moveAmount(direction.GetX() * this->speed * GetFrameTime(), direction.GetY() * this->speed * GetFrameTime());
    raylib::Vector2 newPos = this->GetPosition() + moveAmount;
    this->SetPosition(newPos);
}

void Moveable::MoveTo(raylib::Vector2 position)
{
    //this can later be configured to slowly go to the position
    this->SetPosition(position);
}