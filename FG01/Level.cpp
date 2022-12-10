#include "Level.h"

Level::Level(){}

Level::~Level() {
	
}

void Level::Initialize() {
	levelNumber = 4;
	
}

void Level::Update(char* keys, char* oldkeys) {
	if (keys[KEY_INPUT_DOWN] == TRUE && oldkeys[KEY_INPUT_DOWN] == FALSE) {
		levelNumber--;
		if (levelNumber <= 4) {
			levelNumber = 4;
		}
	}

	if (keys[KEY_INPUT_UP] == TRUE && oldkeys[KEY_INPUT_UP] == FALSE) {
		levelNumber++;
		if (levelNumber >= 7) {
			levelNumber = 7;
		}
	}
}

void Level::Draw() {
	DrawFormatString(80, 250, GetColor(0, 0, 0), "level = %d", levelNumber - 3);

	if (levelNumber == 4) {
		DrawFormatString(180, 30, GetColor(0, 0, 0), "連絡内容:寝坊した友へ");
	}

	if (levelNumber == 5) {
		DrawFormatString(180, 30, GetColor(0, 0, 0), "連絡内容:おつかい");
	}
	
	if (levelNumber == 6) {
		DrawFormatString(180, 30, GetColor(0, 0, 0), "連絡内容:デートの誘い");
	}

	if (levelNumber == 7) {
		DrawFormatString(180, 30, GetColor(0, 0, 0), "連絡内容:待ち合わせ");
	}
}
