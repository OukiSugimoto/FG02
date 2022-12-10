#include "EnemyChat3.h"

EnemyChat3::EnemyChat3() {}
EnemyChat3::~EnemyChat3() {}

void EnemyChat3::Initialize() {
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

    for (int i = 1; i < 10; i++) {
        chatReceponFlag[i] = FALSE;
    }
}

void EnemyChat3::Update(char* keys, char* oldkeys) {

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
        chatAnser = 4;
        if (chatchose == chatAnser) {
            PlaySoundMem(chatReceponSe, DX_PLAYTYPE_BACK, FALSE);
            chatReceponFlag[1] = TRUE;
            chatReceponCount += 1;
        }

    }

    if (chatReceponCount == 1) {
        chatAnser = 2;
        if (chatchose == chatAnser) {
            PlaySoundMem(chatReceponSe, DX_PLAYTYPE_BACK, FALSE);
            chatReceponFlag[2] = TRUE;
            chatReceponCount += 1;
        }

    }

    if (chatReceponCount == 2) {
        chatAnser = 3;
        if (chatchose == chatAnser) {
            PlaySoundMem(chatReceponSe, DX_PLAYTYPE_BACK, FALSE);
            chatReceponFlag[3] = TRUE;
            chatReceponCount += 1;
        }
    }

    if (chatReceponCount == 3) {
        chatAnser = 1;
        if (chatchose == chatAnser) {
            PlaySoundMem(chatReceponSe, DX_PLAYTYPE_BACK, FALSE);
            chatReceponFlag[4] = TRUE;
            chatReceponCount += 1;

            ChatScrollY -= 50;
        }
    }

    if (chatReceponCount == 4) {
        chatAnser = 2;
        if (chatchose == chatAnser) {
            PlaySoundMem(chatReceponSe, DX_PLAYTYPE_BACK, FALSE);
            chatReceponFlag[5] = TRUE;
            chatReceponCount += 1;

            ChatScrollY -= 50;
        }
    }
}

void EnemyChat3::Draw() {

    if (chatReceponFlag[0] == TRUE) {
        DrawGraph(enemyPosX[0], enemyPosY[0] + ChatScrollY, chatReceponGraph, TRUE);
        DrawFormatString(enemyPosX[0] + 50, enemyPosY[0] + 50 + ChatScrollY, GetColor(0, 0, 0), "“y—j“ú—\’è‚ ‚éH");
    }

    if (chatReceponFlag[1] == TRUE) {
        DrawGraph(enemyPosX[1], enemyPosY[1] + ChatScrollY, chatReceponGraph, TRUE);
        DrawFormatString(enemyPosX[1] + 50, enemyPosY[1] + 50 + ChatScrollY, GetColor(0, 0, 0), "‚â‚Á‚Ï‚¢‚¢‚íA\n‚È‚ñ‚Å‚à‚È‚¢");
    }

    if (chatReceponFlag[2] == TRUE) {
        DrawGraph(enemyPosX[2], enemyPosY[2] + ChatScrollY, chatReceponGraph, TRUE);
        DrawFormatString(enemyPosX[2] + 50, enemyPosY[2] + 50 + ChatScrollY, GetColor(0, 0, 0), "‘O˜b‚µ‚½A‰f‰æ\nŒ©‚És‚©‚È‚¢H");
    }

    if (chatReceponFlag[3] == TRUE) {
        DrawGraph(enemyPosX[3], enemyPosY[3] + ChatScrollY, chatReceponGraph, TRUE);
        DrawFormatString(enemyPosX[3] + 50, enemyPosY[3] + 50 + ChatScrollY, GetColor(0, 0, 0), "‚æ‚©‚Á‚½");
    }

    if (chatReceponFlag[4] == TRUE) {
        DrawGraph(enemyPosX[4], enemyPosY[4] + ChatScrollY, chatReceponGraph, TRUE);
        DrawFormatString(enemyPosX[4] + 50, enemyPosY[4] + 50 + ChatScrollY, GetColor(0, 0, 0), "‚¶‚áA‚Ü‚½–¾“ú‚Ë");
    }

}