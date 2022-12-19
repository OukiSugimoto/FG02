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
	DrawFormatString(200, 370, GetColor(0, 0, 0), "�I�񂾂�SPACE");

	if (levelNumber == 4) {
		DrawFormatString(60, 650, GetColor(255, 0, 0), "�Q�V�����F��");
	}
	else{
		DrawFormatString(60, 650, GetColor(0, 0, 0), "�Q�V�����F��");
	}

	if (levelNumber == 5) {
		DrawFormatString(340, 650, GetColor(255, 0, 0), "������");
	}
	else {
		DrawFormatString(340, 650, GetColor(0, 0, 0), "������");
	}
	
	if (levelNumber == 6) {
		DrawFormatString(60, 750, GetColor(255, 0, 0), "�f�[�g�̗U��");
	}
	else {
		DrawFormatString(60, 750, GetColor(0, 0, 0), "�f�[�g�̗U��");
	}

	if (levelNumber == 7) {
		DrawFormatString(340,750, GetColor(255, 0, 0), "�҂����킹");
	}
	else {
		DrawFormatString(340, 750, GetColor(0, 0, 0), "�҂����킹");
	}
}
