#include "raylib-cpp.hpp"
#include "Player.hpp"
#include "Spaceship.hpp"
#include "PolarityHandler.hpp"

Player::Player(){}

Player::Player(raylib::Vector2 position, float speed, float fireRate, float bulletSpeed, int HP, EPolarity polarity):
    Spaceship(position, speed, fireRate, bulletSpeed, HP, polarity)
{}

void Player::Update()
{
    Spaceship::Update();

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        this->Fire(this->GetPosition(), raylib::Vector2(0, -1), this->GetPolarity());
}

void Player::Draw()
{
    Spaceship::Draw();
}