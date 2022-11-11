#pragma once
#include"PlayerChat.h"
#include"EnemyChat.h"

class Level : public PlayerChat
{
public:
	Level();
	~Level();

	void initialize();

	void Update();

	void Draw();

private:
	//int sceneState = 0;

	//int enemyPosXLevel1 = 20;   
	//int enemyPosYLevel1 = 90;   

	//int enemyPosXLevel2 = 20;   
	//int enemyPosYLevel2 = 190;  

	//int enemyPosXLevel3 = 20;   
	//int enemyPosYLevel3 = 290; 

	//int enemyPosXLevel4 = 20;  
	//int enemyPosYLevel4 = 390; 

	//int enemyPosXLevel5 = 20;  
	//int enemyPosYLevel5 = 490;  
};

