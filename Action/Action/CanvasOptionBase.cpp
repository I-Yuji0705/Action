#include "CanvasOptionBase.h"
#include "DxLib.h"


CanvasOptionBase::CanvasOptionBase(Keyboard* keyboard) : CanvasBase(keyboard) {
}
///<summary>
///<para>�F�̍X�V����</para>
///<para>�I�����̐F��ύX����</para>
///<para>�I�΂�Ă���I�����̐F�ƑI�΂�Ă��Ȃ��I�����̐F��ʁX�ɐݒ肵�A�ύX����</para>
///</summary>
void CanvasOptionBase::OptionColorChange() {
	ColorCode selectcolor = { 0,0,255 };//�I�΂�Ă��鍀�ڂ̐F�̐ݒ�
	ColorCode nonselectcolor = { 150,150,150 };//�I�΂�Ă��Ȃ����ڂ̐F�̐ݒ�
	int num = 0;
	for (auto i : optiondeta_) {
		if (num == selectnum_) i->ChangeColor(selectcolor);
		else i->ChangeColor(nonselectcolor);
		num++;
	}
}


///<summary>
///<para>�I�����̍X�V����</para>
///<para>�㉺�L�[���������ƂŁA�I�����Ă���I�������㉺�̑I�����ɕύX����</para>
///<para>��ԏ�̑I������I�����ɏ�L�[�������ƁA��ԉ��̑I������I��</para>
///<para>���l�ɁA��ԉ��̑I������I�����ɉ��L�[�������ƁA��ԏ�̑I������I��</para>
///</summary>
void CanvasOptionBase::OptionUpdate() {
	if (keyboard_->CheckKey(KEY_INPUT_DOWN) == 1) {
		selectnum_ = (selectnum_ + 1) % optiondeta_.size();
	}
	else if (keyboard_->CheckKey(KEY_INPUT_UP) == 1) {
		selectnum_ = (selectnum_ + (int)optiondeta_.size() - 1) % (int)optiondeta_.size();
	}
}
///<summary>
///<para>����������</para>
///<para>�I�����Ă��鍀�ڂ̂������ϐ��̏����l��ݒ肷��</para>
///</summary>
void CanvasOptionBase::Initialize() {
	selectnum_ = 0;
}

///<summary>
///<para>�`�ʏ���</para>
///<para>�I�����ƍ��ڂ̕`�ʏ������s��</para>
///</summary>
void CanvasOptionBase::Draw() {
	CanvasBase::Draw();
	for (auto i : optiondeta_) {
		i->Draw();
	}
}



///<summary>
///<para>�I������</para>
///<para>�I�����ƍ��ڂ̏I���������s��</para>
///</summary>
void CanvasOptionBase::Finalize() {
	CanvasBase::Finalize();
	for (auto i : optiondeta_) {
		i->Finalize();
	}
}

void CanvasOptionBase::Update() {
	OptionUpdate();
	OptionColorChange();
	//Enter�L�[����͂����Ƃ�
	if (keyboard_->CheckKey(KEY_INPUT_RETURN) == 1) {
		optiondeta_[selectnum_]->Opt();
	}
}