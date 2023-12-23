#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet(const sf::Vector2f& position, const sf::Vector2f& direction,
		float size, const sf::Color& color, float speed);


	void Update(float dt); // 외부에서 접근할 때 Update로 접근하고, Update 는 UpdatePosition을 부르게 한번 감쌌음
	
	void Draw(sf::RenderWindow& window);
	sf::Vector2f GetPosition() const { return position; }; // in-line으로 헤더에서 간단하게 구현하였음 

private:
	void UpdatePosition(float dt);

private:
	sf::Vector2f position;
	sf::Vector2f direction;
	float speed;

	sf::CircleShape shape;
	float size;
	sf::Color color;

};