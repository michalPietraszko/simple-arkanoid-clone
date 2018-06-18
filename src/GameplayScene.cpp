#include "Scenes.h"
#include "Constants.h"

template<class T>
void testAndHandleCollision(T* &player, Ball* &ball) {
	if (!isIntersecting(*player, *ball))
		return;
	(ball->getVelocity()).y = -ballVelocity;
	//very stupid and too simple//
	float ballX = ball->x();
	float playerX = player->x();
	if (ballX < playerX){ (ball->getVelocity()).x = -ballVelocity;
}
	else (ball->getVelocity()).x = ballVelocity;
}
bool GameplayScene::gameOver() {
	for (int i = 0; i< vObstacles.size(); i++)
	{
		if (vObstacles[i] != nullptr)
			return false;
	}
	return true;
}
void GameplayScene::populateObstacles(int* &obstacles) {
	constexpr float middle{ windowWidth / 2.f };
	float gaps[2] = { -(obstacleWidth/2.f + VERTICAL_OBST_GAP), (obstacleWidth/2.f + VERTICAL_OBST_GAP) };
	for (int i = 0; i < obstaclesRowsNumber; i++) {
		int k = 0;
		int go_further = 0;
		for (int j = 0; j < *(obstacles+i); j++) {			
			Obstacle* obs = new Obstacle(middle + gaps[j % 2] * go_further, 20.f + ((obstacleHeight + HORIZONTAL_OBST_GAP) * i), OBST_COLOR);
			vObstacles.push_back(obs);
			go_further = j % 2 == 0 ? ++k : k;
		}
	}
}
GameplayScene::GameplayScene(int* &obstacles) {
	 ball = new Ball(windowWidth/2, windowHeight/2, Color::Red);
	 player = new Player(windowWidth / 2, windowHeight - 50, Color::Magenta);
	 populateObstacles(obstacles);
}
GameplayScene::~GameplayScene() {
	delete ball;
	delete player;
	//vector<Obstacle*>::iterator it;
	for (int i = 0; i< vObstacles.size(); i++)
	{
		delete (vObstacles[i]);
	}
	vObstacles.clear();
}

void GameplayScene::draw(RenderWindow &window) {
	window.draw(ball->getShape());
	window.draw(player->getShape());
	for (int i = 0; i < vObstacles.size(); i++) {
		if(vObstacles[i]!=nullptr)
			window.draw(vObstacles[i]->getShape());
	}
	window.display();
}

void GameplayScene::update(){
	testAndHandleCollision<Player>(player, ball);
	ball->update();
	player->update();
	for (int i = 0; i < vObstacles.size(); i++) {
		if (vObstacles[i] != nullptr && isIntersecting(*(vObstacles[i]), *ball)) {
			testAndHandleCollision<Obstacle>(vObstacles[i], ball);
			delete (vObstacles[i]);	
			vObstacles[i] = nullptr;
		}
	}	
}
/*
void update2() {
	testAndHandleCollision<Player>(player, ball);
	ball->update();
	player->update();
	for (int i = 0; i < vObstacles.size(); i++) {
		if (isIntersecting(*(vObstacles[i]), *ball) && vObstacles[i]->isVisible()) {
			testAndHandleCollision<Obstacle>(vObstacles[i], ball);
			vObstacles[i]->update();
		}
	}
}
*/
