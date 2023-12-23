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
#include <vector>
#include <windows.h>
#include <..\Game_programming_cpp\Player.h>
#include <..\Game_programming_cpp\Enemy.h>
#include <..\Game_programming_cpp\Bullet.h>

// Eric edited 2023-12-17 // ~_ ~ // 


int main()
{
	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int* intArray = new int[10];
	intArray[0] = 10;

	int screenWidth = 1200;
	int screenHeight = 600;

	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "GAME");
	// FPS ���� ! 
	//window.setFramerateLimit(60);
	

	// Player 
	Player player{ sf::Vector2f{50.0f, 50.0f},
				20.0f,
				sf::Color::Red,
				500 };
	

	// Enemies 
	const int enemyCount = 10;
	std::vector<Enemy*> enemies;
	//Enemy* enemies = new Enemy[enemyCount]; //Ŭ������ �����Ҵ� 
	for (int i = 0; i < enemyCount; i++)
	{
		float enemyRandomX = screenWidth - 100;
		float enemyRandomY = rand() % screenHeight;
		sf::Vector2f enemyPos{ enemyRandomX,enemyRandomY };


		Enemy* e = new Enemy{ enemyPos,10.0f,sf::Color::Cyan,0.05,&player }; // enemy �� ���� �� �ּҸ� �����Ҵ� new�� �Ѱ���
		enemies.push_back(e);
		
	}

	// Bullet
	std::vector<Bullet*> bullets;
	//Bullet b{ sf::Vector2f{0,0},sf::Vector2f{1,0},5,sf::Color::Green,500 };
	float bulletFirePeriod = 1.0f;
	float bulletFireTimer = 0.0f;


	// Bullet �� �ֱ����� ������ ���� Time clock
	sf::Clock deltaTimeClock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		float dt = deltaTimeClock.restart().asSeconds();
		//std::cout << dt << std::endl;
		bulletFireTimer += dt;
		if (bulletFireTimer > bulletFirePeriod)
		{
			// Bullet ���� ����
			//std::cout << " ���ο� �Ѿ� ������ " << std::endl;

			Bullet* b = new Bullet{ player.GetPosition(),sf::Vector2f{1,0},
			3,sf::Color::Yellow, 500 };

			bullets.push_back(b);

			bulletFireTimer = 0;
		}

	
	
		// �÷��̾� �̵� ���� 
		player.Update(dt); // key press and initial location set 


		// �� �̵� ���� 
		for (int i = 0; i < enemies.size(); i++)
		{
			// (*enemies[i]).Update(); // �ּҸ� ã�ư��� class ��ü�� �����;� �ϹǷ�,, �������� Ȱ���Ѵ�. ��ü=>�ּ�=>��ü 
			enemies[i]->Update(dt); // �� �̰� �ξ� ���� �������� �����ǵ�. 
		}

		// Bullet �̵� ���� 
		for (int i = 0; i < bullets.size(); i++)
		{
			// (*enemies[i]).Update(); // �ּҸ� ã�ư��� class ��ü�� �����;� �ϹǷ�,, �������� Ȱ���Ѵ�. ��ü=>�ּ�=>��ü 
			bullets[i]->Update(dt); // �� �̰� �ξ� ���� �������� �����ǵ�. 
		}
		
		window.clear();
		player.Draw(window);
		//window.draw(player); // �÷��̾ �׸��� ���
		for (int i = 0; i < enemies.size(); i++)
		{
			(*enemies[i]).Draw(window);

		}

		//bullet draw ! 
		for (int i = 0; i < bullets.size(); i++)
		{
			// (*enemies[i]).Update(); // �ּҸ� ã�ư��� class ��ü�� �����;� �ϹǷ�,, �������� Ȱ���Ѵ�. ��ü=>�ּ�=>��ü 
			bullets[i]->Draw(window); // �� �̰� �ξ� ���� �������� �����ǵ�. 
		}


		window.display();

	}

	for (int i = 0; i < enemies.size(); i++)
	{
		delete enemies[i];
	}

	
	//delete [] enemies; vec �� ����ϱ� ������ �ʿ� ������
	//delete[] enemyPositionX;
	//delete[] enemyPositionY;

	return 0;
	}
	


