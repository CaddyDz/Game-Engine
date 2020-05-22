#pragma once

//Headers
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <Windows.h>
#include <cstdlib>

//Main Game Engine Class
class Engine
{
private:
    //Private Variables
    //my stuff
    int m_windowWidth;
    int m_windowHeight;
    std::string m_windowTitle;
    

public:
    //sfml stuff
    sf::RenderWindow *window;
    sf::Event ev;

    enum class Direction
    {
        UP = 17,
        DOWN,
        LEFT,
        RIGHT,
        NONE
    };

public:
    //Constructor and Deconstructor
    Engine(int width, int height, std::string title, int framerateTarget);
    virtual ~Engine();

    //Public Functions
    bool isRunning();
    void checkEvents();
    void playIntro();
    bool checkCollision(sf::Sprite object1, sf::Sprite object2);
    bool checkCollisionX(sf::Sprite object1, sf::Sprite object2);
    bool checkCollisionY(sf::Sprite object1, sf::Sprite object2);
    float checkCollisionDepthX(sf::Sprite object1, sf::Sprite object2);
    float checkCollisionDepthY(sf::Sprite object1, sf::Sprite object2);
    bool checkCollisionUP(sf::Sprite object1, sf::Sprite object2);
    bool checkCollisionDOWN(sf::Sprite object1, sf::Sprite object2);
    bool checkCollisionLEFT(sf::Sprite object1, sf::Sprite object2);
    bool checkCollisionRIGHT(sf::Sprite object1, sf::Sprite object2);
};

//SpartaText Class
class SpartaText : public sf::Text
{
private:
    sf::Font m_SpartaFont;

public:
    //SpartaText Functions
    SpartaText(std::string fontPath, int fontSize, sf::Color fontColor, std::string text);
};

//SpartaAudio
class SpartaAudio : public sf::Sound
{
private:
    sf::SoundBuffer buffer;

public:
    SpartaAudio(std::string audioPath);
};

//SpartaCharacter Class
class Character : public sf::Sprite
{
private:
    //my stuff
    float m_speed;
    float m_CharacterX;
    float m_CharacterY;
    int m_SpriteWidth;
    int m_SpriteHeight;
    //sfml related stuff
    sf::Texture m_CharacterTexture;

public:
    Character();
    void InitCharacter(std::string texturePath, int width, int height);
    void SetSpeed(float speed);
    void SetX(float x);
    void SetY(float y);
    void SetSpriteWidth(int width);
    void SetSpriteHeight(int height);
    float GetSpeed();
    float GetX();
    float GetY();
    int GetSpriteWidth();
    int GetSpriteHeight();
    void SetOriginToBeCenter();
};

//SpartaBackground Class
class Background : public sf::Sprite
{
private:
    //my stuff
    int m_SpriteWidth;
    int m_SpriteHeight;
    //sfml related stuff
    sf::Texture m_BackgroundTexture;

public:
    Background();
    void InitBackground(std::string texturePath, int width, int height, bool repeated, bool smooth);
    void SetSpriteWidth(int width);
    void SetSpriteHeight(int height);
    int GetSpriteWidth();
    int GetSpriteHeight();
    int GetSpriteTextureWidth();
    int GetSpriteTextureHeight();
};