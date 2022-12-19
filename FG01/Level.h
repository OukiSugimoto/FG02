#pragma once
#include"DxLib.h"

class Level
{
public:
	Level();
	~Level();

	void Initialize();

	void Update(char *keys, char* oldkeys);

	void Draw();

	int levelNumber = 4;
private:
	int alpha = 0;

};

