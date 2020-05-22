#include "Engine.h"

//Engine Constructor and Deconstructor
Engine::Engine(int width, int height, std::string title, int framerateTarget)
{
    //init private data members
    m_windowWidth = width;
    m_windowHeight = height;
    m_windowTitle = title;
    //init the window pointer before using it in the init window
    this->window = nullptr;
    //init widow
    this->window = new sf::RenderWindow(sf::VideoMode(m_windowWidth, m_windowHeight), m_windowTitle, sf::Style::Default);
    this->window->setFramerateLimit(framerateTarget);
}

Engine::~Engine()
{
    //delete the pointer or whatever its called to prevent memory leaks
    delete this->window;
}

//Engine Public Functions

bool Engine::isRunning()
{
    return this->window->isOpen();
}

void Engine::checkEvents()
{
    while (this->window->pollEvent(this->ev))
    {
        //Close the window
        if (ev.key.code == sf::Keyboard::Escape)
        {
            this->window->close();
            break;
        }
        else if (ev.type == sf::Event::Closed)
        {
            this->window->close();
            break;
        }
        //other stuff
    }
}

void Engine::playIntro()
{
    std::string fontPath = "assets/fonts/Montserrat-Regular.ttf";
    std::string audiotPath = "assets/audio/intro.wav";
    std::string text = "achieved with Sparta Engine";

    SpartaText intro(fontPath, 24, sf::Color::White, text);
    SpartaAudio introSoundFX(audiotPath);
    introSoundFX.play();

    double duration = 5000;
    clock_t startTime = clock();

    while ((clock() - startTime) < duration)
    {
        Engine::window->clear();
        Engine::checkEvents();
        Engine::window->draw(intro);
        Engine::window->display();
        Engine::window->clear();
    }
}

bool Engine::checkCollision(sf::Sprite object1, sf::Sprite object2)
{
    return checkCollisionX(object1, object2) && checkCollisionY(object1, object2);
}

bool Engine::checkCollisionY(sf::Sprite object1, sf::Sprite object2)
{
    if (
        object1.getGlobalBounds().top + object1.getGlobalBounds().height >= object2.getGlobalBounds().top &&
        object2.getGlobalBounds().top + object2.getGlobalBounds().height >= object1.getGlobalBounds().top)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Engine::checkCollisionX(sf::Sprite object1, sf::Sprite object2)
{
    if (
        object1.getGlobalBounds().left + object1.getGlobalBounds().width >= object2.getGlobalBounds().left &&
        object2.getGlobalBounds().left + object2.getGlobalBounds().width >= object1.getGlobalBounds().left)
    {
        return true;
    }
    else
    {
        return false;
    }
}


float Engine::checkCollisionDepthX(sf::Sprite object1, sf::Sprite object2)
{
    float x;
    if (Engine::checkCollisionRIGHT(object1, object2))
    {
        x = object1.getGlobalBounds().left - (object2.getGlobalBounds().left + object2.getGlobalBounds().width);
    }
    if (Engine::checkCollisionLEFT(object1, object2))
    {
        x = (object1.getGlobalBounds().left + object1.getGlobalBounds().width) - (object2.getGlobalBounds().left);
    }

    return abs(x);    
}
float Engine::checkCollisionDepthY(sf::Sprite object1, sf::Sprite object2)
{
    float y;
    if (Engine::checkCollisionUP(object1, object2))
    {
        y = object1.getGlobalBounds().top - (object2.getGlobalBounds().top + object2.getGlobalBounds().height);
    }
    if (Engine::checkCollisionDOWN(object1, object2))
    {
        y = (object1.getGlobalBounds().top + object1.getGlobalBounds().height) - object2.getGlobalBounds().top;
    }

    return abs(y);
}
bool Engine::checkCollisionUP(sf::Sprite object1, sf::Sprite object2)
{
    
        if (
            object1.getPosition().y > object2.getPosition().y
        )
        {
            return true;
        }
    
    else
    {
        return false;
    }
}

bool Engine::checkCollisionDOWN(sf::Sprite object1, sf::Sprite object2)
{
    
        if (
            object1.getPosition().y < object2.getPosition().y
        )
        {
            return true;
        }
    
    else
    {
        return false;
    }
}

bool Engine::checkCollisionLEFT(sf::Sprite object1, sf::Sprite object2)
{
    
        if (
            object1.getPosition().x > object2.getPosition().x
        )
        {
            return true;
        }
    
    else
    {
        return false;
    }
}

bool Engine::checkCollisionRIGHT(sf::Sprite object1, sf::Sprite object2)
{
    
        if (
            object1.getPosition().x < object2.getPosition().x
        )
        {
            return true;
        }
    
    else
    {
        return false;
    }
}
/*  for reference just in case
// Collision x-axis?
    bool collisionX = one.Position.x + one.Size.x >= two.Position.x &&
        two.Position.x + two.Size.x >= one.Position.x;
    // Collision y-axis?
    bool collisionY = one.Position.y + one.Size.y >= two.Position.y &&
        two.Position.y + two.Size.y >= one.Position.y;
    // Collision only if on both axes
*/

//SpartaText Constructor
SpartaText::SpartaText(std::string fontPath, int fontSize, sf::Color fontColor, std::string text)
{
    m_SpartaFont.loadFromFile(fontPath);
    setFont(m_SpartaFont);
    setCharacterSize(fontSize);
    setFillColor(fontColor);
    setString(text);
}

//SpartaAudio Constructor
SpartaAudio::SpartaAudio(std::string audioPath)
{
    buffer.loadFromFile(audioPath);
    setBuffer(buffer);
}

//Character Class Constructor
Character::Character()
{
    m_speed = 0.f;
    m_CharacterX = 0.f;
    m_CharacterY = 0.f;
    m_SpriteWidth = 0;
    m_SpriteHeight = 0;
}

void Character::InitCharacter(std::string texturePath, int width, int height)
{
    m_SpriteWidth = width;
    m_SpriteHeight = height;
    m_CharacterTexture.loadFromFile(texturePath);
    setTexture(m_CharacterTexture);
    setTextureRect(sf::IntRect(m_CharacterX, m_CharacterY, m_SpriteWidth, m_SpriteHeight));
}

//Character Class Functions
void Character::SetSpeed(float speed)
{
    m_speed = speed;
}

void Character::SetX(float x)
{
    m_CharacterX = x;
    Character::setPosition(x, m_CharacterY);
}

void Character::SetY(float y)
{
    m_CharacterY = y;
    Character::setPosition(m_CharacterX, y);
}

void Character::SetSpriteWidth(int width)
{
    m_SpriteWidth = width;
}

void Character::SetSpriteHeight(int height)
{
    m_SpriteHeight = height;
}

float Character::GetSpeed()
{
    return m_speed;
}

float Character::GetX()
{
    return getPosition().x;
}

float Character::GetY()
{
    return getPosition().y;
}

int Character::GetSpriteWidth()
{
    return Character::getGlobalBounds().width;
}

int Character::GetSpriteHeight()
{
    return Character::getGlobalBounds().height;
}

void Character::SetOriginToBeCenter()
{
    setOrigin((float)getGlobalBounds().width / 2.f, (float)getGlobalBounds().height / 2.f);
}

//Background Class Constructor
Background::Background()
{
    m_SpriteWidth = 0;
    m_SpriteHeight = 0;
}

//Background Class Functions
void Background::InitBackground(std::string texturePath, int width, int height, bool repeated, bool smooth)
{
    m_SpriteWidth = width;
    m_SpriteHeight = height;
    m_BackgroundTexture.loadFromFile(texturePath);
    m_BackgroundTexture.setRepeated(repeated);
    m_BackgroundTexture.setSmooth(smooth);
    setTexture(m_BackgroundTexture);
    setTextureRect(sf::IntRect(0, 0, m_SpriteWidth, m_SpriteHeight));
}

void Background::SetSpriteWidth(int width)
{
    m_SpriteWidth = width;
}

void Background::SetSpriteHeight(int height)
{
    m_SpriteHeight = height;
}

int Background::GetSpriteWidth()
{
    return Background::getGlobalBounds().width;
}

int Background::GetSpriteHeight()
{
    return Background::getGlobalBounds().height;
}


int Background::GetSpriteTextureWidth()
{
    return m_BackgroundTexture.getSize().x;
}

int Background::GetSpriteTextureHeight()
{
    return  m_BackgroundTexture.getSize().y;
}
