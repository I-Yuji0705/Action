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
	manualcanvas_ = (CanvasBase*) new ManualUsually(keyboard_,this);
}

///<summary>
///<para>����������</para>
///<para>�����̏������������s��</para>
///</summary>
void Manual::Initialize() {
	manualcanvas_->Initialize();
}

///<summary>
///<para>�X�V����</para>
///<para>�����̍X�V�������s��</para>
///<para>nextstate_���ύX����Ă����ꍇ�Anextstate_�ɂ���ď������s��</para>
///</summary>
void Manual::Update() {
	if (nextstate_ != Manual_None) {
		manualcanvas_->Finalize();
		switch (nextstate_) {
		case Manual_Usually:
			manualcanvas_ = (CanvasBase*) new ManualUsually(keyboard_,this);
			manualcanvas_->Initialize();
			break;
		case Manual_Operation:
			manualcanvas_ = (CanvasBase*) new ManualOperation(keyboard_,this);
			manualcanvas_->Initialize();
			break;
		case Manual_Stage:
			manualcanvas_ = (CanvasBase*) new ManualStage(keyboard_,this);
			manualcanvas_->Initialize();
			break;
		case Manual_Rule:
			manualcanvas_ = (CanvasBase*) new ManualRule(keyboard_,this);
			manualcanvas_->Initialize();
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
	manualcanvas_->Update();
}

///<summary>
///<para>�`�ʏ���</para>
///<para>�w�i�Ǝ����̕`�ʏ������s��</para>
///</summary>
void Manual::Draw() {
	DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), TRUE);//�w�i�̐ݒ�
	manualcanvas_->Draw();
}

///<summary>
///<para>�I������</para>
///<para>�����̏I���������s��</para>
///</summary>
void Manual::Finalize() {
	manualcanvas_->Finalize();
}

///<summary>
///<para>State�̕ύX����</para>
///<para>nextstate_�������̒l�ɕύX����</para>
///<param name= "state"><para>nextstate_��Copy����l</para></param>
///</summary>
void Manual::ChangeState(ManualState state) {
	nextstate_ = state;
}

///<summary>
///<para>�}�j���A����ʂ�BGM���Đ�����</para>
///</summary>
void Manual::StartBgm() {
	sound_->PlayBgm(BGM_Manual);
}