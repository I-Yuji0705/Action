#include "ManualOperation.h"
#include "DxLib.h"
#include "TextData.h"

///<summary>
///<para>コンストラクタ</para>
///<para>マニュアル内の操作方法の字幕の生成</para>
///</summary>
ManualOperation::ManualOperation(Keyboard* keyboard, IManualStateChanger* statechanger) : ManualCanvasBase(keyboard,statechanger) {
	drawingData_.push_back((DrawingData*) new TextData(250, 100, "操作方法", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 220, "左右キー:プレイヤーの左右移動", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 240, "上キー:プレイヤーのジャンプ", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 260, "下キー:持っているアイテムを置く", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 280, "Ctrlキー:プレイヤーの向きの反転", GetColor(0, 0, 0)));
	drawingData_.push_back((DrawingData*) new TextData(130, 300, "Spaceキー:アイテムを持つ/持っているアイテムを投げる", GetColor(0, 0, 0)));
}