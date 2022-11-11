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
	char keys[256] = { 0 };   // 最新のキーボード情報用
	char oldkeys[256] = { 0 };// 1ループ(フレーム)前のキーボード情報


	int chatSendFlag1 = 0;
	int chatSendFlag2 = 0;
	int chatSendFlag3 = 0;
	int chatSendFlag4 = 0;
	int chatSendFlag5 = 0;

	int playerPosX[10];
	int playerPosY[10];

	int chatAnser = 0;
	int chatchose = 0;
	//仮
	int chattime;



	int chatSendCount = 0;

	int chatSendFlag[20];

	int ChatScrollY = 0;

	int chatSendGraph = LoadGraph("Resource\\playerText.png");
};