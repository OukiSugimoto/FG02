#include "DxLib.h"
#include"talk.h"
#include"PlayerChat.h"
#include"EnemyChat.h"

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
	End
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
	SetFontSize(30);
	if (DxLib_Init() == -1) { return -1; }    // DXlibの初期化

	// 画像などのリソースデータの変数宣言と読み込み
	int backGraph = LoadGraph("Resource\\back.png");
	int textGraph = LoadGraph("Resource\\text.png");

	// ゲームループで使う変数の宣言
	Talk* talk_ = new Talk;
	talk_->Initialize();

	PlayerChat* playerchat_ = new PlayerChat;
	playerchat_->Initialize();

	EnemyChat* enemychat_ = new EnemyChat;
	enemychat_->Initialize();

	int sceneState = 0;

	//タイマー
	int time = 0;
	int timer = 120;

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
		time++;
		if (time >= 60) {
			timer -= 1;
			time = 0;
		}

		talk_->Update(keys);
		
		playerchat_->Update(keys, oldkeys);

		enemychat_->Update(keys, oldkeys);

		// 描画処理
		talk_->Draw();
		
		playerchat_->Draw();

		enemychat_->Draw();

		DrawGraph(0, 0, backGraph, TRUE);

		DrawFormatString(200,200,GetColor(255,255,255),"%d",count);
		//DrawFormatString(200, 0, GetColor(255, 255, 255), "timer=%d", timer);
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
