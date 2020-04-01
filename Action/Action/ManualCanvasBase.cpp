#include "ManualCanvasBase.h"
#include "DxLib.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>Manual��State��ς���|�C���^�̎擾</para>
///<para>����:</para>
///<param name= "statechanger"><para>Manual��State��ς���N���X�̃|�C���^</para></param>
///</summary>
ManualCanvasBase::ManualCanvasBase(Keyboard* keyboard,IManualStateChanger* statechanger): CanvasBase(keyboard) {
	statechanger_ = statechanger;
}

///<summary>
///<para>�X�V����</para>
///<para>Enter�L�[���AEscape�L�[���������ꍇ�A�}�j���A���I����ʂɈڍs����</para>
///</summary>
void ManualCanvasBase::Update() {
	if (keyboard_->CheckKey(KEY_INPUT_RETURN) == 1 ||
		keyboard_->CheckKey(KEY_INPUT_ESCAPE) == 1) {
		statechanger_->ChangeState(Manual_Usually);//��Ԃ��}�j���A���I����ʂɈڍs
	}
}