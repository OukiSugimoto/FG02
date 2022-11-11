#include "PlayerChat.h"

void PlayerChat::Initialize() {
	playerPosX[0] = 320;       playerPosX[1] = 320;
	playerPosY[0] = 140;       playerPosY[1] = 240;

	playerPosX[2] = 320;       playerPosX[3] = 320;
	playerPosY[2] = 340;       playerPosY[3] = 440;

	playerPosX[4] = 320;       playerPosX[5] = 320;
	playerPosY[4] = 540;       playerPosY[5] = 640;

	playerPosX[6] = 320;       playerPosX[7] = 320;
	playerPosY[6] = 740;       playerPosY[7] = 840;

	playerPosX[8] = 320;       playerPosX[9] = 320;
	playerPosY[8] = 940;       playerPosY[9] = 1040;

	//playerPosX[10] = 320;       //playerPosX[7] = 320;
	//playerPosY[10] = 640;       //playerPosY[7] = 490;

	/*enemyPosX = 20;
	enemyPosY = 90;*/

	chattime = 60;

	chatSendCount = 0;

	ChatScrollY = 0;

}

void PlayerChat::Update(char* keys , char* oldkeys) {

	if (keys[KEY_INPUT_DOWN]) {
		ChatScrollY -= 5;
	}

	if (keys[KEY_INPUT_UP]) {
		ChatScrollY += 5;
	}

	if (ChatScrollY >= 0) {
		ChatScrollY = 0;
	}

	if (keys[KEY_INPUT_1] == FALSE && oldkeys[KEY_INPUT_1] == TRUE) {
		chatchose = 1;
	}

	if (keys[KEY_INPUT_2] == FALSE && oldkeys[KEY_INPUT_2] == TRUE) {
		chatchose = 2;
	}

	if (keys[KEY_INPUT_3] == FALSE && oldkeys[KEY_INPUT_3] == TRUE) {
		chatchose = 3;
	}

	if (keys[KEY_INPUT_4] == FALSE && oldkeys[KEY_INPUT_4] == TRUE) {
		chatchose = 4;
	}

	if (chatSendCount == 0) {
		chatAnser = 1;
		if (chatchose == chatAnser) {
			chatSendFlag[0] = TRUE;
			chatSendCount += 1;
		}
	}

	if (chatSendCount == 1) {
		chatAnser = 3;
		if (chatchose == chatAnser) {
			chatSendFlag[1] = TRUE;
			chatSendCount += 1;
		}
	}
	
}

void PlayerChat::Draw(){
		if (chatSendFlag[0] == TRUE) {
			DrawGraph(playerPosX[0], playerPosY[0] + ChatScrollY, chatSendGraph, TRUE);
			DrawFormatString(playerPosX[0] + 50, playerPosY[0] + 50 + ChatScrollY, GetColor(0, 0, 0), "‚¨‚Í‚æ‚¤");
		}

		if (chatSendFlag[1] == TRUE) {
			DrawGraph(playerPosX[1], playerPosY[1] + ChatScrollY, chatSendGraph, TRUE);
		}

		if (chatSendFlag[2] == TRUE) {
			DrawGraph(playerPosX[2], playerPosY[2] + ChatScrollY, chatSendGraph, TRUE);
		}

		if (chatSendFlag[3] == TRUE) {
			DrawGraph(playerPosX[3], playerPosY[3] + ChatScrollY, chatSendGraph, TRUE);
		}

		if (chatSendFlag[4] == TRUE) {
			DrawGraph(playerPosX[4], playerPosY[4] + ChatScrollY, chatSendGraph, TRUE);
		}

		if (chatSendFlag[5] == TRUE) {
			DrawGraph(playerPosX[5], playerPosY[5] + ChatScrollY, chatSendGraph, TRUE);
		}

		if (chatSendFlag[6] == TRUE) {
			DrawGraph(playerPosX[6], playerPosY[6] + ChatScrollY, chatSendGraph, TRUE);
		}

		if (chatSendFlag[7] == TRUE) {
			DrawGraph(playerPosX[7], playerPosY[7] + ChatScrollY, chatSendGraph, TRUE);
		}

		if (chatSendFlag[8] == TRUE) {
			DrawGraph(playerPosX[8], playerPosY[8] + ChatScrollY, chatSendGraph, TRUE);
		}

		if (chatSendFlag[9] == TRUE) {
			DrawGraph(playerPosX[9], playerPosY[9] + ChatScrollY, chatSendGraph, TRUE);
		}
	
	/*DrawFormatString(100, 100, GetColor(255, 255, 255), "%d", chatSendCount);
	DrawFormatString(100, 200, GetColor(255, 255, 255), "chattime=%d", chattime);*/

	DrawFormatString(60, 85, GetColor(255, 255, 255), "‚³‚©‚à‚Æ");
	/*if (chatSendCount == 10) {
		DrawGraph(playerPosX[10], playerPosY[10] + ChatScrollY, chatSendGraph, TRUE);
	}*/
}