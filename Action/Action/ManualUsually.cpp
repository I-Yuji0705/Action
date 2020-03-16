#include "ManualUsually.h"
#include "DxLib.h"
#include <assert.h>
#include "SelectionDeta.h"

///<summary>
///<para>コンストラクタ</para>
///<para>マニュアル内で他のマニュアルを選択する字幕の生成</para>
///</summary>
ManualUsually::ManualUsually(Keyboard* keyboard, IManualStateChanger* statechanger) :ManualSelectionBase(keyboard,statechanger) {
	drawingdeta_.push_back((DrawingDeta*)new SelectionDeta(250, 100, "マニュアル", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(130, 250, "プレイヤーの操作方法", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(130, 300, "ステージ上のオブジェクト一覧", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(130, 350, "ステージのクリア条件", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(130, 400, "メニューに戻る", GetColor(0, 0, 0)));
}

///<summary>
///<para>初期化処理</para>
///</summary>
void ManualUsually::Initialize() {
	SelectionBase::Initialize();
}

///<summary>
///<para>更新処理</para>
///<para>上下キーを入力した際、選択している項目が上下する</para>
///<para>Enterキーを押した際、選んだ選択肢よって異なるStateに変更する</para>
///</summary>
void ManualUsually::Update() {
	SelectionBase::SelectSelection();
	SelectionBase::SelectionColorChange();
	//Enterキーを入力したとき
	if (keyboard_->CheckKey(KEY_INPUT_RETURN) == 1) {
		switch (selectnum_) {
		case 0:
			statechanger_->ChangeState(Manual_Operation);
			break;
		case 1:
			statechanger_->ChangeState(Manual_Stage);
			break;
		case 2:
			statechanger_->ChangeState(Manual_Rule);
			break;
		case 3:
			statechanger_->ChangeState(Manual_Exit);
			break;
		default:
			assert(false);
			break;
		}
	}
}