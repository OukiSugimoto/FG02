#include "PlayerChat4.h"
void PlayerChat4::Initialize() {
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

void PlayerChat4::ChatLike() {
	chatchose = 0;

	ChatLikePoint -= 20;

	if (CheckSoundMem(chatFalseSe) == 0) {
		PlaySoundMem(chatFalseSe, DX_PLAYTYPE_BACK, TRUE);
	}

	if (ChatLikePoint == 0) {
		chatFalse = 1;
	}
}

void PlayerChat4::Update(char* keys, char* oldkeys) {
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
		chatAnser = 1;

		if (chatchose == chatAnser) {
			count = 1;
			chatchose = 0;
			chatSendFlag[0] = TRUE;
			chatChoseFlage = 1;
			chatSendCount += 1;

		}

		if (chatchose == 2 || chatchose == 3 || chatchose == 4) {
			ChatLike();
		}

	}

	if (chatSendCount == 1) {

		chatAnser = 3;

		if (chatchose == chatAnser) {
			count = 1;
			chatchose = 0;
			chatSendFlag[1] = TRUE;
			chatChoseFlage = 2;
			chatSendCount += 1;
		}

		if (chatchose == 2 || chatchose == 1 || chatchose == 4) {
			ChatLike();
		}

	}

	if (chatSendCount == 2) {
		chatAnser = 2;

		if (chatchose == chatAnser) {
			count = 1;
			chatSendFlag[2] = TRUE;
			chatchose = 0;
			chatChoseFlage = 3;
			chatSendCount += 1;
		}

		if (chatchose == 1 || chatchose == 3 || chatchose == 4) {
			ChatLike();
		}

	}

	if (chatSendCount == 3) {
		chatAnser = 1;


		if (chatchose == chatAnser) {
			count = 1;
			chatchose = 0;
			chatSendFlag[3] = TRUE;
			chatChoseFlage = 4;
			chatSendCount += 1;

			ChatScrollY -= 50;
		}

		if (chatchose == 2 || chatchose == 3 || chatchose == 4) {
			ChatLike();
		}

	}

	if (chatSendCount == 4) {

		chatAnser = 4;

		if (chatchose == chatAnser) {
			count = 1;

			chatSendFlag[4] = TRUE;
			chatSendCount += 1;
			chatChoseFlage = 5;
			ChatScrollY -= 50;
			chatchose = 0;

		}


		if (chatchose == 2 || chatchose == 3 || chatchose == 1) {
			ChatLike();
		}

	}

	if (chatSendCount == 5) {

		chatAnser = 2;

		if (chatchose == chatAnser) {
			count = 1;

			chatSendFlag[5] = TRUE;
			chatSendCount += 1;
			chatChoseFlage = 6;
			ChatScrollY -= 50;
			chatchose = 0;

			chatFalse = 2;
		}

		if (chatchose == 4 || chatchose == 3 || chatchose == 1) {
			ChatLike();
		}

	}
}

void PlayerChat4::Draw() {
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
		DrawFormatString(playerPosX[0] + 50, playerPosY[0] + 50 + ChatScrollY, GetColor(0, 0, 0), "ごめん、もうちょい");

	}

	if (chatSendFlag[1] == TRUE) {
		DrawGraph(playerPosX[1], playerPosY[1] + ChatScrollY, chatSendGraph, TRUE);

		DrawFormatString(playerPosX[1] + 50, playerPosY[1] + 50 + ChatScrollY, GetColor(0, 0, 0), "ありがとー");

	}

	if (chatSendFlag[2] == TRUE) {
		DrawGraph(playerPosX[2], playerPosY[2] + ChatScrollY, chatSendGraph, TRUE);

		DrawFormatString(playerPosX[2] + 50, playerPosY[2] + 50 + ChatScrollY, GetColor(0, 0, 0), "あーごめん、\nまだかも");

	}

	if (chatSendFlag[3] == TRUE) {
		DrawGraph(playerPosX[3], playerPosY[3] + ChatScrollY, chatSendGraph, TRUE);

		DrawFormatString(playerPosX[3] + 50, playerPosY[3] + 50 + ChatScrollY, GetColor(0, 0, 0), "まだ気づかないのww");
	}

	if (chatSendFlag[4] == TRUE) {
		DrawGraph(playerPosX[4], playerPosY[4] + ChatScrollY, chatSendGraph, TRUE);

		DrawFormatString(playerPosX[4] + 50, playerPosY[4] + 50 + ChatScrollY, GetColor(0, 0, 0), "映画行くの\n明日だよ？");
	}

	if (chatSendFlag[5] == TRUE) {
		DrawGraph(playerPosX[5], playerPosY[5] + ChatScrollY, chatSendGraph, TRUE);
		DrawFormatString(playerPosX[5] + 50, playerPosY[5] + 50 + ChatScrollY, GetColor(0, 0, 0), "じゃーまた明日ねー");

	}

	if (chatChoseFlage == 0) {
		DrawFormatString(68, 650, GetColor(0, 0, 0), "ごめん、もうちょい");
		DrawFormatString(350, 650, GetColor(0, 0, 0), "今起きた");
		DrawFormatString(68, 750, GetColor(0, 0, 0), "もうつくよ！");
		DrawFormatString(350, 750, GetColor(0, 0, 0), "うん、楽しみ");
	}

	if (chatChoseFlage == 1) {
		DrawFormatString(68, 650, GetColor(0, 0, 0), "ごめんねm(__)m");
		DrawFormatString(350, 650, GetColor(0, 0, 0), "楽しみだね");
		DrawFormatString(68, 750, GetColor(0, 0, 0), "ありがとー");
		DrawFormatString(350, 750, GetColor(0, 0, 0), "うん！！");
	}

	if (chatChoseFlage == 2) {
		DrawFormatString(68, 650, GetColor(0, 0, 0), "いまついた！！");
		DrawFormatString(350, 650, GetColor(0, 0, 0), "あーごめん、\nまだかも");
		DrawFormatString(68, 750, GetColor(0, 0, 0), "今日映画なの？");
		DrawFormatString(350, 750, GetColor(0, 0, 0), "今日何見る？");
	}

	if (chatChoseFlage == 3) {
		DrawFormatString(68, 650, GetColor(0, 0, 0), "まだ気づかないのww");
		DrawFormatString(350, 650, GetColor(0, 0, 0), "おもしろかった？");
		DrawFormatString(68, 750, GetColor(0, 0, 0), "ごめん、\nそろそろつく！！");
		DrawFormatString(350, 750, GetColor(0, 0, 0), "何の映画見た？");
	}

	if (chatChoseFlage == 4) {
		DrawFormatString(68, 650, GetColor(0, 0, 0), "一人で見れば\nよかったのに");
		DrawFormatString(350, 650, GetColor(0, 0, 0), "うしろ見てみて");
		DrawFormatString(68, 750, GetColor(0, 0, 0), "え？");
		DrawFormatString(350, 750, GetColor(0, 0, 0), "映画行くの\n明日だよ？");
	}

	if (chatChoseFlage == 5) {
		DrawFormatString(68, 650, GetColor(0, 0, 0), "楽しかった？");
		DrawFormatString(350, 650, GetColor(0, 0, 0), "じゃーまた明日ねー");
		DrawFormatString(68, 750, GetColor(0, 0, 0), "嘘だよ");
		DrawFormatString(350, 750, GetColor(0, 0, 0), "うしろうしろ");
	}
}