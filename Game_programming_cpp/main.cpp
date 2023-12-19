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
#include <..\Game_programming_cpp\Enemy.h>

// Eric edited 2023-12-17 // ~_ ~ // 


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
	

	// Enemies 
	const int enemyCount = 10;
	Enemy* enemies = new Enemy[enemyCount]; //클래스의 동적할당 
	for (int i = 0; i < enemyCount; i++)
	{
		float enemyRandomX = screenWidth - 100;
		float enemyRandomY = rand() % screenHeight;
		sf::Vector2f enemyPos{ enemyRandomX,enemyRandomY };

		enemies[i] = Enemy{ enemyPos,10.0f,sf::Color::Cyan,0.05f,&player }; // player 의 주소값 넣는부분 ! 가장중요 ! @!@!@!@!@!@
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
		player.Update(); // key press and initial location set 


		// 적 이동 로직 
		for (int i = 0; i < enemyCount; i++)
		{
			enemies[i].Update();

		}
		
		window.clear();
		player.Draw(window);
		//window.draw(player); // 플레이어를 그리는 기능
		for (int i = 0; i < enemyCount; i++)
		{
			enemies[i].Draw(window);
		}


		window.display();

	}
	
	delete [] enemies;
	//delete[] enemyPositionX;
	//delete[] enemyPositionY;

	return 0;
	}
	


