#include "EnemyChat.h"

void EnemyChat::Initialize() {
	enemyPosX = 20;
	enemyPosY = 90;

	chatReceponCount = 0;

	ChatScrollY = 0;
}

void EnemyChat::Update(char* key) {
	if (key[KEY_INPUT_DOWN]) {
		ChatScrollY -= 5;
	}
	if (key[KEY_INPUT_UP]) {
		ChatScrollY += 5;
	}

	if (ChatScrollY >= 0) {
		ChatScrollY = 0;
	}
}

void EnemyChat::Draw() {
	DrawGraph(enemyPosX, enemyPosY + ChatScrollY, chatReceponGraph, TRUE);
}