#include "PlayerChat2.h"

void PlayerChat2::Initialize() {
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

	playerHpPosX[0] = 420;     playerHpPosX[1] = 450;
	playerHpPosY[0] = 30;      playerHpPosY[1] = 30;

	playerHpPosX[2] = 480;     playerHpPosX[3] = 510;
	playerHpPosY[2] = 30;      playerHpPosY[3] = 30;

	playerHpPosX[4] = 540;
	playerHpPosY[4] = 30;

	chattime = 60;

	chatSendCount = 0;

	ChatScrollY = 0;

	chatchose = 0;

	chatFalse = 0;

	chatChoseFlage = 0;

	clearTimer = 30;

	endTimer = 30;

	ChatLikePoint = 100;

	AnimeTime = 0;

	HpAnime = 0;

	index = 0;

	count = 0;

	Timer = 30;

	chatBranchFlage = 0;

	chatBranchNumber = 0;

	for (int i = 0; i < 10; i++) {
		chatSendFlag[i] = FALSE;
	}
}

void PlayerChat2::ChatLike() {
	chatchose = 0;

	ChatLikePoint -= 20;

	if (CheckSoundMem(chatFalseSe) == 0) {
		PlaySoundMem(chatFalseSe, DX_PLAYTYPE_BACK, TRUE);
	}

	if (ChatLikePoint == 0) {
		chatFalse = 1;
	}
}

void PlayerChat2::Update(char* keys, char* oldkeys) {
	shakeChat = rand() % 11 - 10;

	if (keys[KEY_INPUT_1] == FALSE && oldkeys[KEY_INPUT_1] == TRUE) {
		chatchose = 1;
		count = 0;
	}

	if (keys[KEY_INPUT_2] == FALSE && oldkeys[KEY_INPUT_2] == TRUE) {
		chatchose = 2;
		count = 0;
	}

	if (keys[KEY_INPUT_3] == FALSE && oldkeys[KEY_INPUT_3] == TRUE) {
		chatchose = 3;
		count = 0;
	}

	if (keys[KEY_INPUT_4] == FALSE && oldkeys[KEY_INPUT_4] == TRUE) {
		chatchose = 4;
		count = 0;
	}

	if (chatSendCount == 0) {
		chatAnser = 2;

		if (chatchose == chatAnser) {
			count = 1;
			chatchose = 0;
			chatSendFlag[0] = TRUE;
			chatChoseFlage = 1;
			chatSendCount += 1;

		}

		if (chatchose == 1 || chatchose == 3 || chatchose == 4) {
			ChatLike();
		}

	}

	if (chatSendCount == 1) {


		chatAnser = 4;


		if (chatchose == chatAnser) {
			count = 1;
			chatchose = 0;
			chatSendFlag[1] = TRUE;
			chatChoseFlage = 2;
			chatSendCount += 1;
		}


		if (chatchose == 2 || chatchose == 1 || chatchose == 3) {
			ChatLike();
		}


	}

	if (chatSendCount == 2) {
		chatAnser = 3;


		if (chatchose == chatAnser) {
			count = 1;
			chatSendFlag[2] = TRUE;
			chatchose = 0;
			chatChoseFlage = 3;
			chatSendCount += 1;
		}

		if (chatchose == 1 || chatchose == 2 || chatchose == 4) {
			ChatLike();
		}


	}

	if (chatSendCount == 3) {
		chatAnser = 2;


		if (chatchose == chatAnser) {
			count = 1;
			chatchose = 0;
			chatSendFlag[3] = TRUE;
			chatChoseFlage = 4;
			chatSendCount += 1;

			ChatScrollY -= 50;
		}

		if (chatchose == 3 || chatchose == 1 || chatchose == 4) {
			ChatLike();
		}

	}

	if (chatSendCount == 4) {

		chatAnser = 3;


		if (chatchose == chatAnser) {
			count = 1;

			chatSendFlag[4] = TRUE;
			chatSendCount += 1;
			chatChoseFlage = 5;
			ChatScrollY -= 50;
			chatchose = 0;

		}


		if (chatchose == 2 || chatchose == 4 || chatchose == 1) {
			ChatLike();
		}


	}
	if (chatSendCount == 5) {

		chatAnser = 4;


		if (chatchose == chatAnser) {
			count = 1;

			chatSendFlag[5] = TRUE;
			chatSendCount += 1;
			chatChoseFlage = 6;
			ChatScrollY -= 100;
			chatchose = 0;

		}


		if (chatchose == 2 || chatchose == 3 || chatchose == 1) {
			ChatLike();
		}


	}
	if (chatSendCount == 6) {

		chatAnser = 1;

		if (chatchose == chatAnser) {
			count = 1;

			chatSendFlag[6] = TRUE;
			chatSendCount += 1;
			chatChoseFlage = 7;
			ChatScrollY -= 100;
			chatchose = 0;

			chatFalse = 2;
		}


		if (chatchose == 2 || chatchose == 4 || chatchose == 3) {
			ChatLike();
		}


	}
}

void PlayerChat2::Draw() {
	DrawGraph(60, 600, chatSelectGraph, TRUE);
	DrawGraph(340, 600, chatSelectGraph, TRUE);
	DrawGraph(60, 700, chatSelectGraph, TRUE);
	DrawGraph(340, 700, chatSelectGraph, TRUE);

	DrawFormatString(78, 610, GetColor(0, 0, 0), "1");
	DrawFormatString(360, 610, GetColor(0, 0, 0), "2");
	DrawFormatString(78, 710, GetColor(0, 0, 0), "3");
	DrawFormatString(360, 710, GetColor(0, 0, 0), "4");

	if (chatSendFlag[0] == TRUE) {
		DrawGraph(playerPosX[0], playerPosY[0] + ChatScrollY, chatSendGraph, TRUE);
		DrawFormatString(playerPosX[0] + 50, playerPosY[0] + 50 + ChatScrollY, GetColor(0, 0, 0), "なに？");

	}

	if (chatSendFlag[1] == TRUE) {
		DrawGraph(playerPosX[1], playerPosY[1] + ChatScrollY, chatSendGraph, TRUE);

		DrawFormatString(playerPosX[1] + 50, playerPosY[1] + 50 + ChatScrollY, GetColor(0, 0, 0), "いいよ");

	}

	if (chatSendFlag[2] == TRUE) {
		DrawGraph(playerPosX[2], playerPosY[2] + ChatScrollY, chatSendGraph, TRUE);

		DrawFormatString(playerPosX[2] + 50, playerPosY[2] + 50 + ChatScrollY, GetColor(0, 0, 0), "うん");


	}

	if (chatSendFlag[3] == TRUE) {
		DrawGraph(playerPosX[3], playerPosY[3] + ChatScrollY, chatSendGraph, TRUE);

		DrawFormatString(playerPosX[3] + 50, playerPosY[3] + 50 + ChatScrollY, GetColor(0, 0, 0), "わかった！");
	}

	if (chatSendFlag[4] == TRUE) {
		DrawGraph(playerPosX[4], playerPosY[4] + ChatScrollY, chatSendGraph, TRUE);

		DrawFormatString(playerPosX[4] + 50, playerPosY[4] + 50 + ChatScrollY, GetColor(0, 0, 0), "じゃがいもと");


	}

	if (chatSendFlag[5] == TRUE) {
		DrawGraph(playerPosX[5], playerPosY[5] + ChatScrollY, chatSendGraph, TRUE);
		DrawFormatString(playerPosX[5] + 50, playerPosY[5] + 50 + ChatScrollY, GetColor(0, 0, 0), "にんじんとカレー粉");

	}

	if (chatSendFlag[6] == TRUE) {
		DrawGraph(playerPosX[6], playerPosY[6] + ChatScrollY, chatSendGraph, TRUE);
		DrawFormatString(playerPosX[6] + 50, playerPosY[6] + 50 + ChatScrollY, GetColor(0, 0, 0), "はーい！");
	}

	if (chatChoseFlage == 0) {
		DrawFormatString(68, 650, GetColor(0, 0, 0), "やだ");
		DrawFormatString(350, 650, GetColor(0, 0, 0), "なに？");
		DrawFormatString(68, 750, GetColor(0, 0, 0), "why？");
		DrawFormatString(350, 750, GetColor(0, 0, 0), "おーけー");
	}

	if (chatChoseFlage == 1) {
		DrawFormatString(68, 650, GetColor(0, 0, 0), "あんたが行けよ");
		DrawFormatString(350, 650, GetColor(0, 0, 0), "むり");
		DrawFormatString(68, 750, GetColor(0, 0, 0), "じゃ、行ってくるー");
		DrawFormatString(350, 750, GetColor(0, 0, 0), "いいよ");
	}

	if (chatChoseFlage == 2) {
		DrawFormatString(68, 650, GetColor(0, 0, 0), "じゃいがもと？");
		DrawFormatString(350, 650, GetColor(0, 0, 0), "むり");
		DrawFormatString(68, 750, GetColor(0, 0, 0), "うん");
		DrawFormatString(350, 750, GetColor(0, 0, 0), "じゃがいも？");
	}

	if (chatChoseFlage == 3) {
		DrawFormatString(68, 650, GetColor(0, 0, 0), "むり");
		DrawFormatString(350, 650, GetColor(0, 0, 0), "わかった");
		DrawFormatString(68, 750, GetColor(0, 0, 0), "むりだと思う");
		DrawFormatString(350, 750, GetColor(0, 0, 0), "むりかも");
	}

	if (chatChoseFlage == 4) {
		DrawFormatString(68, 650, GetColor(0, 0, 0), "たまねぎと");
		DrawFormatString(350, 650, GetColor(0, 0, 0), "じゃいがもと");
		DrawFormatString(68, 750, GetColor(0, 0, 0), "じゃがいもと");
		DrawFormatString(350, 750, GetColor(0, 0, 0), "じゃがりこと");
	}

	if (chatChoseFlage == 5) {
		DrawFormatString(68, 650, GetColor(0, 0, 0), "にんじんとぶたにく");
		DrawFormatString(350, 650, GetColor(0, 0, 0), "ぶたにくとカレー粉");
		DrawFormatString(68, 750, GetColor(0, 0, 0), "ぶたばことカレー粉");
		DrawFormatString(350, 750, GetColor(0, 0, 0), "にんじんとカレー粉");
	}

	if (chatChoseFlage == 6) {
		DrawFormatString(68, 650, GetColor(0, 0, 0), "はーい");
		DrawFormatString(350, 650, GetColor(0, 0, 0), "むりかも");
		DrawFormatString(68, 750, GetColor(0, 0, 0), "はーまいおにー");
		DrawFormatString(350, 750, GetColor(0, 0, 0), "いいえ");
	}
}