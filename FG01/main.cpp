#include "DxLib.h"
#include"talk.h"
#include"Level.h"
#include"PlayerChat.h"
#include"PlayerChat2.h"
#include"PlayerChat3.h"
#include"PlayerChat4.h"
#include"EnemyChat.h"
#include"EnemyChat2.h"
#include"EnemyChat3.h"
#include"EnemyChat4.h"

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "07_connect mail";

// �E�B���h�E����
const int WIN_WIDTH = 600;
// �E�B���h�E�c��
const int WIN_HEIGHT = 900;

enum GAMESCENE
{
	Title,
	Ruru,
	End,
	Clear,
	Level1,
	Level2,
	Level3,
	Level4
};

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	
	ChangeWindowMode(TRUE);                   // �E�B���h�E���[�h�ɐݒ�
	SetWindowSizeChangeEnableFlag(true, true);// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetMainWindowText(TITLE);                 // �^�C�g����ύX
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);  // ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetWindowSizeExtendRate(1.0);             // ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetBackgroundColor(0, 0, 0);     // ��ʂ̔w�i�F��ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);            // (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetFontSize(20);
	if (DxLib_Init() == -1) { return -1; }    // DXlib�̏�����

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���
	int backGraph = LoadGraph("Resource\\back.png");
	int textGraph = LoadGraph("Resource\\text.png");
	int titleGraph = LoadGraph("Resource\\title.png");
	int endGraph = LoadGraph("Resource\\end.png");
	int clearGraph = LoadGraph("Resource\\clear.png");
	int ruruGraph = LoadGraph("Resource\\ru-ru.png");
	int kikenGraph = LoadGraph("Resource\\kiken.png");

	int gameBGM = LoadSoundMem("Resource\\BGM.mp3");
	int kikenBGM = LoadSoundMem("Resource\\keihou.mp3");
	int clearBGM = LoadSoundMem("Resource\\omedetou.mp3");
	// �Q�[�����[�v�Ŏg���ϐ��̐錾
	int sceneState = 0;

	Talk* talk_ = new Talk;
	Level* level_ = new Level;

	PlayerChat* playerchat_ = new PlayerChat;
	PlayerChat2* playerchat2_ = new PlayerChat2;
	PlayerChat3* playerchat3_ = new PlayerChat3;
	PlayerChat4* playerchat4_ = new PlayerChat4;
	

	EnemyChat* enemychat_ = new EnemyChat;
	EnemyChat2* enemychat2_ = new EnemyChat2;
	EnemyChat3* enemychat3_ = new EnemyChat3;
	EnemyChat4* enemychat4_ = new EnemyChat4;
	

	//�^�C�}�[
	int alpha = 20;

	char keys[256] = { 0 };   // �ŐV�̃L�[�{�[�h���p
	char oldkeys[256] = { 0 };// 1���[�v(�t���[��)�O�̃L�[�{�[�h���

	// �Q�[�����[�v
	while (true)
	{
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		for (int i = 0; i < 256; i++)
		{
			oldkeys[i] = keys[i];
		}
		GetHitKeyStateAll(keys);// �ŐV�̃L�[�{�[�h�����擾
		ClearDrawScreen();      // ��ʃN���A

		//---------  ��������v���O�������L�q  ----------//

		// �X�V����

		switch (sceneState)
		{
		case Title:
			talk_->Initialize();

			playerchat_->Initialize();

			playerchat2_->Initialize();
			
			playerchat3_->Initialize();

			playerchat4_->Initialize();

			enemychat_->Initialize();

			enemychat2_->Initialize();

			enemychat3_->Initialize();

			enemychat4_->Initialize();

			level_->Initialize();

			alpha = 0;

			DrawGraph(0,0,titleGraph,TRUE);

			StopSoundMem(kikenBGM);
			StopSoundMem(clearBGM);
		
			if (CheckSoundMem(gameBGM) == 0) {
				PlaySoundMem(gameBGM, DX_PLAYTYPE_LOOP, TRUE);
			}

			if (keys[KEY_INPUT_SPACE] == TRUE && oldkeys[KEY_INPUT_SPACE] == FALSE) {
				sceneState = Ruru;
			}
			break;
		case Ruru:
			DrawGraph(0, 0, ruruGraph, TRUE);

			level_->Update(keys, oldkeys);

			level_->Draw();

			if (keys[KEY_INPUT_SPACE] == TRUE && oldkeys[KEY_INPUT_SPACE] == FALSE) {
				sceneState = level_->levelNumber;
			}
			break;
		case Level1:
			playerchat_->Update(keys, oldkeys);

			enemychat_->Update(keys, oldkeys);

			if (playerchat_->chatFalse == 1) {
				sceneState = End;
			}
			if (playerchat_->chatFalse == 2) {
				sceneState = Clear;
			}
			break;
		case Level2:
			playerchat2_->Update(keys, oldkeys);

			enemychat2_->Update(keys, oldkeys);

			if (playerchat2_->chatFalse == 1) {
				sceneState = End;
			}
			if (playerchat2_->chatFalse == 2) {
				sceneState = Clear;
			}
			break;
		case Level3:
			playerchat3_->Update(keys, oldkeys);

			enemychat3_->Update(keys, oldkeys);

			if (playerchat3_->chatFalse == 1) {
				sceneState = End;
			}
			if (playerchat3_->chatFalse == 2) {
				sceneState = Clear;
			}
			break;
		case Level4:
			playerchat4_->Update(keys, oldkeys);

			enemychat4_->Update(keys, oldkeys);

			if (playerchat4_->chatFalse == 1) {
				sceneState = End;
			}
			if (playerchat4_->chatFalse == 2) {
				sceneState = Clear;
			}
			break;
		case End:
			DrawGraph(0, 0, endGraph, TRUE);
			if (keys[KEY_INPUT_SPACE] == TRUE && oldkeys[KEY_INPUT_SPACE] == FALSE) {
				sceneState = Title;
			}
			break;

		case Clear:
			StopSoundMem(kikenBGM);
			StopSoundMem(gameBGM);
			if (CheckSoundMem(clearBGM) == 0) {
				PlaySoundMem(clearBGM, DX_PLAYTYPE_BACK, TRUE);
			}
			

			DrawGraph(0, 0, clearGraph, TRUE);
			if (keys[KEY_INPUT_SPACE] == TRUE && oldkeys[KEY_INPUT_SPACE] == FALSE) {
				sceneState = Title;
			}
			break;
		}

		// �`�揈��

		if (sceneState == Level1) {
			talk_->Draw();

			playerchat_->Draw();

			enemychat_->Draw();

			DrawGraph(0, 0, backGraph, TRUE);
			
		}
		
		if (sceneState == Level2) {
			talk_->Draw();

			playerchat2_->Draw();

			enemychat2_->Draw();

			DrawGraph(0, 0, backGraph, TRUE);

		}

		if (sceneState == Level3) {
			talk_->Draw();

			playerchat3_->Draw();

			enemychat3_->Draw();

			DrawGraph(0, 0, backGraph, TRUE);

		}

		if (sceneState == Level4) {
			talk_->Draw();

			playerchat4_->Draw();

			enemychat4_->Draw();

			DrawGraph(0, 0, backGraph, TRUE);

		}


		if (Level1 <= sceneState) {
			DrawGraph(18, 69, textGraph, TRUE);
			if (sceneState == Level1) {
				if (playerchat_->ChatLikePoint == 100) {
					DrawGraph(playerchat_->playerHpPosX[0], playerchat_->playerHpPosY[0], playerchat_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat_->playerHpPosX[1], playerchat_->playerHpPosY[1], playerchat_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat_->playerHpPosX[2], playerchat_->playerHpPosY[2], playerchat_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat_->playerHpPosX[3], playerchat_->playerHpPosY[3], playerchat_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat_->playerHpPosX[4], playerchat_->playerHpPosY[4], playerchat_->PlayerLifeGraph, TRUE);
				}
			}

			if (sceneState == Level2) {
				if (playerchat2_->ChatLikePoint == 100) {
					DrawGraph(playerchat2_->playerHpPosX[0], playerchat2_->playerHpPosY[0], playerchat2_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat2_->playerHpPosX[1], playerchat2_->playerHpPosY[1], playerchat2_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat2_->playerHpPosX[2], playerchat2_->playerHpPosY[2], playerchat2_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat2_->playerHpPosX[3], playerchat2_->playerHpPosY[3], playerchat2_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat2_->playerHpPosX[4], playerchat2_->playerHpPosY[4], playerchat2_->PlayerLifeGraph, TRUE);
				}
			}
			
			if (sceneState == Level3) {
				if (playerchat3_->ChatLikePoint == 100) {
					DrawGraph(playerchat3_->playerHpPosX[0], playerchat3_->playerHpPosY[0], playerchat3_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat3_->playerHpPosX[1], playerchat3_->playerHpPosY[1], playerchat3_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat3_->playerHpPosX[2], playerchat3_->playerHpPosY[2], playerchat3_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat3_->playerHpPosX[3], playerchat3_->playerHpPosY[3], playerchat3_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat3_->playerHpPosX[4], playerchat3_->playerHpPosY[4], playerchat3_->PlayerLifeGraph, TRUE);
				}
			}
			
			if (sceneState == Level4) {
				if (playerchat4_->ChatLikePoint == 100) {
					DrawGraph(playerchat4_->playerHpPosX[0], playerchat4_->playerHpPosY[0], playerchat4_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat4_->playerHpPosX[1], playerchat4_->playerHpPosY[1], playerchat4_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat4_->playerHpPosX[2], playerchat4_->playerHpPosY[2], playerchat4_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat4_->playerHpPosX[3], playerchat4_->playerHpPosY[3], playerchat4_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat4_->playerHpPosX[4], playerchat4_->playerHpPosY[4], playerchat4_->PlayerLifeGraph, TRUE);
				}
			}
			
			if (sceneState == Level1) {
				if (playerchat_->ChatLikePoint == 80) {
					playerchat_->AnimeTime++;

					if (playerchat_->count == 0) {

						if (playerchat_->AnimeTime >= 7)
						{
							playerchat_->index = (playerchat_->index + 1) % 7;

							playerchat_->AnimeTime = 0;

						}
					}
					if (playerchat_->index >= 6) {
						playerchat_->count += 1;
					}

					DrawGraph(playerchat_->playerHpPosX[0], playerchat_->playerHpPosY[0], playerchat_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat_->playerHpPosX[1], playerchat_->playerHpPosY[1], playerchat_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat_->playerHpPosX[2], playerchat_->playerHpPosY[2], playerchat_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat_->playerHpPosX[3], playerchat_->playerHpPosY[3], playerchat_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat_->playerHpPosX[4], playerchat_->playerHpPosY[4], playerchat_->Animes[playerchat_->index], TRUE);
				}
			}
			if (sceneState == Level2) {
				if (playerchat2_->ChatLikePoint == 80) {
					playerchat2_->AnimeTime++;

					if (playerchat2_->count == 0) {

						if (playerchat2_->AnimeTime >= 7)
						{
							playerchat2_->index = (playerchat2_->index + 1) % 7;

							playerchat2_->AnimeTime = 0;

						}
					}
					if (playerchat2_->index >= 6) {
						playerchat2_->count += 1;
					}

					DrawGraph(playerchat2_->playerHpPosX[0], playerchat2_->playerHpPosY[0], playerchat2_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat2_->playerHpPosX[1], playerchat2_->playerHpPosY[1], playerchat2_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat2_->playerHpPosX[2], playerchat2_->playerHpPosY[2], playerchat2_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat2_->playerHpPosX[3], playerchat2_->playerHpPosY[3], playerchat2_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat2_->playerHpPosX[4], playerchat2_->playerHpPosY[4], playerchat2_->Animes[playerchat2_->index], TRUE);
				}
			}
			if (sceneState == Level3) {
				if (playerchat3_->ChatLikePoint == 80) {
					playerchat3_->AnimeTime++;

					if (playerchat3_->count == 0) {

						if (playerchat3_->AnimeTime >= 7)
						{
							playerchat3_->index = (playerchat3_->index + 1) % 7;

							playerchat3_->AnimeTime = 0;

						}
					}
					if (playerchat3_->index >= 6) {
						playerchat3_->count += 1;
					}

					DrawGraph(playerchat3_->playerHpPosX[0], playerchat3_->playerHpPosY[0], playerchat3_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat3_->playerHpPosX[1], playerchat3_->playerHpPosY[1], playerchat3_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat3_->playerHpPosX[2], playerchat3_->playerHpPosY[2], playerchat3_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat3_->playerHpPosX[3], playerchat3_->playerHpPosY[3], playerchat3_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat3_->playerHpPosX[4], playerchat3_->playerHpPosY[4], playerchat3_->Animes[playerchat3_->index], TRUE);
				}
			}
			if (sceneState == Level4) {
				if (playerchat4_->ChatLikePoint == 80) {
					playerchat4_->AnimeTime++;

					if (playerchat4_->count == 0) {

						if (playerchat4_->AnimeTime >= 7)
						{
							playerchat4_->index = (playerchat4_->index + 1) % 7;

							playerchat4_->AnimeTime = 0;

						}
					}
					if (playerchat4_->index >= 6) {
						playerchat4_->count += 1;
					}

					DrawGraph(playerchat4_->playerHpPosX[0], playerchat4_->playerHpPosY[0], playerchat4_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat4_->playerHpPosX[1], playerchat4_->playerHpPosY[1], playerchat4_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat4_->playerHpPosX[2], playerchat4_->playerHpPosY[2], playerchat4_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat4_->playerHpPosX[3], playerchat4_->playerHpPosY[3], playerchat4_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat4_->playerHpPosX[4], playerchat4_->playerHpPosY[4], playerchat4_->Animes[playerchat4_->index], TRUE);
				}
			}
			
			if (sceneState == Level1) {
				if (playerchat_->ChatLikePoint == 60) {
					playerchat_->AnimeTime++;

					if (playerchat_->count == 0) {

						if (playerchat_->AnimeTime >= 7)
						{
							playerchat_->index = (playerchat_->index + 1) % 7;

							playerchat_->AnimeTime = 0;

						}
					}
					if (playerchat_->index >= 6) {
						playerchat_->count += 1;
					}

					DrawGraph(playerchat_->playerHpPosX[0], playerchat_->playerHpPosY[0], playerchat_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat_->playerHpPosX[1], playerchat_->playerHpPosY[1], playerchat_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat_->playerHpPosX[2], playerchat_->playerHpPosY[2], playerchat_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat_->playerHpPosX[3], playerchat_->playerHpPosY[3], playerchat_->Animes[playerchat_->index], TRUE);
				}
			}
			if (sceneState == Level2) {
				if (playerchat2_->ChatLikePoint == 60) {
					playerchat2_->AnimeTime++;

					if (playerchat2_->count == 0) {

						if (playerchat2_->AnimeTime >= 7)
						{
							playerchat2_->index = (playerchat2_->index + 1) % 7;

							playerchat2_->AnimeTime = 0;

						}
					}
					if (playerchat2_->index >= 6) {
						playerchat2_->count += 1;
					}

					DrawGraph(playerchat2_->playerHpPosX[0], playerchat2_->playerHpPosY[0], playerchat2_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat2_->playerHpPosX[1], playerchat2_->playerHpPosY[1], playerchat2_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat2_->playerHpPosX[2], playerchat2_->playerHpPosY[2], playerchat2_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat2_->playerHpPosX[3], playerchat2_->playerHpPosY[3], playerchat2_->Animes[playerchat2_->index], TRUE);
				}
			}
			if (sceneState == Level3) {
				if (playerchat3_->ChatLikePoint == 60) {
					playerchat3_->AnimeTime++;

					if (playerchat3_->count == 0) {

						if (playerchat3_->AnimeTime >= 7)
						{
							playerchat3_->index = (playerchat3_->index + 1) % 7;

							playerchat3_->AnimeTime = 0;

						}
					}
					if (playerchat3_->index >= 6) {
						playerchat3_->count += 1;
					}

					DrawGraph(playerchat3_->playerHpPosX[0], playerchat3_->playerHpPosY[0], playerchat3_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat3_->playerHpPosX[1], playerchat3_->playerHpPosY[1], playerchat3_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat3_->playerHpPosX[2], playerchat3_->playerHpPosY[2], playerchat3_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat3_->playerHpPosX[3], playerchat3_->playerHpPosY[3], playerchat3_->Animes[playerchat3_->index], TRUE);
				}
			}
			if (sceneState == Level4) {
				if (playerchat4_->ChatLikePoint == 60) {
					playerchat4_->AnimeTime++;

					if (playerchat4_->count == 0) {

						if (playerchat4_->AnimeTime >= 7)
						{
							playerchat4_->index = (playerchat4_->index + 1) % 7;

							playerchat4_->AnimeTime = 0;

						}
					}
					if (playerchat4_->index >= 6) {
						playerchat4_->count += 1;
					}

					DrawGraph(playerchat4_->playerHpPosX[0], playerchat4_->playerHpPosY[0], playerchat4_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat4_->playerHpPosX[1], playerchat4_->playerHpPosY[1], playerchat4_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat4_->playerHpPosX[2], playerchat4_->playerHpPosY[2], playerchat4_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat4_->playerHpPosX[3], playerchat4_->playerHpPosY[3], playerchat4_->Animes[playerchat4_->index], TRUE);
				}
			}
			
			if (sceneState == Level1) {
				if (playerchat_->ChatLikePoint == 40) {
					playerchat_->AnimeTime++;

					if (playerchat_->count == 0) {

						if (playerchat_->AnimeTime >= 7)
						{
							playerchat_->index = (playerchat_->index + 1) % 7;

							playerchat_->AnimeTime = 0;

						}
					}
					if (playerchat_->index >= 6) {
						playerchat_->count += 1;
					}

					DrawGraph(playerchat_->playerHpPosX[0], playerchat_->playerHpPosY[0], playerchat_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat_->playerHpPosX[1], playerchat_->playerHpPosY[1], playerchat_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat_->playerHpPosX[2], playerchat_->playerHpPosY[2], playerchat_->Animes[playerchat_->index], TRUE);
				}
			}
			if (sceneState == Level2) {
				if (playerchat2_->ChatLikePoint == 40) {
					playerchat2_->AnimeTime++;

					if (playerchat2_->count == 0) {

						if (playerchat2_->AnimeTime >= 7)
						{
							playerchat2_->index = (playerchat2_->index + 1) % 7;

							playerchat2_->AnimeTime = 0;

						}
					}
					if (playerchat2_->index >= 6) {
						playerchat2_->count += 1;
					}

					DrawGraph(playerchat2_->playerHpPosX[0], playerchat2_->playerHpPosY[0], playerchat2_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat2_->playerHpPosX[1], playerchat2_->playerHpPosY[1], playerchat2_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat2_->playerHpPosX[2], playerchat2_->playerHpPosY[2], playerchat2_->Animes[playerchat2_->index], TRUE);
				}
			}
			if (sceneState == Level3) {
				if (playerchat3_->ChatLikePoint == 40) {
					playerchat3_->AnimeTime++;

					if (playerchat3_->count == 0) {

						if (playerchat3_->AnimeTime >= 7)
						{
							playerchat3_->index = (playerchat3_->index + 1) % 7;

							playerchat3_->AnimeTime = 0;

						}
					}
					if (playerchat3_->index >= 6) {
						playerchat3_->count += 1;
					}

					DrawGraph(playerchat3_->playerHpPosX[0], playerchat3_->playerHpPosY[0], playerchat3_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat3_->playerHpPosX[1], playerchat3_->playerHpPosY[1], playerchat3_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat3_->playerHpPosX[2], playerchat3_->playerHpPosY[2], playerchat3_->Animes[playerchat3_->index], TRUE);
				}
			}
			if (sceneState == Level4) {
				if (playerchat4_->ChatLikePoint == 40) {
					playerchat4_->AnimeTime++;

					if (playerchat4_->count == 0) {

						if (playerchat4_->AnimeTime >= 7)
						{
							playerchat4_->index = (playerchat4_->index + 1) % 7;

							playerchat4_->AnimeTime = 0;

						}
					}
					if (playerchat4_->index >= 6) {
						playerchat4_->count += 1;
					}

					DrawGraph(playerchat4_->playerHpPosX[0], playerchat4_->playerHpPosY[0], playerchat4_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat4_->playerHpPosX[1], playerchat4_->playerHpPosY[1], playerchat4_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat4_->playerHpPosX[2], playerchat4_->playerHpPosY[2], playerchat4_->Animes[playerchat4_->index], TRUE);
				}
			}
			
			if (sceneState == Level1) {
				if (playerchat_->ChatLikePoint == 20) {
					playerchat_->AnimeTime++;

					if (playerchat_->count == 0) {
						if (playerchat_->AnimeTime >= 7)
						{
							playerchat_->index = (playerchat_->index + 1) % 7;

							playerchat_->AnimeTime = 0;

						}
					}
					if (playerchat_->index >= 6) {
						playerchat_->count += 1;
					}

					DrawGraph(playerchat_->playerHpPosX[0] + playerchat_->shakeChat, playerchat_->playerHpPosY[0], playerchat_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat_->playerHpPosX[1], playerchat_->playerHpPosY[1], playerchat_->Animes[playerchat_->index], TRUE);

					alpha += 2;

					if (alpha >= 120) {
						alpha = 40;
					}

					StopSoundMem(gameBGM);
					PlaySoundMem(kikenBGM, DX_PLAYTYPE_LOOP, FALSE);

					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
					DrawGraph(18, 69, textGraph, TRUE);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

					SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
					DrawGraph(18, 69, kikenGraph, TRUE);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				}
			}
			if (sceneState == Level2) {
				if (playerchat2_->ChatLikePoint == 20) {
					playerchat2_->AnimeTime++;

					if (playerchat2_->count == 0) {
						if (playerchat2_->AnimeTime >= 7)
						{
							playerchat2_->index = (playerchat2_->index + 1) % 7;

							playerchat2_->AnimeTime = 0;

						}
					}
					if (playerchat2_->index >= 6) {
						playerchat2_->count += 1;
					}

					DrawGraph(playerchat2_->playerHpPosX[0] + playerchat2_->shakeChat, playerchat2_->playerHpPosY[0], playerchat2_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat2_->playerHpPosX[1], playerchat2_->playerHpPosY[1], playerchat2_->Animes[playerchat2_->index], TRUE);

					alpha += 2;

					if (alpha >= 120) {
						alpha = 40;
					}

					StopSoundMem(gameBGM);
					PlaySoundMem(kikenBGM, DX_PLAYTYPE_LOOP, FALSE);

					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
					DrawGraph(18, 69, textGraph, TRUE);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

					SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
					DrawGraph(18, 69, kikenGraph, TRUE);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				}
			}
			if (sceneState == Level3) {
				if (playerchat3_->ChatLikePoint == 20) {
					playerchat3_->AnimeTime++;

					if (playerchat3_->count == 0) {
						if (playerchat3_->AnimeTime >= 7)
						{
							playerchat3_->index = (playerchat3_->index + 1) % 7;

							playerchat3_->AnimeTime = 0;

						}
					}
					if (playerchat3_->index >= 6) {
						playerchat3_->count += 1;
					}

					DrawGraph(playerchat3_->playerHpPosX[0] + playerchat3_->shakeChat, playerchat3_->playerHpPosY[0], playerchat3_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat3_->playerHpPosX[1], playerchat3_->playerHpPosY[1], playerchat3_->Animes[playerchat3_->index], TRUE);

					alpha += 2;

					if (alpha >= 120) {
						alpha = 40;
					}

					StopSoundMem(gameBGM);
					PlaySoundMem(kikenBGM, DX_PLAYTYPE_LOOP, FALSE);

					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
					DrawGraph(18, 69, textGraph, TRUE);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

					SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
					DrawGraph(18, 69, kikenGraph, TRUE);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				}
			}
			if (sceneState == Level4) {
				if (playerchat4_->ChatLikePoint == 20) {
					playerchat4_->AnimeTime++;

					if (playerchat4_->count == 0) {
						if (playerchat4_->AnimeTime >= 7)
						{
							playerchat4_->index = (playerchat4_->index + 1) % 7;

							playerchat4_->AnimeTime = 0;

						}
					}
					if (playerchat4_->index >= 6) {
						playerchat4_->count += 1;
					}

					DrawGraph(playerchat4_->playerHpPosX[0] + playerchat4_->shakeChat, playerchat4_->playerHpPosY[0], playerchat4_->PlayerLifeGraph, TRUE);
					DrawGraph(playerchat4_->playerHpPosX[1], playerchat4_->playerHpPosY[1], playerchat4_->Animes[playerchat4_->index], TRUE);

					alpha += 2;

					if (alpha >= 120) {
						alpha = 40;
					}

					StopSoundMem(gameBGM);
					PlaySoundMem(kikenBGM, DX_PLAYTYPE_LOOP, FALSE);

					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
					DrawGraph(18, 69, textGraph, TRUE);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

					SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
					DrawGraph(18, 69, kikenGraph, TRUE);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				}
			}
			
			if (sceneState == Level1) {
				if (playerchat_->ChatLikePoint == 0) {
					DrawGraph(playerchat_->playerHpPosX[0], playerchat_->playerHpPosY[0], playerchat_->Animes[playerchat_->index], TRUE);
				}
			}
			if (sceneState == Level2) {
				if (playerchat2_->ChatLikePoint == 0) {
					DrawGraph(playerchat2_->playerHpPosX[0], playerchat2_->playerHpPosY[0], playerchat2_->Animes[playerchat2_->index], TRUE);
				}
			}
			if (sceneState == Level3) {
				if (playerchat3_->ChatLikePoint == 0) {
					DrawGraph(playerchat3_->playerHpPosX[0], playerchat3_->playerHpPosY[0], playerchat3_->Animes[playerchat3_->index], TRUE);
				}
			}
			if (sceneState == Level4) {
				if (playerchat4_->ChatLikePoint == 0) {
					DrawGraph(playerchat4_->playerHpPosX[0], playerchat4_->playerHpPosY[0], playerchat4_->Animes[playerchat4_->index], TRUE);
				}
			}
			
			if (sceneState == Level1) {
				DrawFormatString(390, 80, GetColor(0, 0, 0), "�A������:�Ƃ�����");
			}
			if (sceneState == Level2) {
				DrawFormatString(390, 80, GetColor(0, 0, 0), "�A������:��");
			}
			if (sceneState == Level3) {
				DrawFormatString(390, 80, GetColor(0, 0, 0), "�A������:���l");
			}
			if (sceneState == Level4) {
				DrawFormatString(390, 80, GetColor(0, 0, 0), "�A������:���l");
			}
			
			
		}
		//---------  �����܂łɃv���O�������L�q  ---------//

		ScreenFlip();// (�_�u���o�b�t�@)����
		WaitTimer(20);// 20�~���b�ҋ@(�^��60FPS)
		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1)
		{
			break;
		}
		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}
	DxLib_End();// Dx���C�u�����I������

	return 0;// ����I��
}
