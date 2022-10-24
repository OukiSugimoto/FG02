#include "chat.h"

void Chat::Initialize() {
	playerPosX = 325;
	playerPosY = 140;

	enemyPosX = 20;
	enemyPosY = 90;

	chattime = 0;

	chatReceponCount = 0;
	chatSendCount = 0;
}

void Chat::Update(char* key) {
	if (key[KEY_INPUT_S]) {
		Chat::Draw();

	}
}

void Chat::Draw() {
	DrawGraph(325,140 + 190 * chatReceponCount,chatReceponGraph,TRUE);
	DrawGraph(20,90, chatSendGraph, TRUE);
}