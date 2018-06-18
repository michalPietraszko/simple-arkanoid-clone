#pragma once
#include "GameObjects.h"

using std::vector;

class Scene {
public: 
	virtual void update() = 0;
	virtual void draw(RenderWindow  &window) = 0;
};

class GameplayScene : public Scene {
	Ball* ball;
	Player* player;
	Obstacle* obst;
	vector<Obstacle*> vObstacles;

public:
	 Ball * &getBall() { return ball; }
	 bool gameOver();
	 GameplayScene(int* &obstacles);//pointer to array start
	 ~GameplayScene();
	 void populateObstacles(int* &obstacles);
	 void update();
	 void draw(RenderWindow  &window);
};