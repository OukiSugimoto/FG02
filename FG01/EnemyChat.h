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

	int chatReceponFlag[20];

private:
	int enemyPosX[10];
	int enemyPosY[10];
	int chattime;

	int chatReceponCount = 0;

	char keys[256] = { 0 };   // �ŐV�̃L�[�{�[�h���p
	char oldkeys[256] = { 0 };// 1���[�v(�t���[��)�O�̃L�[�{�[�h���

	

	int ChatScrollY = 0;

	int chatReceponGraph = LoadGraph("Resource\\enemyText.png");
};

