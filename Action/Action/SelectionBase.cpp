#include "SelectionBase.h"
#include "DxLib.h"
#include "ColorCode.h"


SelectionBase::SelectionBase(Keyboard* keyboard) {
	keyboard_ = keyboard;
}

void SelectionBase::Initialize() {
	selectnum_ = 0;
}
//���ڂ̕`�ʏ���
void SelectionBase::Draw() { 
	for (auto i : choicedeta_) {
		i->Draw();
	}
	for (auto i : drawingdeta_) {
		i->Draw();
	}
}
//�I�΂�Ă���I�����̐F��ύX����
void SelectionBase::SelectionColorChange(){
	ColorCode selectcolor = { 0,0,255 };
	ColorCode nonselectcolor = { 150,150,150 };
	//unsigned int selectcolor = GetColor(0,0,255);//�I�΂�Ă��鍀�ڂ̐F�̐ݒ�
	//unsigned int nonselectcolor = GetColor(150, 150, 150);//�I�΂�Ă��Ȃ����ڂ̐F�̐ݒ�
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