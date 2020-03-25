#include "Title.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "TitleUsually.h"
#include "TitleDelete.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�ǉ��ŁA�^�C�g���ɕ\������摜�ƍŏ��ɕ\�����鎚���̐������s��</para>
///</summary>
Title::Title(Keyboard* keyboard,Sound* sound,ISceneChanger* changer) : BaseScene(keyboard,sound,changer) {
	titlecanvas_ = (CanvasBase*) new TitleUsually(keyboard_, this);
	title_ = LoadGraph("Title/title.png");
	nextstate_ = Title_None;
}

///<summary>
///<para>����������</para>
///<para>�����̏������������s��</para>
///</summary>
void Title::Initialize() {
	titlecanvas_->Initialize();
}

///<summary>
///<para>�X�V����</para>
///<para>�����̍X�V�������s��</para>
///<para>nextstate���ύX����Ă����ꍇ�Anextstate�ɂ���ď������s��</para>
///</summary>
void Title::Update(){
	if (nextstate_ != Title_None) {
		titlecanvas_->Finalize();
		switch (nextstate_) {
		case Title_Usually:
			titlecanvas_ = (CanvasBase*) new TitleUsually(keyboard_,this);
			titlecanvas_->Initialize();
			break;
		case Title_Delete:
			titlecanvas_ = (CanvasBase*) new TitleDelete(keyboard_, this);
			titlecanvas_->Initialize();
			break;
		case Title_Intersection:
			scenechanger_->ChangeScene(Scene_Manual);
			titlecanvas_->Initialize();
			break;
		case Title_Game:
			scenechanger_->ChangeScene(Scene_Game);
			titlecanvas_->Initialize();
			break;
		case Title_Exit:
			DxLib_End();//�v���O�������I������
			break;
		default:
			assert(false);
			break;
		}
		nextstate_ = Title_None;
	}
	titlecanvas_->Update();
}

///<summary>
///<para>�`�ʏ���</para>
///<para>�^�C�g���Ǝ����̕`�ʏ������s��</para>
///</summary>
void Title::Draw() {
	DrawBox(0, 0, 640, 480, GetColor(255,255,255), TRUE);//�w�i�F�̐ݒ�
	titlecanvas_->Draw();//�����̕\��
	DrawModiGraph(50,50,600,50,600,300,50,300,title_,FALSE);//�^�C�g���̕\��
}

///<summary>
///<para>�I������</para>
///<para>��������̃^�C�g���̉摜���폜���A�����̏I���������s��</para>
///</summary>
void Title::Finalize() {
	DeleteGraph(title_);
	titlecanvas_->Finalize();
}

///<summary>
///<para>State�̕ύX����</para>
///<para>nextstate_�������̒l�ɕύX����</para>
///<para>����:</para>
///<param name= "state"><para>nextstate_��Copy����l</para></param>
///</summary>
void Title::ChangeState(TitleState state){
	nextstate_ = state;
}
void Title::StartBgm() {
	sound_->PlayBgm(BGM_Menu);
}