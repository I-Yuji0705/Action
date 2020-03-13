#pragma once
#include "Object.h"
#include "Collision.h"
#include "Sound.h"

//ゲーム内のObjectが行う行動の基底クラス
class IActionBase {
protected:
public:
	virtual void Do() = 0;//アクションを起こす
};