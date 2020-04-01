#pragma once
#include "CanvasBase.h"


class OptionDetaBase;
//DrawingDetaに加えて、選択肢を表示するクラス
class CanvasOptionBase : public CanvasBase {
protected:
	std::vector<OptionDetaBase*> optiondeta_;//選択肢を入れる動的配列
	int selectnum_;
	void OptionColorChange();
	void OptionUpdate();
public:
	CanvasOptionBase(Keyboard* keyboard);
	virtual void Initialize();//初期化処理
	virtual void Update();//更新処理
	virtual void Draw();//描写処理
	virtual void Finalize();//終了処理
};