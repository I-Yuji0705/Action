#pragma once
#include "Singleton.h"
class Keyboard : public Singleton<Keyboard>{
private:
	int key[256];
public:
	int CheckKey(int KeyCode);//キーを押しているフレーム数を返す
	int UpdateKey();//キーの状態を更新する
};