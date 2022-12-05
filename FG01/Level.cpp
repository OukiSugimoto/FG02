#include "Level.h"

Level::Level(){}

Level::~Level() {
	
}

void Level::initialize() {
	levelNumber = 4;
	
}

void Level::Update(char* keys, char* oldkeys) {
	if (keys[KEY_INPUT_DOWN] == TRUE && oldkeys[KEY_INPUT_DOWN] == FALSE) {
		levelNumber--;
		if (levelNumber <= 3) {
			levelNumber = 3;
		}
	}

	if (keys[KEY_INPUT_UP] == TRUE && oldkeys[KEY_INPUT_UP] == FALSE) {
		levelNumber++;
		if (levelNumber >= 8) {
			levelNumber = 8;
		}
	}
}

void Level::Draw() {
	DrawFormatString(80, 250, GetColor(0, 0, 0), "level = %d", levelNumber - 3);

	if (levelNumber == 4) {
		DrawFormatString(180, 30, GetColor(0, 0, 0), "�A������:�Ƃ�����");
	}

	if (levelNumber == 5) {
		DrawFormatString(180, 30, GetColor(0, 0, 0), "�A������:�t��");
	}
	
	if (levelNumber == 6) {
		DrawFormatString(180, 30, GetColor(0, 0, 0), "�A������:�w���I�X");
	}

	if (levelNumber == 7) {
		DrawFormatString(180, 30, GetColor(0, 0, 0), "�A������:�W���C�{�[�C");
	}

	if (levelNumber == 8) {
		DrawFormatString(180, 30, GetColor(0, 0, 0), "�A������:�J�C�h�E");
	}
}
