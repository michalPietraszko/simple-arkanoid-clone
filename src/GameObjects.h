#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Constants.h"



class GameObject {
	//sf::Vector2f velocity;
public:	
	virtual Shape & getShape() = 0;	
	virtual float getWidth() = 0;
	virtual float getHeight() = 0;
	float x() { return getShape().getPosition().x; }
	float y() { return getShape().getPosition().y; }
	float left() { return x() - getWidth()     /2.f; }
	float right() { return x() + getWidth()   / 2.f; }
	float top() { return y() - getHeight()    / 2.f; }
	float bottom() { return y() + getHeight() / 2.f; }
};

class Ball : public GameObject {
private:
	sf::CircleShape bShape;
	sf::Vector2f velocity;
	bool gameOver;	
	unsigned int livesAvaiable;

public:
	Ball(float startX, float startY, sf::Color color);
	unsigned int getLives() { return livesAvaiable;  }
	CircleShape& getShape() override { return bShape; }
	Vector2f& getVelocity() { return velocity; }
	void update();
	bool checkBallGameOver() { return gameOver; }
	virtual float getWidth()  override { return ballRadius; }
	virtual float getHeight() override { return ballRadius; }
};

class Player : public GameObject {
private: 
	sf::RectangleShape pShape;
	sf::Vector2f velocity;
public:
	Player(float startX, float startY, sf::Color color);
	RectangleShape& getShape() override { return pShape; }
	Vector2f& getVelocity() { return velocity; }
	void update();
	virtual float getWidth()  override { return playerWidth; }
	virtual float getHeight() override { return playerHeight; }

};
class Obstacle : public GameObject {
private:
	sf::RectangleShape oShape;
	sf::Vector2f velocity;
	//UNUSED//
	bool visible;
public:
	Obstacle(float startX, float startY, sf::Color color);	
	RectangleShape& getShape() override { return oShape; }
	Vector2f& getVelocity() { return velocity; }
	virtual float getWidth()  override { return obstacleWidth; }
	virtual float getHeight() override { return obstacleHeight; }


	//UNUSED//
	void update();
	//UNUSED//
	bool isVisible() { return visible; }
	//UNUSED//
	void setVisible(bool val) { visible = val; }

};