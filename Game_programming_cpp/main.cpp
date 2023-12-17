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
	player.setFillColor(sf::Color::Blue);

	
	
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

		
		window.clear();
		window.draw(player);
		window.display();

	}
}
	


