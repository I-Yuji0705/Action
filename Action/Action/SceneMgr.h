#pragma once

#include "ISceneChanger.h"
#include "BaseScene.h"
#include "Sound.h"
#include "Screen.h"
#include "Keyboard.h"


enum SceneState {
	Normal_Scene,
	BlackOut_Scene,
	Lighting_Scene,
};
class BaseScene;
class Sound;
//�v���O��������Scene���Ǘ�������N���X
class SceneMgr : public ISceneChanger{
private:
	Keyboard* keyboard_;
	Screen screen;
	BaseScene* scene_;    //�V�[���Ǘ��ϐ�
	Sound* sound_;
	Scene next_scene_;    //���̃V�[���Ǘ��ϐ�
	void BlackOutScene();//��ʂ̕`�ʔ͈͂����߂�
	void LightingScene();//��ʂ̕`�ʔ͈͂��L����
	void SetDepictionScreen(int x1, int y1, int x2, int y2);//�`�ʔ͈͂̐ݒ�
	SceneState state;//���݂�Scene�̏��
	char stagename_[30];
public:
	SceneMgr(Keyboard* keyboard,Sound* sound);
	void Initialize();//������
	void Finalize();//�I������
	void Update();//�X�V
	void Draw();//�`��

	// ���� nextScene �ɃV�[����ύX����
	void ChangeScene(Scene NextScene) final;
	void ChangeScene(Scene NextScene,const char stagename[30]) final;

};