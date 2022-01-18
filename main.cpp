#include "raylib-cpp.hpp"
#include "classes/Player.hpp"
#include "classes/Enemy.hpp"
#include "classes/PolarityHandler.hpp"
#include "raygui.h"

#include <iostream>
#include <string>
#include <vector>

static void InitGame(void);
static void UpdateGame(void);
static void DrawGame(void);

raylib::Window window(650, 1000, "schmup cpp");
raylib::Texture2D shipTextures(raylib::GetWorkingDirectory() + "\\assets\\textures\\ShipTextures.png");
raylib::Texture2D bulletTextures(raylib::GetWorkingDirectory() + "\\assets\\textures\\BulletTextures.png");
raylib::Texture2D ShieldTexture(raylib::GetWorkingDirectory() + "\\assets\\textures\\ShieldTexture.png");
std::vector<raylib::Texture2D> backgroundTextures;

Player player;
Player playerStart(
    raylib::Vector2(GetScreenWidth() / 2, GetScreenHeight() - 150),
    500,
    0.1f,
    1500,
    10,
    GOOD
);

Enemy enemy;
Enemy enemyStart(
    raylib::Vector2(GetScreenWidth()/2, 150),
    400,
    0.3f,
    1500,
    10,
    GOOD
);



int main()
{
    // Initialization
    SetTargetFPS(240);
    InitGame();

    // Main game loop
    while (!window.ShouldClose())
    {
        UpdateGame();
        DrawGame();
    }

    return 0;
}

void InitGame()
{
    player = playerStart;
    player.SetTexture(&shipTextures, raylib::Rectangle(68, 14, 35, 33));
    player.SetScale(2);
    player.SetBulletsTexture(&bulletTextures, raylib::Rectangle(201, 187, 11, 18), player.GetRotation(), player.GetScale());
    player.SetShieldTextures(&ShieldTexture, raylib::Rectangle(0, 0, 50, 50), raylib::Rectangle(0, 50, 50, 50));

    enemy = enemyStart;
    enemy.SetTexture(&shipTextures, raylib::Rectangle(220, 159, 35, 41));
    enemy.SetScale(2);
    enemy.SetRotation(180);
    enemy.SetBulletsTexture(&bulletTextures, raylib::Rectangle(201, 187, 11, 18), enemy.GetRotation(), enemy.GetScale());

    backgroundTextures.push_back(
        raylib::Texture2D(raylib::GetWorkingDirectory() + "\\assets\\textures\\ParallaxBackground\\SpaceBackground.png"));
    backgroundTextures.push_back(
        raylib::Texture2D(raylib::GetWorkingDirectory() + "\\assets\\textures\\ParallaxBackground\\SpaceStars.png"));
    backgroundTextures.push_back(
        raylib::Texture2D(raylib::GetWorkingDirectory() + "\\assets\\textures\\ParallaxBackground\\SpaceFarPlanets.png"));
    /*backgroundTextures.push_back(
        raylib::Texture2D(raylib::GetWorkingDirectory() + "\\assets\\textures\\ParallaxBackground\\SpaceRingPlanets.png"));
    backgroundTextures.push_back(
        raylib::Texture2D(raylib::GetWorkingDirectory() + "\\assets\\textures\\ParallaxBackground\\SpaceBigPlanet.png"));*/
}


void UpdateGame()
{
    player.Update();
    enemy.Update();
    std::vector<Damageable*> enemies = {&enemy};
    player.CheckBulletsCollision(enemies);
    std::vector<Damageable*> players = {&player};
    enemy.CheckBulletsCollision(players);
    enemy.CheckShieldCollision({player.GetShield()});
}

void DrawGame()
{
    BeginDrawing();
    {
        window.ClearBackground(BLACK);

        for (int i = 0; i < (int)backgroundTextures.size(); i++)
        {
            raylib::Rectangle sourceRect = {0, 0, (float)backgroundTextures.at(i).width, (float)backgroundTextures.at(i).height};
            raylib::Rectangle destRect = {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()};
            backgroundTextures.at(i).Draw(sourceRect, destRect);
        }
        
        player.Draw();
        enemy.Draw();
        
        DrawFPS(20, 20);
    }
    EndDrawing();
}