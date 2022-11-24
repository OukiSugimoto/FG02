#pragma once
#include"DxLib.h"

class Talk
{
public:
	Talk();
	~Talk();

	void Initialize();
	void Draw();

private:
	int posX = 0;
	int posY = 0;

	int talkGraph = LoadGraph("Resource\\talk.png");	

	int chatSendGraph = LoadGraph("Resource\\PlayerText.png");

	int TalkScrollY = 0;
	//スクロール用変数
	int posY2;
	
	//タイマー
	int time;
	int timer;
};

