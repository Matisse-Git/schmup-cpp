#include "raylib-cpp.hpp"
#include "Bullet.hpp"
#include "PolarityHandler.hpp"
#include "Collidable.hpp"
#include "Moveable.hpp"

Bullet::Bullet(raylib::Vector2 position, float speed, raylib::Vector2 direction, EPolarity polarity):
    Moveable(position, speed),
    Collidable(raylib::Rectangle(position, this->GetSpriteSize())),
    PolarityHandler(polarity)
{
    this->direction = direction;
}

void Bullet::Update()
{
    this->Move(this->direction);
    this->UpdateCollisionRect(this->GetPosition());
}

void Bullet::Draw()
{
    this->DrawTexture(this->GetPosition());
    this->DrawCollisionRect(RED);
}