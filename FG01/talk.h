#pragma once
#include"DxLib.h"
#include"EnemyChat.h"

class Talk : public EnemyChat
{
public:
	Talk();
	~Talk();

	void Initialize();
	void Update(char *key);
	void Draw();

private:
	int posX;
	int posY;

	int talkGraph = LoadGraph("Resource\\talk.png");	

	int chatSendGraph = LoadGraph("Resource\\PlayerText.png");

	int TalkScrollY = 0;
	//スクロール用変数
	int posY2;
	
	int talk2Graph = talkGraph;
	//タイマー
	int time;
	int timer;
};

