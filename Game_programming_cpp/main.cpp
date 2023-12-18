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
#include <..\Game_programming_cpp\Player.h>

// Eric edited 2023-12-17 // ~_ ~ // 

void UpdateEnemyPosition(float enemySpeed, int enemyCount, sf::Vector2f* EnemyPositions,
	sf::Vector2f PlayerPosition)
{
	for (int i = 0; i < enemyCount; i++)
	{
		float enemyToPlayerX = PlayerPosition.x - EnemyPositions[i].x;
		float enemyToPlayerY = PlayerPosition.y - EnemyPositions[i].y;
		
		float length = sqrt(enemyToPlayerX * enemyToPlayerX + enemyToPlayerX * enemyToPlayerY);
		
		enemyToPlayerX /= length; // ���� 1 ¥�� vector x,y 
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
	Player player{ sf::Vector2f{50.0f, 50.0f},
				20.0f,
				sf::Color::Red,
				0.05f };
	
	//sf::RectangleShape player;
	//float rectWidth = 20.0f;
	//float rectHeight = 20.0f;
	////float rectXPosition = 50.0f;
	////float rectYPosition = 50.0f;
	//sf::Vector2f PlayerPosition = sf::Vector2f{ 50.0f, 50.0f }; // location
	//
	//player.setSize(sf::Vector2f(rectWidth, rectHeight)); // size
	//player.setPosition(PlayerPosition); // initial position
	//player.setFillColor(sf::Color::Red); //color 


	// Enemies 
	const int enemyCount = 10;
	//float enemyPositionX[enemyCount]; // heap �޸𸮷� ���� 
	//float enemyPositionY[enemyCount];
	//float* enemyPositionX = new float[enemyCount]; // player �� �ϳ�����, enemy �� �ټ��̹Ƿ�, �����Ҵ� �迭�� ���
	//float* enemyPositionY = new float[enemyCount]; // player ���� �ߴ� ��ó��. sf::Vector2f ��ü�� �����Ҵ� �迭�� Ȱ��
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
	
		// �÷��̾� �̵� ���� 
		player.Update(); // key press and initial location set 



		// �� �̵� ���� 
		UpdateEnemyPosition(enemySpeed,enemyCount, EnemyPositions,player.GetPosition() );


		for (int i = 0; i < enemyCount; i++)
		{
			enemies[i].setPosition(sf::Vector2f{ EnemyPositions[i].x,EnemyPositions[i].y });

		}
		
		window.clear();
		player.Draw(window);
		//window.draw(player); // �÷��̾ �׸��� ���
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
	


