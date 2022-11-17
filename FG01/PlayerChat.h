#pragma once
#include"DxLib.h"

class PlayerChat 
{
public:
	PlayerChat() {}
	~PlayerChat(){}
	
	void Initialize();
	void Update(char *keys, char* oldkeys);
	void Draw();

	int chatSendFlag[10];

	int chatFalse = 0;

	int clearTimer = 30;

	int endTimer = 30;
private:
	char keys[256] = { 0 };   // 最新のキーボード情報用
	char oldkeys[256] = { 0 };// 1ループ(フレーム)前のキーボード情報

	int playerPosX[10];
	int playerPosY[10];

	int chatAnser = 0;
	int chatchose = 0;

	int sceneState = 0;
	
	int chattime;

	int chatSendCount;

	int ChatScrollY = 0;

	int chatSendGraph = LoadGraph("Resource\\playerText.png");

	int chatSelectGraph = LoadGraph("Resource\\text_small.png");

	int chatChoseFlage = 0;

	//void ChatFalse();
};