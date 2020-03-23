#include "SelectionBase.h"
#include "DxLib.h"
#include "ColorCode.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>Scene���Ŏg�p����L�[�{�[�h�N���X���擾����</para>
///<para>����:</para>
///<param name= "keyboard"><para>�L�[��������Ă��邩�m�F����N���X</para></param>
///</summary>
SelectionBase::SelectionBase(Keyboard* keyboard) {
	keyboard_ = keyboard;
}


///<summary>
///<para>����������</para>
///<para>�I�����Ă��鍀�ڂ̂������ϐ��̏����l��ݒ肷��</para>
///</summary>
void SelectionBase::Initialize() {
	selectnum_ = 0;
}

///<summary>
///<para>�`�ʏ���</para>
///<para>�I�����ƍ��ڂ̕`�ʏ������s��</para>
///</summary>
void SelectionBase::Draw() { 
	for (auto i : choicedeta_) {
		i->Draw();
	}
	for (auto i : drawingdeta_) {
		i->Draw();
	}
}

///<summary>
///<para>�F�̍X�V����</para>
///<para>�I�����̐F��ύX����</para>
///<para>�I�΂�Ă���I�����̐F�ƑI�΂�Ă��Ȃ��I�����̐F��ʁX�ɐݒ肵�A�ύX����</para>
///</summary>
void SelectionBase::SelectionColorChange(){
	ColorCode selectcolor = { 0,0,255 };//�I�΂�Ă��鍀�ڂ̐F�̐ݒ�
	ColorCode nonselectcolor = { 150,150,150 };//�I�΂�Ă��Ȃ����ڂ̐F�̐ݒ�
	//unsigned int selectcolor = GetColor(0,0,255);//�I�΂�Ă��鍀�ڂ̐F�̐ݒ�
	//unsigned int nonselectcolor = GetColor(150, 150, 150);//�I�΂�Ă��Ȃ����ڂ̐F�̐ݒ�
	int num = 0;
	for (auto i : choicedeta_) {
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
void SelectionBase::SelectSelection(){
	if (keyboard_->CheckKey(KEY_INPUT_DOWN) == 1) {
		selectnum_ = (selectnum_ + 1) % choicedeta_.size();
	}
	else if (keyboard_->CheckKey(KEY_INPUT_UP) == 1) {
		selectnum_ = (selectnum_ + (int)choicedeta_.size() - 1) % (int)choicedeta_.size();
	}
}

///<summary>
///<para>�I������</para>
///<para>�I�����ƍ��ڂ̏I���������s��</para>
///</summary>
void SelectionBase::Finalize() {
	for (auto i : choicedeta_) {
		i->Finalize();
	}
	for (auto i : drawingdeta_) {
		i->Finalize();
	}
}