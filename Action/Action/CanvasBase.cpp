#include "CanvasBase.h"
#include "DxLib.h"
#include "ColorCode.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>Scene���Ŏg�p����L�[�{�[�h�N���X���擾����</para>
///<param name= "keyboard"><para>�L�[��������Ă��邩�m�F����N���X</para></param>
///</summary>
CanvasBase::CanvasBase(Keyboard* keyboard) {
	keyboard_ = keyboard;
}

///<summary>
///<para>�`�ʏ���</para>
///<para>�I�����ƍ��ڂ̕`�ʏ������s��</para>
///</summary>
void CanvasBase::Draw() { 
	for (auto i : drawingData_) {
		i->Draw();
	}
}



///<summary>
///<para>�I������</para>
///<para>�I�����ƍ��ڂ̏I���������s��</para>
///</summary>
void CanvasBase::Finalize() {
	for (auto i : drawingData_) {
		i->Finalize();
	}
}