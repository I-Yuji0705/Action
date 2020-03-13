#include "Keyboard.h"
#include "DxLib.h"
int Keyboard::CheckKey(int keycode) {
	return key[keycode];
}
int Keyboard::UpdateKey() {//更新に成功すると0を返し、エラーが起きると-1を返す
	try
	{
		const int kKeyType =256;
		char tmpKey[kKeyType];
		GetHitKeyStateAll(tmpKey);//すべてのKeyの押下状態を入力
		for (int i = 0; i < kKeyType; i++) {
			if (tmpKey[i] != 0) key[i]++;//キーが押されている状態の場合
			else key[i] = 0;
		}
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}