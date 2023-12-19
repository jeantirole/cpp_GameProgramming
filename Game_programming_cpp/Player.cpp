#include "Player.h"


Player::Player(sf::Vector2f pos, float size, sf::Color color, float speed)
	: position{pos}, size{size},color{color}, speed{speed}
{
	//������ �ۼ� 
	shape.setSize(sf::Vector2f{ size,size });
	shape.setFillColor(color);
}

void Player::Update()
{
	// Update() Body, �ۼ�
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

void Player::ProcessInput() // �Է�ó�� 
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