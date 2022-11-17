#include"talk.h"

Talk::Talk() {}
Talk::~Talk(){}

void Talk::Initialize() {
	posX = 0;
	posY = 0;
}

void Talk::Draw() {
	DrawGraph(posX, posY, talkGraph, TRUE);

	//選択画面
	//チャット番号
	DrawGraph(18, 600, chatSendGraph, TRUE);
	DrawGraph(300, 600, chatSendGraph, TRUE);
	DrawGraph(18, 700, chatSendGraph, TRUE);
	DrawGraph(300, 700, chatSendGraph, TRUE);

}
