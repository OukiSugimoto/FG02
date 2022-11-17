//#include "GameOver.h"
//
//void GameOver::Update(char* keys, char* oldkeys,int GCount,int GFlag)
//{
//	if (GCount == 0)
//	{
//		if (keys[KEY_INPUT_1] == FALSE && oldkeys[KEY_INPUT_1] == TRUE)
//		{
//			GCount += 1;
//		}
//		else if (keys[KEY_INPUT_4] == FALSE && oldkeys[KEY_INPUT_4] == TRUE || keys[KEY_INPUT_2] == FALSE && oldkeys[KEY_INPUT_2] == TRUE ||
//			keys[KEY_INPUT_3] == FALSE && oldkeys[KEY_INPUT_3] == TRUE)
//		{
//			GFlag = 1;
//		}
//	}
//	if (GCount == 1)
//	{
//		if (keys[KEY_INPUT_3] == FALSE && oldkeys[KEY_INPUT_3] == TRUE)
//		{
//			GCount += 1;
//		}
//		else if (keys[KEY_INPUT_4] == FALSE && oldkeys[KEY_INPUT_4] == TRUE || keys[KEY_INPUT_2] == FALSE && oldkeys[KEY_INPUT_2] == TRUE ||
//			keys[KEY_INPUT_1] == FALSE && oldkeys[KEY_INPUT_1] == TRUE)
//		{
//			GFlag = 1;
//		}
//	}
//	if (GCount == 2)
//	{
//		if (keys[KEY_INPUT_2] == FALSE && oldkeys[KEY_INPUT_2] == TRUE)
//		{
//			GCount += 1;
//		}
//		else if (keys[KEY_INPUT_4] == FALSE && oldkeys[KEY_INPUT_4] == TRUE || keys[KEY_INPUT_1] == FALSE && oldkeys[KEY_INPUT_1] == TRUE ||
//			keys[KEY_INPUT_3] == FALSE && oldkeys[KEY_INPUT_3] == TRUE)
//		{
//			GFlag = 1;
//		}
//	}
//	if (GCount == 3)
//	{
//		if (keys[KEY_INPUT_3] == FALSE && oldkeys[KEY_INPUT_3] == TRUE)
//		{
//			GCount += 1;
//		}
//		else if (keys[KEY_INPUT_4] == FALSE && oldkeys[KEY_INPUT_4] == TRUE || keys[KEY_INPUT_2] == FALSE && oldkeys[KEY_INPUT_2] == TRUE ||
//			keys[KEY_INPUT_1] == FALSE && oldkeys[KEY_INPUT_1] == TRUE)
//		{
//			GFlag = 1;
//		}
//	}
//	if (GCount == 4)
//	{
//		if (keys[KEY_INPUT_4] == FALSE && oldkeys[KEY_INPUT_4] == TRUE)
//		{
//			GCount += 1;
//		}
//		else if (keys[KEY_INPUT_1] == FALSE && oldkeys[KEY_INPUT_1] == TRUE || keys[KEY_INPUT_2] == FALSE && oldkeys[KEY_INPUT_2] == TRUE ||
//			keys[KEY_INPUT_3] == FALSE && oldkeys[KEY_INPUT_3] == TRUE)
//		{
//			GFlag = 1;
//		}
//	}
//}
//void GameOver::Draw(int GFlag)
//{
//	if (GFlag == 1)
//	{
//		DrawGraph(0, 0, endGraph, true);
//	}
//	
//}
