#include "EnemyChat.h"

EnemyChat::EnemyChat() {}
EnemyChat::~EnemyChat(){}

void EnemyChat::Initialize() {
	enemyPosX[0] = 20;        enemyPosX[1] = 20;
	enemyPosY[0] = 90;        enemyPosY[1] = 190;
	
	enemyPosX[2] = 20;        enemyPosX[3] = 20;
	enemyPosY[2] = 240;       enemyPosY[3] = 290;

	enemyPosX[4] = 20;        enemyPosX[5] = 20;
	enemyPosY[4] = 340;       enemyPosY[5] = 390;

	enemyPosX[6] = 20;        enemyPosX[7] = 20;
	enemyPosY[6] = 440;       enemyPosY[7] = 490; 

	chatReceponCount = 0;

	ChatScrollY = 0;
}

void EnemyChat::Update(char* keys, char* oldkeys) {
	
	if (keys[KEY_INPUT_DOWN]) {
		ChatScrollY -= 5;
	}

	if (keys[KEY_INPUT_UP]) {
		ChatScrollY += 5;
	}

	if (ChatScrollY >= 0) {
		ChatScrollY = 0;
	}

	if (keys[KEY_INPUT_1] == TRUE && oldkeys[KEY_INPUT_SPACE] == FALSE) {
		chatReceponFlag1 = TRUE;
	}
	
}

void EnemyChat::Draw() {
		DrawGraph(enemyPosX[0], enemyPosY[0] + ChatScrollY, chatReceponGraph, TRUE);

		if (chatReceponFlag1 == TRUE) {
			DrawGraph(enemyPosX[1], enemyPosY[1] + ChatScrollY, chatReceponGraph, TRUE);
		}
		
		if (chatReceponFlag2 == TRUE) {
			DrawGraph(enemyPosX[2], enemyPosY[2] + ChatScrollY, chatReceponGraph, TRUE);
		}

		if (chatReceponFlag3 == TRUE) {
			DrawGraph(enemyPosX[3], enemyPosY[3] + ChatScrollY, chatReceponGraph, TRUE);
		}

		//DrawFormatString(100,100,GetColor(255,255,255),"flag = %d",chatReceponFlag1);

}