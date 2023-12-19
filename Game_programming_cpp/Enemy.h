#pragma once
#include <SFML/Graphics.hpp>
#include <../Game_programming_cpp/Player.h>



class Enemy
{
public:
	Enemy(const sf::Vector2f pos, float size, sf::Color color, float speed, const Player* playerRef);
	Enemy();

	void Update(); // 플레이어의 동작 

	void Draw(sf::RenderWindow& window); // 플레이어 그리기 
	
	void UpdatePosition();

	sf::Vector2f GetPosition() const;

private:
	sf::Vector2f position; // 위치 
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
//	Enemy(); // 인자를 안받는 기본 생성자 => 왜 필요하지? 
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
//	sf::Vector2f position; // 위치 
//	float speed;
//	const Player* playerRef;
//	
//	float size;
//	sf::Color color;
//	sf::CircleShape shape;
//	
//};