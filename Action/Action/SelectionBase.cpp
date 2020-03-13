#include "SelectionBase.h"
#include "DxLib.h"
#include "ColorCode.h"


SelectionBase::SelectionBase(Keyboard* keyboard) {
	keyboard_ = keyboard;
}

void SelectionBase::Initialize() {
	selectnum_ = 0;
}
//項目の描写処理
void SelectionBase::Draw() { 
	for (auto i : choicedeta_) {
		i->Draw();
	}
	for (auto i : drawingdeta_) {
		i->Draw();
	}
}
//選ばれている選択肢の色を変更する
void SelectionBase::SelectionColorChange(){
	ColorCode selectcolor = { 0,0,255 };
	ColorCode nonselectcolor = { 150,150,150 };
	//unsigned int selectcolor = GetColor(0,0,255);//選ばれている項目の色の設定
	//unsigned int nonselectcolor = GetColor(150, 150, 150);//選ばれていない項目の色の設定
	int num = 0;
	for (auto i : choicedeta_) {
		if (num == selectnum_) i->ChangeColor(selectcolor);
		else i->ChangeColor(nonselectcolor);
		num++;
	}
}
void SelectionBase::SelectSelection(){
	if (keyboard_->CheckKey(KEY_INPUT_DOWN) == 1) {
		selectnum_ = (selectnum_ + 1) % choicedeta_.size();
	}
	else if (keyboard_->CheckKey(KEY_INPUT_UP) == 1) {
		selectnum_ = (selectnum_ + (int)choicedeta_.size() - 1) % (int)choicedeta_.size();
	}
}
void SelectionBase::Finalize() {
	for (auto i : choicedeta_) {
		i->Finalize();
	}
	for (auto i : drawingdeta_) {
		i->Finalize();
	}
}