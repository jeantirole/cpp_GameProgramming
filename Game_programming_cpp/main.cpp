#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG 
#define DBG_NEW new (_NORMAL_BLOCK, __FILE__,__LINE__)
#else
#define DBG_NEW new
#endif

#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>


// Eric edited 2023-12-17

void UpdatePlayerPosition(sf::Vector2f& PlayerPosition)
{
	bool dPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	bool aPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	bool wPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	bool sPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

	if (dPressed)
	{
		PlayerPosition.x += 0.05f;
	}
	if (aPressed)
	{
		PlayerPosition.x -= 0.05f;
	}
	if (wPressed)
	{
		PlayerPosition.y -= 0.05f;
	}
	if (sPressed)
	{
		PlayerPosition.y += 0.05;
	}
}

void UpdateEnemyPosition(float enemySpeed, int enemyCount, sf::Vector2f* EnemyPositions,
	sf::Vector2f PlayerPosition)
{
	for (int i = 0; i < enemyCount; i++)
	{
		float enemyToPlayerX = PlayerPosition.x - EnemyPositions[i].x;
		float enemyToPlayerY = PlayerPosition.y - EnemyPositions[i].y;
		
		float length = sqrt(enemyToPlayerX * enemyToPlayerX + enemyToPlayerX * enemyToPlayerY);
		
		enemyToPlayerX /= length; // 길이 1 짜리 vector x,y 
		enemyToPlayerY /= length;

		EnemyPositions[i].x += enemyToPlayerX * enemySpeed;
		EnemyPositions[i].y += enemyToPlayerY * enemySpeed;

	}
}




int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int* intArray = new int[10];
	intArray[0] = 10;

	int screenWidth = 800;
	int screenHeight = 450;

	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "GAME");

	// Player 
	sf::RectangleShape player;
	float rectWidth = 20.0f;
	float rectHeight = 20.0f;
	//float rectXPosition = 50.0f;
	//float rectYPosition = 50.0f;
	sf::Vector2f PlayerPosition = sf::Vector2f{ 50.0f, 50.0f };
	
	player.setSize(sf::Vector2f(rectWidth, rectHeight));
	player.setPosition(PlayerPosition);
	player.setFillColor(sf::Color::Red);


	// Enemies 
	const int enemyCount = 10;
	//float enemyPositionX[enemyCount]; // heap 메모리로 변경 
	//float enemyPositionY[enemyCount];
	//float* enemyPositionX = new float[enemyCount]; // player 는 하나지만, enemy 는 다수이므로, 동적할당 배열을 사용
	//float* enemyPositionY = new float[enemyCount]; // player 에서 했던 것처럼. sf::Vector2f 객체를 동적할당 배열로 활용
	const float enemySize = 10.0f;
	const float enemySpeed = 0.010f;
	sf::Vector2f* EnemyPositions = new sf::Vector2f[enemyCount];
	const sf::Color enemyColor = sf::Color::Cyan;
	sf::CircleShape enemies[enemyCount];


	for (int i = 0; i < enemySize; i++)
	{
		EnemyPositions[i].x = screenWidth - 100;
		EnemyPositions[i].y = rand() % screenHeight;
		
		enemies[i] = sf::CircleShape{ enemySize };
		enemies[i].setFillColor(enemyColor);
		enemies[i].setOutlineColor(sf::Color::Red);
		enemies[i].setOutlineThickness(1.0f);
	}

	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	
		// 플레이어 이동 로직 
		UpdatePlayerPosition(PlayerPosition);
		player.setPosition(PlayerPosition);

		// 적 이동 로직 
		UpdateEnemyPosition(enemySpeed,enemyCount, EnemyPositions,
			PlayerPosition);


		for (int i = 0; i < enemyCount; i++)
		{
			enemies[i].setPosition(sf::Vector2f{ EnemyPositions[i].x,EnemyPositions[i].y });

		}
		
		window.clear();
		window.draw(player);
		for (int i = 0; i < enemyCount; i++)
		{
			window.draw(enemies[i]);
		}


		window.display();

	}
	
	//delete[] enemyPositionX;
	//delete[] enemyPositionY;

	return 0;
	}
	


