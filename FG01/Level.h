#pragma once
#include"DxLib.h"

class Level
{
public:
	Level();
	~Level();

	void initialize();

	void Update(char *keys, char* oldkeys);

	void Draw();

	int levelNumber = 4;
private:
	

};

