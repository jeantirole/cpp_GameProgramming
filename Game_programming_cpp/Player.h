#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(sf::Vector2f pos, float size, sf::Color color, float speed);
	
	void Update(float dt); // �÷��̾��� ���� 
	
	void Draw(sf::RenderWindow& window); // �÷��̾� �׸��� 

	sf::Vector2f GetPosition() const;

private:
	void ProcessInput( float dt); // Ű�����Է�ó�� 


private:
	sf::Vector2f position; //��ġ 
	float speed;

	sf::RectangleShape shape; //���
	float size; //ũ�� 
	sf::Color color; //�� 
	
	
};

