#pragma once
#include"DxLib.h"
#include"EnemyChat.h"

class PlayerChat : public EnemyChat
{
public:
	PlayerChat() {}
	~PlayerChat(){}
	
	void Initialize();
	void Update(char *keys, char* oldkeys);
	void Draw();
	
private:
	char keys[256] = { 0 };   // �ŐV�̃L�[�{�[�h���p
	char oldkeys[256] = { 0 };// 1���[�v(�t���[��)�O�̃L�[�{�[�h���


	int chatSendFlag1 = 0;
	int chatSendFlag2 = 0;
	int chatSendFlag3 = 0;
	int chatSendFlag4 = 0;
	int chatSendFlag5 = 0;

	int playerPosX[10];
	int playerPosY[10];

	int chatAnser = 0;
	int chatchose = 0;
	//��
	int chattime;



	int chatSendCount = 0;

	int chatSendFlag[20];

	int ChatScrollY = 0;

	int chatSendGraph = LoadGraph("Resource\\playerText.png");
};