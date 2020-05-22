#include <ctime>
#include "Game.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
//GameEngine stuff
#pragma region GameEngine
    //GameEngine variables
    int WindowWidth = 960;
    int WindowHeight = 540;
    int FramerateTarget = 60;
    std::string WindowTitle = "Sparta";
    //GameEngine instance
    Engine GameEngine(WindowWidth, WindowHeight, WindowTitle, FramerateTarget); //init GameEngine
#pragma endregion
//Player stuff
#pragma region Player
    std::string playerTexturepath = "assets/textures/dirt.png";
    int playerSpriteWidth = 50;
    int playerSpriteHeight = 50;
    Player man;
    man.InitCharacter(playerTexturepath, playerSpriteWidth, playerSpriteHeight);
    man.SetSpeed(2.f);
    man.setPosition(200.f, 200.f);
    man.SetOriginToBeCenter();
    float manOldPositionX;
    float manOldPositionY;
    float manNewPositionX;
    float manNewPositionY;
#pragma endregion
//Enemies stuf
#pragma region Enemies
    std::string enemyTexturePath = "assets/textures/dirt.png";
    int enemySpriteWidth = 50;
    int enemySpriteHeight = 50;
    Enemy enemy;
    enemy.InitCharacter(enemyTexturePath, enemySpriteWidth, enemySpriteHeight);
    enemy.setPosition(100.f, 100.f);
    enemy.SetOriginToBeCenter();


#pragma endregion
    while (GameEngine.isRunning())
    {
        manOldPositionX = man.getPosition().x;
        manOldPositionY = man.getPosition().y;
        GameEngine.window->clear();
        GameEngine.checkEvents();
        man.checkInput();
        if (GameEngine.checkCollisionY(man, enemy))
        {
            if (GameEngine.checkCollisionUP(man, enemy))
            {
                manNewPositionY = manOldPositionY + GameEngine.checkCollisionDepthY(man, enemy);
            }
            if (GameEngine.checkCollisionDOWN(man, enemy))
            {
                manNewPositionY = manOldPositionY - GameEngine.checkCollisionDepthY(man, enemy);
            }
            man.setPosition(manOldPositionX, manNewPositionY);
        }
        GameEngine.window->draw(man);
        GameEngine.window->draw(enemy);
        GameEngine.window->display();
    }

    return 0;
}