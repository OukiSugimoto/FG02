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

	chatReceponFlag[0] = TRUE;

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
	
}

void EnemyChat::Draw() {
	    if (chatReceponFlag[0] == TRUE) {
			DrawGraph(enemyPosX[0], enemyPosY[0] + ChatScrollY, chatReceponGraph, TRUE);
			DrawFormatString(enemyPosX[0] + 50, enemyPosY[0] + 50 + ChatScrollY, GetColor(0, 0, 0), "‚¨‚Í‚æ");

			DrawFormatString(68, 650, GetColor(0, 0, 0), "‚¨‚Í‚æ");
			DrawFormatString(350, 650, GetColor(0, 0, 0), "‚¢‚½‚¢");
			DrawFormatString(68, 750, GetColor(0, 0, 0), "‚â‚¾");
			DrawFormatString(350, 750, GetColor(0, 0, 0), "‚Î‚Â‚¾‚©‚ç");
	    }
		
		if (chatReceponFlag[1] == TRUE) {
			DrawGraph(enemyPosX[1], enemyPosY[1] + ChatScrollY, chatReceponGraph, TRUE);
		}
		
		if (chatReceponFlag[2] == TRUE) {
			DrawGraph(enemyPosX[2], enemyPosY[2] + ChatScrollY, chatReceponGraph, TRUE);
		}

		if (chatReceponFlag[3] == TRUE) {
			DrawGraph(enemyPosX[3], enemyPosY[3] + ChatScrollY, chatReceponGraph, TRUE);
		}

		//DrawFormatString(100,100,GetColor(255,255,255),"flag = %d",chatReceponFlag1);

}