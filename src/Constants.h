#pragma once
#include <vector>

using namespace sf;

//window size
constexpr int windowWidth{ 800 }, windowHeight{ 600 };
constexpr unsigned int obstaclesRowsNumber{ 3 };
constexpr float ballVelocity      {  8.f };
constexpr float ballRadius        { 10.f };
constexpr float playerWidth       { 60.f };
constexpr float playerHeight      { 20.f };
constexpr float obstacleWidth     { 55.f };
constexpr float obstacleHeight    { 20.f };
constexpr float playerVelocity    { 12.f };
constexpr float VERTICAL_OBST_GAP{ 32.5f };
constexpr float HORIZONTAL_OBST_GAP{ 5.f };
constexpr unsigned int LIVES{ 3 };

const sf::Color OBST_COLOR = Color::Yellow;


template<class T1, class T2> 
bool isIntersecting(T1 &shape1, T2 &shape2) {
	return shape1.right() >= shape2.left() && shape1.left() <= shape2.right() &&
		shape1.bottom() >= shape2.top() && shape1.top() <= shape2.bottom();
}

