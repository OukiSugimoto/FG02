#pragma once
#include"DxLib.h"

class EnemyChat
{
public:
	EnemyChat();
	~EnemyChat();

	void Initialize();
	void Update(char* Key);
	void Draw();

private:
	int enemyPosX;
	int enemyPosY;
	int chattime;

	int chatReceponCount = 0;

	int chatReceponFlag[100];

	int ChatScrollY = 0;

	int chatReceponGraph = LoadGraph("Resource\\EnemyText.png");
};

