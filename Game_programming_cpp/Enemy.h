#pragma once
#include <SFML/Graphics.hpp>
#include <../Game_programming_cpp/Player.h>



class Enemy
{
public:
	Enemy(const sf::Vector2f pos, float size, sf::Color color, float speed, const Player* playerRef);
	Enemy();

	void Update(); // �÷��̾��� ���� 

	void Draw(sf::RenderWindow& window); // �÷��̾� �׸��� 
	
	void UpdatePosition();

	sf::Vector2f GetPosition() const;

private:
	sf::Vector2f position; // ��ġ 
	float speed;
	const Player* playerRef; //player ! 
	float size;
	sf::Color color;
	sf::CircleShape shape;
	 
};
//
//class Enemy
//{
//public:
//	// constructor 
//	Enemy(const sf::Vector2f pos, float size, sf::Color color, float speed,
//		const Player* player);
//	Enemy(); // ���ڸ� �ȹ޴� �⺻ ������ => �� �ʿ�����? 
//
//	void Update(); 
//
//	void Draw(sf::RenderWindow& window); // drawing 
//
//	sf::Vector2f GetPosition();
//
//private:
//	void UpdatePosition();
//
//
//private:
//	sf::Vector2f position; // ��ġ 
//	float speed;
//	const Player* playerRef;
//	
//	float size;
//	sf::Color color;
//	sf::CircleShape shape;
//	
//};