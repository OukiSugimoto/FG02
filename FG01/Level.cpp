#include "Level.h"

Level::Level(){}

Level::~Level() {
	
}

void Level::initialize() {
	levelNumber = 1;
	
}

void Level::Update(char* keys, char* oldkeys) {
	if (keys[KEY_INPUT_DOWN] == TRUE && oldkeys[KEY_INPUT_DOWN] == FALSE) {
		levelNumber--;
		if (levelNumber <= 1) {
			levelNumber = 1;
		}
	}

	if (keys[KEY_INPUT_UP] == TRUE && oldkeys[KEY_INPUT_UP] == FALSE) {
		levelNumber++;
		if (levelNumber >= 5) {
			levelNumber = 5;
		}
	}
}

void Level::Draw() {
	DrawFormatString(80, 250, GetColor(0, 0, 0), "level = %d", levelNumber);

	if (levelNumber == 1) {
		DrawFormatString(180, 30, GetColor(0, 0, 0), "連絡相手:ともだち");
	}

	if (levelNumber == 2) {
		DrawFormatString(180, 30, GetColor(0, 0, 0), "連絡相手:春日");
	}
	
	if (levelNumber == 3) {
		DrawFormatString(180, 30, GetColor(0, 0, 0), "連絡相手:ヘリオス");
	}

	if (levelNumber == 4) {
		DrawFormatString(180, 30, GetColor(0, 0, 0), "連絡相手:ジョイボーイ");
	}

	if (levelNumber == 5) {
		DrawFormatString(180, 30, GetColor(0, 0, 0), "連絡相手:カイドウ");
	}
}
