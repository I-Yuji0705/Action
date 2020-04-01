#pragma once
#include "Object.h"
#include "Collision.h"
#include "Sound.h"

//ゲーム内のObjectが行う行動のインターフェースクラス
class IActionBase {
protected:
public:
	virtual ~IActionBase() = 0;
	virtual void Do() = 0;//アクションを起こす
};