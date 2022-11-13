#pragma once
#include"DxLib.h"
#include"PlayerChat.h"

class EnemyChat : public PlayerChat
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

	int chatAnser = 0;
	int chatchose = 0;

	char keys[256] = { 0 };   // 最新のキーボード情報用
	char oldkeys[256] = { 0 };// 1ループ(フレーム)前のキーボード情報

	int chatReceponFlag[20];

	int ChatScrollY = 0;

	int chatReceponGraph = LoadGraph("Resource\\enemyText.png");

	int chatReceponSe = LoadSoundMem("Resource\\teroren.mp3",6);

	int chatChoseFlage = 0;
};

