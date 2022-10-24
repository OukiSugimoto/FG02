#pragma once
#include"DxLib.h"

class Chat
{
public:
	Chat() {}
	~Chat(){}

	void Initialize();
	void Update(char *Key);
	void Draw();
	
private:
	int playerPosX;
	int playerPosY;

	int enemyPosX;
	int enemyPosY;
	//‰¼
	int chattime;

	int chatReceponFlag;
	int chatSendFlag;

	int chatReceponCount = 0;
	int chatSendCount = 0;

	int chatReceponGraph = LoadGraph("Resource\\EnemyText.png");
	int chatSendGraph = LoadGraph("Resource\\PlayerText.png");
};