#include "raylib-cpp.hpp"
#include "Enemy.hpp"
#include "Spaceship.hpp"
#include "PolarityHandler.hpp"

Enemy::Enemy(){}

Enemy::Enemy(raylib::Vector2 position, float speed, float fireRate, float bulletSpeed, int HP, EPolarity polarity):
    Spaceship(position, speed, fireRate, bulletSpeed, HP, polarity)
{
    this->direction = raylib::Vector2(1, 0);
}

void Enemy::Update()
{
    Spaceship::Update();

    this->Fire(raylib::Vector2(this->GetPosition().GetX(), this->GetPosition().GetY() + this->GetSpriteSize().GetY()/2), raylib::Vector2(0, 1), this->GetPolarity());

    if ((this->GetCollisionRect().GetX() + this->GetCollisionRect().GetWidth() >= GetScreenWidth() && this->direction.GetX() != -1) || (this->GetCollisionRect().GetX() <= 0 && this->direction.GetX() != 1))
        this->direction.x *= -1;
    
    this->Move(this->direction);
}

void Enemy::Draw()
{
    Spaceship::Draw();
}