#include "EnemyChat4.h"

EnemyChat4::EnemyChat4() {}
EnemyChat4::~EnemyChat4() {}

void EnemyChat4::Initialize() {
    enemyPosX[0] = 20;        enemyPosX[1] = 20;
    enemyPosY[0] = 90;        enemyPosY[1] = 190;

    enemyPosX[2] = 20;        enemyPosX[3] = 20;
    enemyPosY[2] = 290;       enemyPosY[3] = 390;

    enemyPosX[4] = 20;        enemyPosX[5] = 20;
    enemyPosY[4] = 490;       enemyPosY[5] = 590;

    enemyPosX[6] = 20;        enemyPosX[7] = 20;
    enemyPosY[6] = 690;       enemyPosY[7] = 790;

    enemyPosX[8] = 20;        enemyPosX[9] = 20;
    enemyPosY[8] = 890;       enemyPosY[9] = 990;

    chatReceponCount = 0;

    chatReceponFlag[0] = TRUE;

    ChatScrollY = 0;

    chatchose = 0;

    chatChoseFlage = 0;

    chatBranchFlage = 0;

    chatBranchNumber = 0;

    for (int i = 1; i < 10; i++) {
        chatReceponFlag[i] = FALSE;
    }
}

void EnemyChat4::Update(char* keys, char* oldkeys) {

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

    if (chatSendFlag[0] == TRUE) {
        chatReceponFlag[1] = TRUE;
    }

    if (chatSendFlag[1] == TRUE) {
        chatReceponFlag[2] = TRUE;
    }

    if (chatSendFlag[2] == TRUE) {
        chatReceponFlag[3] = TRUE;
    }

    if (chatSendFlag[3] == TRUE) {
        chatReceponFlag[4] = TRUE;
    }

    if (chatSendFlag[4] == TRUE) {
        chatReceponFlag[5] = TRUE;
    }

    if (chatReceponCount == 0) {
        chatAnser = 1;
        if (chatchose == chatAnser) {
            if (CheckSoundMem(chatReceponSe) == 0) {
                PlaySoundMem(chatReceponSe, DX_PLAYTYPE_BACK, TRUE);
            }
            chatReceponFlag[1] = TRUE;
            chatReceponCount += 1;
        }

    }

    if (chatReceponCount == 1) {
        chatAnser = 3;
        if (chatchose == chatAnser) {
            if (CheckSoundMem(chatReceponSe) == 0) {
                PlaySoundMem(chatReceponSe, DX_PLAYTYPE_BACK, TRUE);
            }
            chatReceponFlag[2] = TRUE;
            chatReceponCount += 1;
        }

    }

    if (chatReceponCount == 2) {
        chatAnser = 2;
        if (chatchose == chatAnser) {
            if (CheckSoundMem(chatReceponSe) == 0) {
                PlaySoundMem(chatReceponSe, DX_PLAYTYPE_BACK, TRUE);
            }
            chatReceponFlag[3] = TRUE;
            chatReceponCount += 1;
        }
    }

    if (chatReceponCount == 3) {
        chatAnser = 1;
        if (chatchose == chatAnser) {
            if (CheckSoundMem(chatReceponSe) == 0) {
                PlaySoundMem(chatReceponSe, DX_PLAYTYPE_BACK, TRUE);
            }
            chatReceponFlag[4] = TRUE;
            chatReceponCount += 1;

            ChatScrollY -= 50;
        }
    }

    if (chatReceponCount == 4) {
        chatAnser = 4;
        if (chatchose == chatAnser) {
            if (CheckSoundMem(chatReceponSe) == 0) {
                PlaySoundMem(chatReceponSe, DX_PLAYTYPE_BACK, TRUE);
            }
            chatReceponFlag[5] = TRUE;
            chatReceponCount += 1;

            ChatScrollY -= 50;
        }
    }

    if (chatReceponCount == 5) {
        chatAnser = 2;
        if (chatchose == chatAnser) {
            if (CheckSoundMem(chatReceponSe) == 0) {
                PlaySoundMem(chatReceponSe, DX_PLAYTYPE_BACK, TRUE);
            }
            chatReceponFlag[6] = TRUE;
            chatReceponCount += 1;

            chatFalse = 2;

            ChatScrollY -= 50;
        }
    }
}




void EnemyChat4::Draw() {

    if (chatReceponFlag[0] == TRUE) {
        DrawGraph(enemyPosX[0], enemyPosY[0] + ChatScrollY, chatReceponGraph, TRUE);
        DrawFormatString(enemyPosX[0] + 50, enemyPosY[0] + 50 + ChatScrollY, GetColor(0, 0, 0), "‚à‚¤‚Â‚¢‚½H");
    }

    if (chatReceponFlag[1] == TRUE) {
        DrawGraph(enemyPosX[1], enemyPosY[1] + ChatScrollY, chatReceponGraph, TRUE);
        DrawFormatString(enemyPosX[1] + 50, enemyPosY[1] + 50 + ChatScrollY, GetColor(0, 0, 0), "‚¨‚Á‚¯[A‘Ò‚Á‚Ä‚é");
    }

    if (chatReceponFlag[2] == TRUE) {
        DrawGraph(enemyPosX[2], enemyPosY[2] + ChatScrollY, chatReceponGraph, TRUE);
        DrawFormatString(enemyPosX[2] + 50, enemyPosY[2] + 50 + ChatScrollY, GetColor(0, 0, 0), "‚à‚¤‰f‰æ\n‚Í‚¶‚Ü‚é‚æH");
    }

    if (chatReceponFlag[3] == TRUE) {
        DrawGraph(enemyPosX[3], enemyPosY[3] + ChatScrollY, chatReceponGraph, TRUE);
        DrawFormatString(enemyPosX[3] + 50, enemyPosY[3] + 10 + ChatScrollY, GetColor(0, 0, 0), "`2ŽžŠÔŒã`");
        DrawFormatString(enemyPosX[3] + 50, enemyPosY[3] + 50 + ChatScrollY, GetColor(0, 0, 0), "‚à‚¤‰f‰æ\nI‚í‚Á‚¿‚á‚½‚æ");
    }

    if (chatReceponFlag[4] == TRUE) {
        DrawGraph(enemyPosX[4], enemyPosY[4] + ChatScrollY, chatReceponGraph, TRUE);
        DrawFormatString(enemyPosX[4] + 50, enemyPosY[4] + 50 + ChatScrollY, GetColor(0, 0, 0), "‚¦H");
    }

    if (chatReceponFlag[5] == TRUE) {
        DrawGraph(enemyPosX[5], enemyPosY[5] + ChatScrollY, chatReceponGraph, TRUE);
        DrawFormatString(enemyPosX[5] + 50, enemyPosY[5] + 50 + ChatScrollY, GetColor(0, 0, 0), "‚¤‚»‚Å‚µ‚å");
    }
}