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
        this->bullets.push_back(Bullet(position, this->bulletSpeed, direction, polarity));
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
    for (int i = 0; i < (int)this->bullets.size(); i++)
    {
        Bullet* bullet = &this->bullets.at(i);
        bullet->SetTexture(bulletTexture, bulletSpriteRect);
        bullet->SetScale(scale);
        bullet->SetRotation(rotation);
    }
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