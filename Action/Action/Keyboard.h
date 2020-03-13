#pragma once
#include "Singleton.h"

//キーボードの状態と
//キーを押している時間を返すクラス
class Keyboard : public Singleton<Keyboard>{
private:
	int key[256];
public:
	int CheckKey(int KeyCode);//キーを押しているフレーム数を返す
	int UpdateKey();//キーの状態を更新する
};