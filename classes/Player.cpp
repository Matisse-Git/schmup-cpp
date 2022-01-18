#include "raylib-cpp.hpp"
#include "Player.hpp"
#include "Spaceship.hpp"
#include "PolarityHandler.hpp"

Player::Player(){}

Player::Player(raylib::Vector2 position, float speed, float fireRate, float bulletSpeed, int HP, EPolarity polarity):
    Spaceship(position, speed, fireRate, bulletSpeed, HP, polarity)
{

}

void Player::Update()
{
    Spaceship::Update();
    this->shield.Update(this->GetPosition(), this->GetPolarity());

    raylib::Vector2 directionToMove(0, 0);
    if (IsKeyDown(KEY_W))
        directionToMove.SetY(-1);
    else if (IsKeyDown(KEY_S))
        directionToMove.SetY(1);
    if (IsKeyDown(KEY_A))
        directionToMove.SetX(-1);
    else if (IsKeyDown(KEY_D))
        directionToMove.SetX(1);
    
    this->Move(directionToMove);

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        this->Fire(raylib::Vector2(this->GetPosition().GetX(), this->GetPosition().GetY() - this->GetSpriteSize().GetY()/2), raylib::Vector2(0, -1), this->GetPolarity());

    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        this->TogglePolarity();
}

void Player::Draw()
{
    Spaceship::Draw();
    this->shield.Draw();
}

Shield Player::GetShield()
{
    return this->shield;
}

void Player::SetShieldTextures(raylib::Texture2D* shieldTexture, raylib::Rectangle goodShieldSpriteRect, raylib::Rectangle evilShieldSpriteRect)
{
    this->shield = Shield(this->GetPosition(), goodShieldSpriteRect, evilShieldSpriteRect, this->GetPolarity());

    raylib::Rectangle shieldSpriteRectToUse;
    if (this->GetPolarity() == GOOD)
        shieldSpriteRectToUse = goodShieldSpriteRect;
    else
        shieldSpriteRectToUse = evilShieldSpriteRect;

    this->shield.SetTexture(shieldTexture, shieldSpriteRectToUse);
    this->shield.SetRotation(this->GetRotation());
    this->shield.SetScale(this->GetScale());
}