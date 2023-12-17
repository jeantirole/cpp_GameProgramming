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

void UpdatePosition(float& currentXPoistion, float& currentYPosition)
{
	bool dPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	bool aPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	bool wPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	bool sPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

	if (dPressed)
	{
		currentXPoistion += 0.05f;
	}
	if (aPressed)
	{
		currentXPoistion -= 0.05f;
	}
	if (wPressed)
	{
		currentYPosition -= 0.05f;
	}
	if (sPressed)
	{
		currentYPosition += 0.05;
	}
}






int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int screenWidth = 800;
	int screenHeight = 450;
	
	
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "GAME");
	
	sf::RectangleShape player;

	float rectWidth = 20.0f;
	float rectHeight = 20.0f;
	float rectXPosition = 50.0f;
	float rectYPosition = 50.0f;

	player.setSize(sf::Vector2f(rectWidth, rectHeight));
	player.setPosition(sf::Vector2f{ rectXPosition, rectYPosition });
	player.setFillColor(sf::Color::Red);

	// Enemies 
	const int enemyCount = 10;
	float enemyPositionX[enemyCount];
	float enemyPositionY[enemyCount];
	const float enemySize = 10.0f;
	const sf::Color enemyColor = sf::Color::Cyan;
	sf::CircleShape enemies[enemyCount];
	for (int i = 0; i < enemySize; i++)
	{
		enemyPositionX[i] = screenWidth - 100;
		enemyPositionY[i] = rand() % screenHeight;
		
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
	
		UpdatePosition(rectXPosition, rectYPosition);
		
		player.setPosition(sf::Vector2f{ rectXPosition,rectYPosition });

		for (int i = 0; i < enemyCount; i++)
		{
			enemies[i].setPosition(sf::Vector2f{ enemyPositionX[i],enemyPositionY[i] });

		}
		
		window.clear();
		window.draw(player);
		for (int i = 0; i < enemyCount; i++)
		{
			window.draw(enemies[i]);
		}


		window.display();

	}
}
	


