#include "ManualRule.h"
#include "DxLib.h"
#include "TextData.h"

///<summary>
///<para>コンストラクタ</para>
///<para>マニュアル内のクリア条件の字幕の生成</para>
///</summary>
ManualRule::ManualRule(Keyboard* keyboard, IManualStateChanger* statechanger) :ManualCanvasBase(keyboard,statechanger) {
	drawingData_.push_back((DrawingData*) new TextData(250, 100, "ステージのクリア条件", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 220, "ステージ内に散らばるアイテムを集めて、", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 240, "ステージ内にある積み上げエリアをオブジェクトで", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 260, "埋め尽くすとクリアします。", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 280, "積み上げエリア内に埋め尽くせるオブジェクトは、", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 300, "積み上げエリア以外の全てが対象です。", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 320, "つまり、最後の一押しにプレイヤーをエリアに入れ", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 340, "てもクリアになります。", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 360, "覚えておくとクリアが楽になるかもしれません。", GetColor(0, 0, 0)));
}