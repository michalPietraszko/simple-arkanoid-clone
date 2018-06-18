#include "Scenes.h" 
#include <Windows.h>

#include <iostream>



Ball::Ball(float startX, float startY, static const sf::Color color) {
	bShape.setPosition(startX, startY);
	bShape.setRadius(ballRadius);
	bShape.setFillColor(color);
	bShape.setOrigin(ballRadius, ballRadius);
	gameOver = false;
	livesAvaiable = LIVES;
	velocity.x = -ballVelocity;
	velocity.y = -ballVelocity;
}
void Ball::update() {
	
	if (left() < 0 || right() > windowWidth)  velocity.x = -velocity.x;
	if (top()  < 0 || bottom()> windowHeight) velocity.y = -velocity.y;
	if (top() >= (windowHeight - ballRadius)) { 
		if (livesAvaiable == 0)
			gameOver = true;
		else {
			livesAvaiable--;
		}		
	}
	bShape.move(velocity);
}
