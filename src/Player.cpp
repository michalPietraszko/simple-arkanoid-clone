#pragma once
#include "GameObjects.h"

Player::Player(float startX, float startY, sf::Color color) {
	pShape.setPosition(startX, startY);
	pShape.setSize( sf::Vector2f(playerWidth, playerHeight));
	pShape.setFillColor(color);
	pShape.setOrigin(playerWidth / 2.f, playerHeight / 2.f);
}
void Player::update() {
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && left() > 0) velocity.x = -playerVelocity;
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && right() < windowWidth) velocity.x = playerVelocity;
	else velocity.x = 0;
	pShape.move(velocity);
}