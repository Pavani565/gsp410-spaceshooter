#pragma once

#include "Global.h"
#include "Renderer.h"
#include "Player.h"
#include "HUD.h"
#include "UI.h"
#include "Enemy.h"
#include "Station.h"
#include "Star.h"


class Controller
{
private:
	controllerState gameControleState;
	commandState playerCommand;
	altMoveState playerAltMove;
	Renderer renderer;
	Player player;
	HUD hud;
	UI ui;
	Enemy enemies;
	Station stations;
	Star stars;


public:

	void initGame(void);

	void setUpScreen(void);

	void giveIntroSpeel(void);

	void runRules(void);

	

	void update(void);

	void updateCommand(void);

	void makeQuads(void);

		

	void moveProcess(void);

	bool enoughFuel(void);

	bool checkForObstacles(void);

	void addUpObsticleCosts(void);


	void longRangeScan(void);

	void fireBlaster(void);
	void calculateEnemyDamage(void);
	
	void fireMissle(void);
	void addUpObsticleDamage(void);

	void updateSheilds(void);

	void shutdown(void);
};