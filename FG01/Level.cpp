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
	DrawFormatString(200, 370, GetColor(0, 0, 0), "ëIÇÒÇæÇÁSPACE");

	if (levelNumber == 4) {
		DrawFormatString(60, 650, GetColor(255, 0, 0), "êQñVÇµÇΩóFÇ÷");
	}
	else{
		DrawFormatString(60, 650, GetColor(0, 0, 0), "êQñVÇµÇΩóFÇ÷");
	}

	if (levelNumber == 5) {
		DrawFormatString(340, 650, GetColor(255, 0, 0), "Ç®Ç¬Ç©Ç¢");
	}
	else {
		DrawFormatString(340, 650, GetColor(0, 0, 0), "Ç®Ç¬Ç©Ç¢");
	}
	
	if (levelNumber == 6) {
		DrawFormatString(60, 750, GetColor(255, 0, 0), "ÉfÅ[ÉgÇÃóUÇ¢");
	}
	else {
		DrawFormatString(60, 750, GetColor(0, 0, 0), "ÉfÅ[ÉgÇÃóUÇ¢");
	}

	if (levelNumber == 7) {
		DrawFormatString(340,750, GetColor(255, 0, 0), "ë“ÇøçáÇÌÇπ");
	}
	else {
		DrawFormatString(340, 750, GetColor(0, 0, 0), "ë“ÇøçáÇÌÇπ");
	}
}
