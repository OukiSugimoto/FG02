#pragma once
#include"DxLib.h"

class EnemyChat
{
public:
	EnemyChat();
	~EnemyChat();

	void Initialize();
	void Update(char* keys,char* oldkeys);
	void Draw();

private:
	int enemyPosX[10];
	int enemyPosY[10];
	int chattime;

	int chatReceponCount = 0;

	char keys[256] = { 0 };   // 最新のキーボード情報用
	char oldkeys[256] = { 0 };// 1ループ(フレーム)前のキーボード情報

	int chatReceponFlag1 = 0;
	int chatReceponFlag2 = 0;
	int chatReceponFlag3 = 0;
	int chatReceponFlag4 = 0;
	int chatReceponFlag5 = 0;

	int ChatScrollY = 0;

	int chatReceponGraph = LoadGraph("Resource\\enemyText.png");
};

