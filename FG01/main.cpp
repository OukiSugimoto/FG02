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

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "07_connect mail";

// ウィンドウ横幅
const int WIN_WIDTH = 600;
// ウィンドウ縦幅
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
	
	ChangeWindowMode(TRUE);                   // ウィンドウモードに設定
	SetWindowSizeChangeEnableFlag(true, true);// ウィンドウサイズを手動では変更させず、かつウィンドウサイズに合わせて拡大できないようにする
	SetMainWindowText(TITLE);                 // タイトルを変更
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);  // 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetWindowSizeExtendRate(1.0);             // 画面サイズを設定(解像度との比率で設定)
	SetBackgroundColor(0, 0, 0);     // 画面の背景色を設定する
	SetDrawScreen(DX_SCREEN_BACK);            // (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetFontSize(20);
	if (DxLib_Init() == -1) { return -1; }    // DXlibの初期化

	// 画像などのリソースデータの変数宣言と読み込み
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
	// ゲームループで使う変数の宣言
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
	

	//タイマー
	int alpha = 20;

	char keys[256] = { 0 };   // 最新のキーボード情報用
	char oldkeys[256] = { 0 };// 1ループ(フレーム)前のキーボード情報

	// ゲームループ
	while (true)
	{
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		for (int i = 0; i < 256; i++)
		{
			oldkeys[i] = keys[i];
		}
		GetHitKeyStateAll(keys);// 最新のキーボード情報を取得
		ClearDrawScreen();      // 画面クリア

		//---------  ここからプログラムを記述  ----------//

		// 更新処理

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

		// 描画処理

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
				DrawFormatString(390, 80, GetColor(0, 0, 0), "連絡相手:ともだち");
			}
			if (sceneState == Level2) {
				DrawFormatString(390, 80, GetColor(0, 0, 0), "連絡相手:母");
			}
			if (sceneState == Level3) {
				DrawFormatString(390, 80, GetColor(0, 0, 0), "連絡相手:恋人");
			}
			if (sceneState == Level4) {
				DrawFormatString(390, 80, GetColor(0, 0, 0), "連絡相手:恋人");
			}
			
			
		}
		//---------  ここまでにプログラムを記述  ---------//

		ScreenFlip();// (ダブルバッファ)裏面
		WaitTimer(20);// 20ミリ秒待機(疑似60FPS)
		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1)
		{
			break;
		}
		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}
	DxLib_End();// Dxライブラリ終了処理

	return 0;// 正常終了
}
