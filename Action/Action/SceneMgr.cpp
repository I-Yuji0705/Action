#include "SceneMgr.h"
#include "DxLib.h"
#include "Menu.h"
#include "Game.h"
SceneMgr::SceneMgr() : NextScene(Scene_None) //���̃V�[���Ǘ��ϐ�
{
	scene = (BaseScene*) new Menu(this);
}

//������
void SceneMgr::Initialize() {
	scene->Initialize();
}

//�I������
void SceneMgr::Finalize() {
	scene->Finalize();
}

//�X�V
void SceneMgr::Update() {
	if (NextScene != Scene_None) {    //���̃V�[�����Z�b�g����Ă�����
		scene->Finalize();//���݂̃V�[���̏I�����������s
		delete scene;
		switch (NextScene) {       //�V�[���ɂ���ď����𕪊�
		case Scene_Menu:        //���̉�ʂ����j���[�Ȃ�
			scene = (BaseScene*) new Menu(this);   //���j���[��ʂ̃C���X�^���X�𐶐�����
			break;//�ȉ���
		case Scene_Game:        //���̉�ʂ����j���[�Ȃ�
			scene = (BaseScene*) new Game(this);   //���j���[��ʂ̃C���X�^���X�𐶐�����
			break;//�ȉ���
		}
		
		NextScene = Scene_None;    //���̃V�[�������N���A
		scene->Initialize();    //�V�[����������
	}

	scene->Update(); //�V�[���̍X�V
}

//�`��
void SceneMgr::Draw() {
	scene->Draw(); //�V�[���̕`��
}

// ���� nextScene �ɃV�[����ύX����
void SceneMgr::ChangeScene(Scene nextScene) {
	NextScene = nextScene;    //���̃V�[�����Z�b�g����
}