#include <iostream>
#include <sstream>
#include "Scenes.h"
#include <Windows.h>


/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
////////////////Use with debug x64///////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

void setUpText(sf::Text &text, sf::Font &font, std::string s) {
	text.setFont(font);	
	text.setString(s);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Green);
	text.setPosition(Vector2f(windowWidth - 200.f, windowHeight - 50.f));
}


std::string getLivesInfoString(Ball* &b ) {
	std::stringstream ss;
	ss << "Lives avaiable: " <<b->getLives();
	return ss.str();	
}
int main() {
	bool running = true;	
	int*  obstacles = new int[obstaclesRowsNumber];
	obstacles[0] = 13;
	obstacles[1] = 11;
	obstacles[2] = 9;
	GameplayScene* gScene = new GameplayScene(obstacles);
	RenderWindow window(VideoMode(windowWidth, windowHeight, 32), "Game version 1.02");
	window.setFramerateLimit(60);	

	////text////
	sf::Text text;
	sf::Font font;
	setUpText(text, font, getLivesInfoString(gScene->getBall()));
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "unable to load fonts!" <<std::endl;
	}
	
	unsigned int rememberedLives = gScene->getBall()->getLives();

	//Gameloop
	while (running) {	
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(Color::Black);	
		if (rememberedLives != gScene->getBall()->getLives()) {
			rememberedLives--;
			text.setString(getLivesInfoString(gScene->getBall()));
		}
		window.draw(text);
		gScene->update();
		gScene->draw(window);		
		if (Keyboard::isKeyPressed(Keyboard::Escape)) 
			running = false; 
	
		if (gScene->gameOver()){
			Sleep(1500);
			running = false;
		}
		if (gScene->getBall()->checkBallGameOver()) {
			Sleep(1500);
			running = false;	
		}
	}
	delete gScene;
	delete[] obstacles;

	return 0;
}