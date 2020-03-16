#include "Manual.h"
#include "DxLib.h"
#include <assert.h>
#include "ManualUsually.h"
#include "ManualOperation.h"
#include "ManualStage.h"
#include "ManualRule.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�ŏ��ɕ\�����鎚�����Ǘ�����N���X�̐���</para>
///</summary>
Manual::Manual(Keyboard* keyboard, Sound* sound, ISceneChanger* changer) : BaseScene(keyboard, sound,changer) {
	nextstate_ = Manual_None;
	manualselection_ = (ManualSelectionBase*) new ManualUsually(keyboard_,this);
}

///<summary>
///<para>����������</para>
///<para>�����̏������������s��</para>
///</summary>
void Manual::Initialize() {
	manualselection_->Initialize();
}

///<summary>
///<para>�X�V����</para>
///<para>���݂̃X�e�[�g�̕ύX�v���̊m�F�ƁA�����̍X�V�������s��</para>
///<para>�ύX�v�����������ꍇ�A�ύX�������s��</para>
///</summary>
void Manual::Update() {
	if (nextstate_ != Manual_None) {
		manualselection_->Finalize();
		switch (nextstate_) {
		case Manual_Usually:
			manualselection_ = (ManualSelectionBase*) new ManualUsually(keyboard_,this);
			manualselection_->Initialize();
			break;
		case Manual_Operation:
			manualselection_ = (ManualSelectionBase*) new ManualOperation(keyboard_,this);
			manualselection_->Initialize();
			break;
		case Manual_Stage:
			manualselection_ = (ManualSelectionBase*) new ManualStage(keyboard_,this);
			manualselection_->Initialize();
			break;
		case Manual_Rule:
			manualselection_ = (ManualSelectionBase*) new ManualRule(keyboard_,this);
			manualselection_->Initialize();
			break;
		case Manual_Exit:
			scenechanger_->ChangeScene(Scene_Title);
			break;
		default:
			assert(false);
			break;
		}
		nextstate_ = Manual_None;
	}
	manualselection_->Update();
}

//�`��
void Manual::Draw() {
	DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), TRUE);//�w�i�̐ݒ�
	manualselection_->Draw();
}

///<summary>
///<para>�I������</para>
///<para>�����̏I���������s��</para>
///</summary>
void Manual::Finalize() {
	manualselection_->Finalize();
}

void Manual::ChangeState(ManualState state) {
	nextstate_ = state;
}

///<summary>
///<para>�}�j���A����ʂ�BGM���Đ�����</para>
///</summary>
void Manual::StartBgm() {
	sound_->PlayBgm(BGM_Manual);
}