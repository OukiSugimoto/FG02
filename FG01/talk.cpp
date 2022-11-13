#include"talk.h"

Talk::Talk() {}
Talk::~Talk(){}

void Talk::Initialize() {
	posX = 0;
	posY = 0;

	posY2 = 850;
	TalkScrollY = 0;

	timer = 120;
}

void Talk::Update(char *key) {
	if (key[KEY_INPUT_UP]) {
		TalkScrollY -= 10;
	}
	if (key[KEY_INPUT_DOWN]) {
		TalkScrollY += 10;
	}
	
	if (TalkScrollY >= 850) {
		TalkScrollY = 0;
		posY = 0;
		posY2 = 850;
	}

	if (TalkScrollY <= 0) {
		TalkScrollY = 0;
		posY = 0;
		posY2 = 850;
	}
	
}

void Talk::Draw() {
	DrawGraph(posX, posY - TalkScrollY, talkGraph, TRUE);
	DrawGraph(posX, posY2 - TalkScrollY, talk2Graph, TRUE);

	//選択画面
	//チャット番号
	DrawGraph(18, 600, chatSendGraph, TRUE);
	DrawGraph(300, 600, chatSendGraph, TRUE);
	DrawGraph(18, 700, chatSendGraph, TRUE);
	DrawGraph(300, 700, chatSendGraph, TRUE);

	DrawFormatString(300, 10, GetColor(255, 255, 255), "〇〇〇");
	

	//チャット選択
	/*DrawGraph(18, 600, chatSendGraph, TRUE);
	DrawGraph(300, 600, chatSendGraph, TRUE);
	DrawGraph(18, 700, chatSendGraph, TRUE);
	DrawGraph(300, 700, chatSendGraph, TRUE);*/
	//DrawFormatString(200, 200, GetColor(128, 128, 128), "scroll=%d", TalkScrollY);
	
}
