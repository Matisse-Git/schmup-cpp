#include "raylib-cpp.hpp"
#include "Shield.hpp"
#include "Collidable.hpp"
#include "PolarityHandler.hpp"
#include "Stationary.hpp"

#include <iostream>

Shield::Shield(){}

Shield::Shield(raylib::Vector2 position, raylib::Rectangle goodSpriteRect, raylib::Rectangle evilSpriteRect, EPolarity polarity):
    Collidable({0, 0, 0, 0}),
    PolarityHandler(polarity),
    Stationary(position)
{
    this->goodSpriteRect = goodSpriteRect;
    this->evilSpriteRect = evilSpriteRect;
}

void Shield::Update(raylib::Vector2 position, EPolarity polarity)
{
    this->SetPosition(position);
    this->UpdateCollisionRect(raylib::Rectangle(position, this->GetSpriteSize()));
    this->SetPolarity(polarity);

    raylib::Rectangle shieldSpriteRectToUse;
    if (this->GetPolarity() == GOOD)
        shieldSpriteRectToUse = this->goodSpriteRect;
    else
        shieldSpriteRectToUse = this->evilSpriteRect;

    this->SetTexture(this->GetTexture(), shieldSpriteRectToUse);
}

void Shield::Draw()
{
    this->DrawTexture(this->GetPosition());
    this->DrawCollisionRect(RED);
}