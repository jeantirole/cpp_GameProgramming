#include "Player.h"


Player::Player(sf::Vector2f pos, float size, sf::Color color, float speed)
	: position{pos}, size{size},color{color}, speed{speed}
{
	//积己磊 累己 
	shape.setSize(sf::Vector2f{ size,size });
	shape.setFillColor(color);
}

void Player::Update()
{
	// Update() Body, 累己
	ProcessInput();
	shape.setPosition(position);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}


sf::Vector2f Player::GetPosition() const
{
	return position;
}

void Player::ProcessInput() // 涝仿贸府 
{
	bool dPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	bool aPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	bool wPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	bool sPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

	if (dPressed)
	{
		position.x += 0.05f;
	}
	if (aPressed)
	{
		position.x -= 0.05f;
	}
	if (wPressed)
	{
		position.y -= 0.05f;
	}
	if (sPressed)
	{
		position.y += 0.05;
	}
}