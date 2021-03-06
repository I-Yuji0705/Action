#pragma once
#include "DrawingData.h"
#include <vector>
#include "Keyboard.h"
#include "OptionDataBase.h"

class DrawingData;
class Keyboard;
//DrawingDataをもとに複数の項目を表示するクラス
class CanvasBase{
protected:
	std::vector<DrawingData*> drawingData_;//選択肢以外を入れる動的配列
	Keyboard* keyboard_;
public:
	CanvasBase(Keyboard* keyboard);
	virtual void Initialize() {};//初期化処理
	virtual void Update() {};//更新処理
	virtual void Draw();//描写処理
	virtual void Finalize();//終了処理
};