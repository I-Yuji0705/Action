#pragma once
#include "DrawingDeta.h"
#include <vector>

class DrawingDeta;
//SelectionDetaをもとに複数の項目と
//選択肢を表示するクラス
class SelectionBase{
protected:
	std::vector<DrawingDeta*> choicedeta_;//選択肢を入れる動的配列
	std::vector<DrawingDeta*> drawingdeta_;//選択肢以外を入れる動的配列
	int selectnum_;
	void SelectionColorChange();
	void SelectSelection();
public:
	virtual void Initialize();//初期化処理
	virtual void Update() {};//更新処理
	virtual void Draw();//描写処理
	virtual void Finalize();//終了処理
};