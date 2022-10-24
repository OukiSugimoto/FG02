#pragma once
#include"DxLib.h"

class PlayerChat
{
public:
	PlayerChat() {}
	~PlayerChat(){}

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

	int chatReceponCount = 0;
	int chatSendCount = 0;

	int chatReceponFlag[100];
	int chatSendFlag[100];

	int ChatScrollY = 0;

	int chatSendGraph = LoadGraph("Resource\\PlayerText.png");
};