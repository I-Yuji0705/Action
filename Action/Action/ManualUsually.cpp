#include "ManualUsually.h"
#include "DxLib.h"
#include <assert.h>
#include "TextData.h"
#include "ManualOptionData.h"

///<summary>
///<para>コンストラクタ</para>
///<para>マニュアル内で他のマニュアルを選択する字幕の生成</para>
///</summary>
ManualUsually::ManualUsually(Keyboard* keyboard, IManualStateChanger* statechanger) :ManualCanvasOptionBase(keyboard,statechanger) {
	drawingData_.push_back((DrawingData*)new TextData(250, 100, "マニュアル", GetColor(0, 0, 0)));
	optionData_.push_back((OptionDataBase*)new ManualOptionData(130, 250, "プレイヤーの操作方法", GetColor(0, 0, 0),statechanger, ManualState::Manual_Operation));
	optionData_.push_back((OptionDataBase*)new ManualOptionData(130, 300, "ステージ上のオブジェクト一覧", GetColor(0, 0, 0), statechanger, ManualState::Manual_Stage));
	optionData_.push_back((OptionDataBase*)new ManualOptionData(130, 350, "ステージのクリア条件", GetColor(0, 0, 0), statechanger, ManualState::Manual_Rule));
	optionData_.push_back((OptionDataBase*)new ManualOptionData(130, 400, "メニューに戻る", GetColor(0, 0, 0), statechanger, ManualState::Manual_Exit));
}