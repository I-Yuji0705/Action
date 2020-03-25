#include "ManualOperation.h"
#include "DxLib.h"
#include "TextDeta.h"

///<summary>
///<para>コンストラクタ</para>
///<para>マニュアル内の操作方法の字幕の生成</para>
///</summary>
ManualOperation::ManualOperation(Keyboard* keyboard, IManualStateChanger* statechanger) : ManualCanvasBase(keyboard,statechanger) {
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(250, 100, "操作方法", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(130, 220, "左右キー:プレイヤーの左右移動", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(130, 240, "上キー:プレイヤーのジャンプ", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(130, 260, "下キー:持っているアイテムを置く", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(130, 280, "Ctrlキー:プレイヤーの向きの反転", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(130, 300, "Spaceキー:アイテムを持つ/持っているアイテムを投げる", GetColor(0, 0, 0)));
}