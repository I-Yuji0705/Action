#include "SceneMgr.h"
#include "DxLib.h"
#include "Title.h"
#include "Game.h"
#include "Manual.h"
#include <assert.h>

///<summary>
///<para>�R���X�g���N�^</para>
///<para>Scene���Ŏg�p����L�[�{�[�h�N���X�Ɖ��𔭐�������N���X���擾����</para>
///<para>�ǉ��ŁA�ŏ���Scene��Title�ɐݒ肷��</para>
///<para>����:</para>
///<param name= "keyboard"><para>�L�[��������Ă��邩�m�F����N���X</para></param>
///<param name= "sound"><para>BGM��SE�Ȃǂ̉��𔭐�������N���X</para></param>
///</summary>
SceneMgr::SceneMgr(Keyboard* keyboard,Sound* sound) : next_scene_(Scene_None) //���̃V�[���Ǘ��ϐ�
{
	keyboard_ = keyboard;
	sound_ = sound;
	scene_ = (BaseScene*) new Title(keyboard_, sound_, this);
	//scene_->StartBgm();
	state = Normal_Scene;
}

//������
///<summary>
///<para>����������</para>
///<para>Scene�̏������������s��</para>
///</summary>
void SceneMgr::Initialize() {
	scene_->Initialize();
}

//�I������
///<summary>
///<para>�I������</para>
///<para>Scene�̏I���������s��</para>
///</summary>
void SceneMgr::Finalize() {
	scene_->Finalize();
	sound_->Finalize();
}

//�X�V
///<summary>
///<para>�X�V����</para>
///<para>Scene�̕ύX�v�����Ȃ��ꍇ�AScene�̍X�V�������s��</para>
///<para>Scene�̕ύX�v�����������ꍇ�A��ʂ��Â����n�߂�</para>
///</summary>
void SceneMgr::Update() {
	switch (state) {
	case Normal_Scene:
		if (next_scene_ != Scene_None) {    //���̃V�[�����Z�b�g����Ă�����
			state = BlackOut_Scene;
			sound_->StopBgm();
			sound_->StopSe();
			sound_->PlaySe(Se_SceneChange);
		}
		scene_->Update(); //�V�[���̍X�V
		break;
	case BlackOut_Scene:
		BlackOutScene();
		break;
	case Lighting_Scene:
		LightingScene();
		break;
	default:
		assert(false);
		break;
	}
}

//�`��

///<summary>
///<para>�`�ʏ���</para>
///<para>Scene�̕`�ʏ������s��</para>
///</summary>
void SceneMgr::Draw() {
	scene_->Draw(); //�V�[���̕`��
}

// ���� nextScene �ɃV�[����ύX����

///<summary>
///<para>�V�[���̕ύX����</para>
///<para>���̃V�[�����Z�b�g���A�`�ʔ͈͂�ݒ肵�Ȃ���</para>
///</summary>
void SceneMgr::ChangeScene(Scene nextscene) {
	next_scene_ = nextscene;    //���̃V�[�����Z�b�g����
	SetDepictionScreen(0, 0, 640, 480);
}

///<summary>
///<para>�V�[���̈Ó]����</para>
///<para>�`�ʔ͈͂����߂邱�Ƃŉ�ʂ��Â�����</para>
///<para>�`�ʔ͈͂𖳂�������A�V�[���̕ύX�������s���AState���Ó]�̏�Ԃ��疾�邭�����ԂɕύX����</para>
///</summary>
void SceneMgr::BlackOutScene() {
	const int animationspeed = 2;
	SetDepictionScreen(screen.x1 + animationspeed * 3, screen.y1 + animationspeed * 4, screen.x2 - animationspeed * 3, screen.y2 - animationspeed * 4);
	if (screen.x1 > screen.x2 || screen.y1 > screen.y2) {
		state = Lighting_Scene;
		scene_->Finalize();//���݂̃V�[���̏I�����������s
		delete scene_;
		switch (next_scene_) {       //�V�[���ɂ���ď����𕪊�
		case Scene_Title:        //���̉�ʂ����j���[�Ȃ�
			scene_ = (BaseScene*) new Title(keyboard_, sound_,this);   //���j���[��ʂ̃C���X�^���X�𐶐�����
			break;
		case Scene_Game:        //���̉�ʂ��Q�[���Ȃ�
			scene_ = (BaseScene*) new Game(keyboard_, sound_, this);   //�Q�[����ʂ̃C���X�^���X�𐶐�����
			break;
		case Scene_Manual:        //���̉�ʂ��}�j���A���Ȃ�
			scene_ = (BaseScene*) new Manual(keyboard_, sound_, this);   //�}�j���A����ʂ̃C���X�^���X�𐶐�����
			break;
		default:
			assert(false);
			break;
		}
		next_scene_ = Scene_None;    //���̃V�[�������N���A
		scene_->Initialize();    //�V�[����������
	}
}

///<summary>
///<para>�V�[���̖��邭���鏈��</para>
///<para>�`�ʔ͈͂��L���邱�Ƃŉ�ʂ𖾂邭����</para>
///<para>�`�ʔ͈͂���ʂ܂ōL������AScene����BGM���Đ����AState��ʏ펞�ɕύX����</para>
///</summary>
void SceneMgr::LightingScene() {
	const int animationspeed = 2;
	SetDepictionScreen(screen.x1 - animationspeed * 3, screen.y1 - animationspeed * 4, screen.x2 + animationspeed * 3, screen.y2 + animationspeed * 4);
	if (screen.x1 < 0 && screen.x2 > 480 && screen.y1 < 0 && screen.y2 > 640) { 
		state = Normal_Scene;
		SetDepictionScreen(0, 0, 640, 480);
		//scene_->StartBgm();
	}
}

///<summary>
///<para>�V�[���̕`�ʔ͈͂̕ύX����</para>
///<para>�`�ʂ���͈͂̍����X���W��Y���W�A�E����X���W��Y���W�������Ƃ��Ď󂯎��</para>
///<para>�V�[���̕`�ʔ͈͂�ϐ��ɕۑ�������A�󂯎�������W��Ίp���Ƃ���l�p�`��`�ʔ͈͂Ƃ��Đݒ肷��</para>
///<para>����:</para>
///<param name="x1"><para>x1:�`�ʂ���͈͂̍����X���W</para></param>
///<param name="y1"><para>y1:�`�ʂ���͈͂̍����Y���W</para></param>
///<param name="x2"><para>x2:�`�ʂ���͈͂̉E����X���W</para></param>
///<param name="y2"><para>y2:�`�ʂ���͈͂̉E����X���W</para></param>
///</summary>
void SceneMgr::SetDepictionScreen(int x1, int y1, int x2, int y2) {
	screen.x1 = x1;
	screen.y1 = y1;
	screen.x2 = x2;
	screen.y2 = y2;
	SetDrawArea(screen.x1, screen.y1, screen.x2, screen.y2);
}