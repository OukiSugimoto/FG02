#include "PlayerChat.h"

void PlayerChat::Initialize() {
	playerPosX = 325;
	playerPosY = 140;

	enemyPosX = 20;
	enemyPosY = 90;

	chattime = 0;

	chatReceponCount = 0;
	chatSendCount = 0;

	ChatScrollY = 0;
}

void PlayerChat::Update(char* key) {
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

void PlayerChat::Draw(){
    DrawGraph(playerPosX,playerPosY + ChatScrollY, chatSendGraph,TRUE);
}