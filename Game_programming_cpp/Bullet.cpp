#include "Bullet.h"

Bullet::Bullet(const sf::Vector2f& position, const sf::Vector2f& direction, float size, const sf::Color& color, float speed)
	: position{position}, direction{direction}, size{size},
	color{color},speed{speed}
{
	shape = sf::CircleShape{ size };
	shape.setFillColor(color);
}

void Bullet::Update(float dt)
{
	UpdatePosition(dt);
	shape.setPosition(position);
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void Bullet::UpdatePosition(float dt)
{
	position += direction * speed * dt;
}
