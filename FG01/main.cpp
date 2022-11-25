#include "DxLib.h"
#include"talk.h"
#include"PlayerChat.h"
#include"EnemyChat.h"
#include"GameOver.h"
#include"Level.h"

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "07_connect mail";

// ウィンドウ横幅
const int WIN_WIDTH = 600;
// ウィンドウ縦幅
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

	// ゲームループで使う変数の宣言
	int sceneState = 0;

	Talk* talk_ = new Talk;
	PlayerChat* playerchat_ = new PlayerChat;
	EnemyChat* enemychat_ = new EnemyChat;
	Level* level_ = new Level;

	//タイマー
	int time = 0;
	int timer = 120;

	int alpha = 20;

	int count = 0;

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

		// 描画処理

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


			


			DrawFormatString(200, 30, GetColor(0, 0, 0), "連絡相手:ともだち");

			//DrawFormatString(420, 30, GetColor(255, 255, 255), "好感度 = %d",playerchat_->ChatLikePoint);
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
