#include "TitleUsually.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "TextData.h"
#include "TitleOptionData.h"

///<summary>
///<para>コンストラクタ</para>
///<para>字幕の生成</para>
///</summary>
TitleUsually::TitleUsually(Keyboard* keyboard, ITitleStateChanger* statechanger) :TitleCanvasOptionBase(keyboard,statechanger){
	optionData_.push_back((OptionDataBase*) new TitleOptionData(400, 300, "ゲームスタート", GetColor(0, 0, 0),statechanger, Title_Game));
	optionData_.push_back((OptionDataBase*) new TitleOptionData(400, 350, "ゲーム終了", GetColor(0, 0, 0),statechanger, Title_Delete));
	optionData_.push_back((OptionDataBase*) new TitleOptionData(400, 400, "操作説明", GetColor(0, 0, 0), statechanger, Title_Intersection));
	drawingData_.push_back((DrawingData*) new TextData(130, 380, "Enterキー:項目の決定", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 400, "上下キー：項目の選択", GetColor(0, 0, 0)));
}
