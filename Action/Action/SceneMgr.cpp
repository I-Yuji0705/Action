#include "SceneMgr.h"
#include "DxLib.h"
#include "Title.h"
#include "Game.h"
#include "Manual.h"
#include <assert.h>

SceneMgr::SceneMgr(Keyboard* keyboard,Sound* sound) : next_scene_(Scene_None) //���̃V�[���Ǘ��ϐ�
{
	keyboard_ = keyboard;
	sound_ = sound;
	scene_ = (BaseScene*) new Title(keyboard_, sound_, this);
	//scene_->StartBgm();
	state = Normal_Scene;
}

//������
void SceneMgr::Initialize() {
	scene_->Initialize();
}

//�I������
void SceneMgr::Finalize() {
	scene_->Finalize();
	sound_->Finalize();
}

//�X�V
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
void SceneMgr::Draw() {
	scene_->Draw(); //�V�[���̕`��
}

// ���� nextScene �ɃV�[����ύX����
void SceneMgr::ChangeScene(Scene nextscene) {
	next_scene_ = nextscene;    //���̃V�[�����Z�b�g����
	SetDepictionScreen(0, 0, 640, 480);
}
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
void SceneMgr::LightingScene() {
	const int animationspeed = 2;
	SetDepictionScreen(screen.x1 - animationspeed * 3, screen.y1 - animationspeed * 4, screen.x2 + animationspeed * 3, screen.y2 + animationspeed * 4);
	if (screen.x1 < 0 && screen.x2 > 480 && screen.y1 < 0 && screen.y2 > 640) { 
		state = Normal_Scene; 
		//scene_->StartBgm();
	}
}
void SceneMgr::SetDepictionScreen(int x1, int y1, int x2, int y2) {
	screen.x1 = x1;
	screen.y1 = y1;
	screen.x2 = x2;
	screen.y2 = y2;
	SetDrawArea(screen.x1, screen.y1, screen.x2, screen.y2);
}