#pragma once
#include "GameObjects.h"

Obstacle::Obstacle(float startX, float startY, sf::Color color) {
	oShape.setPosition(startX, startY);
	oShape.setSize(sf::Vector2f(obstacleWidth, obstacleHeight));
	oShape.setFillColor(color);
	oShape.setOrigin(playerWidth / 2.f, playerHeight / 2.f);
}
void Obstacle::update() {
	//UNUSED//
	setVisible(false);
}