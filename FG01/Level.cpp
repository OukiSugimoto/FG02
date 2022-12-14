#include "Level.h"

Level::Level(){}

Level::~Level() {
	
}

void Level::Initialize() {
	levelNumber = 4;
	
}

void Level::Update(char* keys, char* oldkeys) {
	if (keys[KEY_INPUT_1] == TRUE && oldkeys[KEY_INPUT_1] == FALSE) {
		levelNumber = 4;
	}

	if (keys[KEY_INPUT_2] == TRUE && oldkeys[KEY_INPUT_2] == FALSE) {
		levelNumber = 5;
	}

	if (keys[KEY_INPUT_3] == TRUE && oldkeys[KEY_INPUT_3] == FALSE) {
		levelNumber = 6;
	}

	if (keys[KEY_INPUT_4] == TRUE && oldkeys[KEY_INPUT_4] == FALSE) {
		levelNumber = 7;
	}
}

void Level::Draw() {
	DrawFormatString(220, 700, GetColor(0, 0, 0), "選んだらSPACE");

	if (levelNumber == 4) {
		DrawFormatString(70, 280, GetColor(255, 0, 0), "寝坊した友へ");
	}
	else{
		DrawFormatString(70, 280, GetColor(0, 0, 0), "寝坊した友へ");
	}

	if (levelNumber == 5) {
		DrawFormatString(350, 280, GetColor(255, 0, 0), "おつかい");
	}
	else {
		DrawFormatString(350, 280, GetColor(0, 0, 0), "おつかい");
	}
	
	if (levelNumber == 6) {
		DrawFormatString(70, 380, GetColor(255, 0, 0), "デートの誘い");
	}
	else {
		DrawFormatString(70, 380, GetColor(0, 0, 0), "デートの誘い");
	}

	if (levelNumber == 7) {
		DrawFormatString(350,380, GetColor(255, 0, 0), "待ち合わせ");
	}
	else {
		DrawFormatString(350, 380, GetColor(0, 0, 0), "待ち合わせ");
	}
}
