#include"talk.h"

Talk::Talk() {}
Talk::~Talk(){}

void Talk::Initialize() {
	posX = 0;
	posY = 0;

	posY2 = 850;
	TalkScrollY = 0;

	timer = 120;
}

void Talk::Update(char *key) {
	if (key[KEY_INPUT_UP]) {
		TalkScrollY -= 10;
	}
	if (key[KEY_INPUT_DOWN]) {
		TalkScrollY += 10;
	}
	
	if (TalkScrollY >= 850) {
		TalkScrollY = 0;
		posY = 0;
		posY2 = 850;
	}

	if (TalkScrollY <= 0) {
		TalkScrollY = 0;
		posY = 0;
		posY2 = 850;
	}
	
}

void Talk::Draw() {
	DrawGraph(posX, posY - TalkScrollY, talkGraph, TRUE);
	DrawGraph(posX, posY2 - TalkScrollY, talk2Graph, TRUE);

	DrawFormatString(200, 200, GetColor(128, 128, 128), "scroll=%d", TalkScrollY);
	
}
