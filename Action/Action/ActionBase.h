#pragma once
#include "Object.h"
#include "Collision.h"
#include "Sound.h"

//ゲーム内のObjectが行う行動の基底クラス
class ActionBase {
protected:
	Collision* collision_;//アクション時の物理判定を計測する場所
	Sound* sound_;//アクション時に鳴らす音
public:
	ActionBase(Collision* collision,Sound* sound);
	virtual void Do() = 0;//アクションを起こす
};