#include "raylib-cpp.hpp"
#include "Damageable.hpp"
#include "Collidable.hpp"
#include "PolarityHandler.hpp"

#include <string>

Damageable::Damageable(){}

Damageable::Damageable(int HP, EPolarity polarity, raylib::Rectangle collisionRect):
    Collidable(collisionRect),
    PolarityHandler(polarity)
{
    this->HP = HP;
}

void Damageable::Damage(int amount)
{
    this->HP -= amount;
    if (this->HP <= 0)
        this->isDead = true;
}

bool Damageable::IsDead()
{
    return this->isDead;
}

void Damageable::DrawHP(raylib::Vector2 position, raylib::Color color, float fontSize)
{
    color.DrawText("HP: " + std::to_string(this->HP), position.GetX(), position.GetY(), fontSize);
}