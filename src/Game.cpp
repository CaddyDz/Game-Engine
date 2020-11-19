#include "Game.h"

// Player Constructor
Player::Player()
{
	// pass
}

// Player functions

void Player::checkInput()
{
	// Need to figure out how to get the key pressed from the SFML library.
	switch(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		case S:
			Player::move(sf::Vector2f(0.f, 5.f * GetSpeed()));
			break;
		case Z:
			Player::move(sf::Vector2f(0.f, -5.f * GetSpeed()));
			break;
		case Q:
			Player::move(sf::Vector2f(-5.f * GetSpeed(), 0.f));
		case D:
			Player::move(sf::Vector2f(GetSpeed() * 5.f, 0.f));
		case Space:
			// Pass
		default:
			// Pass
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		Player::move(sf::Vector2f(0.f, 5.f * GetSpeed()));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		Player::move(sf::Vector2f(0.f, -5.f * GetSpeed()));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		Player::move(sf::Vector2f(-5.f * GetSpeed(), 0.f));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		Player::move(sf::Vector2f(GetSpeed() * 5.f, 0.f));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		// Pass
	}
}