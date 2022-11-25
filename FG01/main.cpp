#include "DxLib.h"
#include"talk.h"
#include"PlayerChat.h"
#include"EnemyChat.h"
#include"GameOver.h"
#include"Level.h"

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "07_connect mail";

// �E�B���h�E����
const int WIN_WIDTH = 600;
// �E�B���h�E�c��
const int WIN_HEIGHT = 900;

enum GAMESCENE
{
	Title,
	Level1,
	Level2,
	Level3,
	Level4,
	Level5,
	End,
	Clear,
	Ruru
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

	// �Q�[�����[�v�Ŏg���ϐ��̐錾
	int sceneState = 0;

	Talk* talk_ = new Talk;
	PlayerChat* playerchat_ = new PlayerChat;
	EnemyChat* enemychat_ = new EnemyChat;
	Level* level_ = new Level;

	//�^�C�}�[
	int time = 0;
	int timer = 120;

	int alpha = 20;

	int count = 0;

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

			enemychat_->Initialize();

			level_->initialize();

			DrawGraph(0,0,titleGraph,TRUE);
			if (keys[KEY_INPUT_SPACE] == TRUE && oldkeys[KEY_INPUT_SPACE] == FALSE) {
				sceneState = Ruru;

			}
			break;

		case Level1:
			playerchat_->Update(keys, oldkeys);

			enemychat_->Update(keys, oldkeys);

			if (playerchat_->chatFalse == 1) {
				sceneState = End;
			}
			break;

		case End:
			DrawGraph(0, 0, endGraph, TRUE);
			if (keys[KEY_INPUT_SPACE] == TRUE && oldkeys[KEY_INPUT_SPACE] == FALSE) {
				sceneState = Title;
			}
			break;

		case Clear:
			DrawGraph(0, 0, clearGraph, TRUE);
			if (keys[KEY_INPUT_SPACE] == TRUE && oldkeys[KEY_INPUT_SPACE] == FALSE) {
				sceneState = Title;
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
		}

		// �`�揈��

		if (sceneState == Level1) {
			talk_->Draw();

			playerchat_->Draw();

			enemychat_->Draw();

			DrawGraph(0, 0, backGraph, TRUE);

			playerchat_->AnimeTime++;
			if (playerchat_->AnimeTime >= 7)
			{
				playerchat_->index = (playerchat_->index + 1) % 7;

				playerchat_->AnimeTime = 3;
			}


			if (playerchat_->ChatLikePoint == 100) {
				DrawGraph(playerchat_->playerHpPosX[0], playerchat_->playerHpPosY[0], playerchat_->PlayerLifeGraph, TRUE);
				DrawGraph(playerchat_->playerHpPosX[1], playerchat_->playerHpPosY[1], playerchat_->PlayerLifeGraph, TRUE);
				DrawGraph(playerchat_->playerHpPosX[2], playerchat_->playerHpPosY[2], playerchat_->PlayerLifeGraph, TRUE);
				DrawGraph(playerchat_->playerHpPosX[3], playerchat_->playerHpPosY[3], playerchat_->PlayerLifeGraph, TRUE);
				DrawGraph(playerchat_->playerHpPosX[4], playerchat_->playerHpPosY[4], playerchat_->PlayerLifeGraph, TRUE);
			}

			if (playerchat_->ChatLikePoint == 80) {
				DrawGraph(playerchat_->playerHpPosX[0], playerchat_->playerHpPosY[0], playerchat_->PlayerLifeGraph,TRUE);
				DrawGraph(playerchat_->playerHpPosX[1], playerchat_->playerHpPosY[1], playerchat_->PlayerLifeGraph, TRUE);
				DrawGraph(playerchat_->playerHpPosX[2], playerchat_->playerHpPosY[2], playerchat_->PlayerLifeGraph, TRUE);
				DrawGraph(playerchat_->playerHpPosX[3], playerchat_->playerHpPosY[3], playerchat_->PlayerLifeGraph, TRUE);
				DrawGraph(playerchat_->playerHpPosX[4], playerchat_->playerHpPosY[4], playerchat_->Animes[playerchat_->index], TRUE);
			}

			if (playerchat_->ChatLikePoint == 60) {
				DrawGraph(playerchat_->playerHpPosX[0], playerchat_->playerHpPosY[0], playerchat_->PlayerLifeGraph, TRUE);
				DrawGraph(playerchat_->playerHpPosX[1], playerchat_->playerHpPosY[1], playerchat_->PlayerLifeGraph, TRUE);
				DrawGraph(playerchat_->playerHpPosX[2], playerchat_->playerHpPosY[2], playerchat_->PlayerLifeGraph, TRUE);
				DrawGraph(playerchat_->playerHpPosX[3], playerchat_->playerHpPosY[3], playerchat_->Animes[playerchat_->index], TRUE);
				DrawGraph(playerchat_->playerHpPosX[4], playerchat_->playerHpPosY[4], playerchat_->Animes[playerchat_->index], TRUE);
			}

			if (playerchat_->ChatLikePoint == 40) {
				DrawGraph(playerchat_->playerHpPosX[0], playerchat_->playerHpPosY[0], playerchat_->PlayerLifeGraph, TRUE);
				DrawGraph(playerchat_->playerHpPosX[1], playerchat_->playerHpPosY[1], playerchat_->PlayerLifeGraph, TRUE);
				DrawGraph(playerchat_->playerHpPosX[2], playerchat_->playerHpPosY[2], playerchat_->Animes[playerchat_->index], TRUE);
				DrawGraph(playerchat_->playerHpPosX[3], playerchat_->playerHpPosY[3], playerchat_->Animes[playerchat_->index], TRUE);
				DrawGraph(playerchat_->playerHpPosX[4], playerchat_->playerHpPosY[4], playerchat_->Animes[playerchat_->index], TRUE);
			}

			if (playerchat_->ChatLikePoint == 20) {
				DrawGraph(playerchat_->playerHpPosX[0] + playerchat_->shakeChat, playerchat_->playerHpPosY[0], playerchat_->PlayerLifeGraph, TRUE);
				DrawGraph(playerchat_->playerHpPosX[1], playerchat_->playerHpPosY[1], playerchat_->Animes[playerchat_->index], TRUE);
				DrawGraph(playerchat_->playerHpPosX[2], playerchat_->playerHpPosY[2], playerchat_->Animes[playerchat_->index], TRUE);
				DrawGraph(playerchat_->playerHpPosX[3], playerchat_->playerHpPosY[3], playerchat_->Animes[playerchat_->index], TRUE);
				DrawGraph(playerchat_->playerHpPosX[4], playerchat_->playerHpPosY[4], playerchat_->Animes[playerchat_->index], TRUE);

				alpha += 2;

			if (alpha >= 120) {
				alpha = 40;
			}

			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
			DrawGraph(18, 69, textGraph, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

			SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
			DrawGraph(18, 69, kikenGraph, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}


			


			DrawFormatString(200, 30, GetColor(0, 0, 0), "�A������:�Ƃ�����");

			//DrawFormatString(420, 30, GetColor(255, 255, 255), "�D���x = %d",playerchat_->ChatLikePoint);
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
