#include "raylib-cpp.hpp"
#include "Fireable.hpp"
#include "Bullet.hpp"
#include "PolarityHandler.hpp"
#include "Damageable.hpp"

#include <vector>

Fireable::Fireable(){}

Fireable::Fireable(float fireRate, float bulletSpeed)
{
    this->fireRate = fireRate;
    this->bulletSpeed = bulletSpeed;
}

bool Fireable::CheckCanFire()
{
    double timeSinceFired = GetTime() - whenLastFired;

    if (timeSinceFired >= fireRate)
        return true;

    return false;
}

void Fireable::DestroyBullet(Bullet bulletToDestroy)
{
    for (int i = 0; i < (int)this->bullets.size(); i++)
    {
        Bullet* bullet = &this->bullets.at(i);

        if (bullet->GetPosition() == bulletToDestroy.GetPosition())
        {
            this->bullets.erase(this->bullets.begin() + i);
        }
    }
}

void Fireable::Fire(raylib::Vector2 position, raylib::Vector2 direction, EPolarity polarity)
{
    if (CheckCanFire())
    {
        Bullet newBullet(position, this->bulletSpeed, direction, polarity);
        newBullet.SetTexture(this->bulletTexture, this->bulletSpriteRect);
        newBullet.SetScale(this->bulletScale);
        newBullet.SetRotation(this->bulletRotation);
        this->bullets.push_back(newBullet);
        this->whenLastFired = GetTime();
    }
}

void Fireable::UpdateBullets()
{
    for (int i = 0; i < (int)this->bullets.size(); i++)
    {
        Bullet* bullet = &this->bullets.at(i);
        bullet->Update();

        if (bullet->GetPosition().GetY() <= -100)
            this->DestroyBullet(*bullet);
    }
}

void Fireable::DrawBullets()
{
    for (int i = 0; i < (int)this->bullets.size(); i++)
    {
        Bullet* bullet = &this->bullets.at(i);
        bullet->Draw();
    }
}

void Fireable::SetBulletsTexture(raylib::Texture2D* bulletTexture, raylib::Rectangle bulletSpriteRect, float rotation, float scale)
{
    this->bulletTexture = bulletTexture;
    this->bulletSpriteRect = bulletSpriteRect;
    this->bulletRotation = rotation;
    this->bulletScale = scale;
}

void Fireable::CheckBulletsCollision(std::vector<Damageable*> targets)
{
    for (int i = 0; i < (int)this->bullets.size(); i++)
    {
        Bullet* bullet = &this->bullets.at(i);
        for (int j = 0; j < (int)targets.size(); j++)
        {
            Damageable* target = targets.at(i);

            bool targetHit = bullet->CheckCollision(target->GetCollisionRect());
            
            if (targetHit)
            {
                int damageAmount = 1;

                if (bullet->GetPolarity() != target->GetPolarity())
                    damageAmount *= 2;

                target->Damage(damageAmount);
                this->DestroyBullet(*bullet);
            }
        }
    }
}