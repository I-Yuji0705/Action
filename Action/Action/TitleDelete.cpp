#include "TitleDelete.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "SelectionDeta.h"

TitleDelete::TitleDelete(Keyboard* keyboard, ITitleStateChanger* statechanger) :TitleSelectionBase(keyboard,statechanger){
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(300, 350, "はい", GetColor(0, 0, 0))) ;
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(300, 400, "いいえ", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*)new SelectionDeta(200, 300, "本当にゲームを終了しますか？", GetColor(0, 0, 0)));}

void TitleDelete::Initialize(){
	SelectionBase::Initialize();
}
void TitleDelete::Update(){
	SelectionBase::SelectSelection();
	SelectionBase::SelectionColorChange();
	//Enterキーを入力したとき
	if (keyboard_->CheckKey(KEY_INPUT_RETURN) == 1) {
		switch (selectnum_) {
		case 0:
			statechanger_->ChangeState(Title_Exit);
			break;
		case 1:
			statechanger_->ChangeState(Title_Usually);
			break;
		default:
			assert(false);
			break;
		}
	}
}