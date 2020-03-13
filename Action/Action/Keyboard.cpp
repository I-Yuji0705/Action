#include "Keyboard.h"
#include "DxLib.h"
#define KeyNum 256//キーの種類
int Keyboard::UpdateKey() {//更新に成功すると0を返し、エラーが起きると-1を返す
	try
	{
		char tmpKey[KeyNum];
		GetHitKeyStateAll(tmpKey);
		for (int i = 0; i < KeyNum; i++) {
			if (tmpKey[i] != 0) key[i]++;
			else key[i] = 0;
		}
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}
int Keyboard::CheckKey(int KeyCode) {
	return key[KeyCode];
}