#pragma once
#include"DxLib.h"
class Talk
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
	//スクロール用変数
	int posY2;
	int scrollY;

	int talk2Graph = talkGraph;
	//タイマー
	int time;
	int timer;
};

