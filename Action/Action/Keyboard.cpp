#include "Keyboard.h"
#include "DxLib.h"

///<summary>
///<para>受け取ったキーコードから、対象のキーがどの程度押されているかを返す</para>
///<para>引数:</para>
///<param name="keycode"><para>keycode:調べるキーコード</para></param>
///<para>戻り値:</para>
///<returns>
///<para>引数のkeycodeが押されているフレーム数</para>
///</returns>
///</summary>
int Keyboard::CheckKey(int keycode) {
	return key[keycode];
}

///<summary>
///<para>受け取ったキーコードから、対象のキーがどの程度押されているかを返す</para>
///<para>引数:</para>
///<param name="keycode"><para>keycode:調べるキーコード</para></param>
///<para>戻り値:</para>
///<returns>
///<para>0:更新が完了した</para>
///<para>-1:更新中にエラーが発生した</para>
///</returns>
///</summary>
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