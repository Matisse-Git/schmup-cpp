#include "raylib-cpp.hpp"
#include "Spaceship.hpp"
#include "Moveable.hpp"
#include "Fireable.hpp"
#include "Damageable.hpp"
#include "PolarityHandler.hpp"

Spaceship::Spaceship(){}

Spaceship::Spaceship(raylib::Vector2 position, float speed, float fireRate, float bulletSpeed, int HP, EPolarity polarity):
    Moveable(position, speed),
    Fireable(fireRate, bulletSpeed),
    Damageable(HP, polarity, raylib::Rectangle(this->GetPosition(), this->GetSpriteSize()))
{

}

void Spaceship::Update()
{
    this->UpdateCollisionRect(raylib::Rectangle(this->GetPosition(), this->GetSpriteSize()));
    this->UpdateBullets();
}

void Spaceship::Draw()
{
    this->DrawBullets();
    this->DrawTexture(this->GetPosition());
    this->DrawCollisionRect(RED);
}