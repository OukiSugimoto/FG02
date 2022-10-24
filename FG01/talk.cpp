#include"talk.h"

Talk::Talk() {}
Talk::~Talk(){}

void Talk::Initialize() {
	posX = 20;
	posY = 0;

	posY2 = 650;
	scrollY = 0;

	timer = 120;
}

void Talk::Update(char *key) {
	if (key[KEY_INPUT_UP]) {
		scrollY -= 10;
	}
	if (key[KEY_INPUT_DOWN]) {
		scrollY += 10;
	}
	
	if (scrollY >= 650) {
		scrollY = 0;
		posY = 0;
		posY2 = 650;
	}
	if (scrollY <= 0) {
		scrollY = 0;
		posY = 0;
		posY2 = 650;
	}
	
}

void Talk::Draw() {
	DrawGraph(posX, posY - scrollY, talkGraph, TRUE);
	DrawGraph(posX, posY2 - scrollY, talk2Graph, TRUE);

	DrawFormatString(200, 200, GetColor(128, 128, 128), "scroll=%d", scrollY);
	
}
