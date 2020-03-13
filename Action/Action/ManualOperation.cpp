#include "ManualOperation.h"
#include "DxLib.h"
#include "SelectionDeta.h"

ManualOperation::ManualOperation(Keyboard* keyboard, IManualStateChanger* statechanger) : ManualSelectionBase(keyboard,statechanger) {
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(250, 100, "操作方法", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 220, "左右キー:プレイヤーの左右移動", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 240, "上キー:プレイヤーのジャンプ", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 260, "下キー:持っているアイテムを置く", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 280, "Ctrlキー:プレイヤーの向きの反転", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(130, 300, "Spaceキー:アイテムを持つ/持っているアイテムを投げる", GetColor(0, 0, 0)));
}

void ManualOperation::Initialize() {
	SelectionBase::Initialize();
}