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
	//�X�N���[���p�ϐ�
	int posY2;
	int scrollY;

	int talk2Graph = talkGraph;
	//�^�C�}�[
	int time;
	int timer;
};

