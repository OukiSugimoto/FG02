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
	int posX;
	int posY;

	int talkGraph = LoadGraph("Resource\\talk.png");	

	int chatSendGraph = LoadGraph("Resource\\PlayerText.png");

	int TalkScrollY = 0;
	//�X�N���[���p�ϐ�
	int posY2;
	
	//�^�C�}�[
	int time;
	int timer;
};

