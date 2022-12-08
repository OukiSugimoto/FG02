#pragma once
#include"DxLib.h"
#include"Level.h"

class PlayerChat3
{
public:
	PlayerChat3() {}
	~PlayerChat3() {}

	void Initialize();
	void Update(char* keys, char* oldkeys);
	void Draw();

	void ChatLike();

	int chatSendFlag[10];

	int chatFalse = 0;

	int clearTimer = 30;

	int endTimer = 30;

	int ChatLikePoint = 100;

	int playerHpPosX[5];
	int playerHpPosY[5];

	int Animes[7];

	int AnimeTime = 0;

	int index = 0;

	int count = 0;

	int shakeChat = rand() % 11 - 10;

	int PlayerLifeGraph = LoadGraph("Resource\\HP.png");

	int PlayerLifeAnime = LoadDivGraph("Resource\\HPAnime.png", 7, 7, 1, 32, 32, Animes);

private:
	char keys[256] = { 0 };   // 最新のキーボード情報用
	char oldkeys[256] = { 0 };// 1ループ(フレーム)前のキーボード情報

	int playerPosX[10];
	int playerPosY[10];

	int chatAnser = 0;
	int chatchose = 0;

	int sceneState = 0;

	int Timer = 0;

	int chattime;

	int chatSendCount;

	int chatDamege = rand() % 21 - 20;

	int ChatScrollY = 0;

	int chatSendGraph = LoadGraph("Resource\\playerText.png");

	int chatSelectGraph = LoadGraph("Resource\\text_small.png");

	int chatChoseFlage = 0;

	int HpAnime = 0;

};

