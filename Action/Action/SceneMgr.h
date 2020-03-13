#pragma once

#include "ISceneChanger.h"
#include "BaseScene.h"
#include "Sound.h"
#include "Screen.h"


enum SceneState {
	Normal_Scene,
	BlackOut_Scene,
	Lighting_Scene,
};
class BaseScene;
class Sound;
class SceneMgr : public ISceneChanger{
private:
	Screen screen;
	BaseScene* scene_;    //�V�[���Ǘ��ϐ�
	Sound* sound_;
	Scene next_scene_;    //���̃V�[���Ǘ��ϐ�
	void BlackOutScene();//��ʂ̕`�ʔ͈͂����߂�
	void LightingScene();//��ʂ̕`�ʔ͈͂��L����
	void SetDepictionScreen(int x1, int y1, int x2, int y2);//�`�ʔ͈͂̐ݒ�
	SceneState state;//���݂�Scene�̏��
public:
	SceneMgr();
	void Initialize();//������
	void Finalize();//�I������
	void Update();//�X�V
	void Draw();//�`��

	// ���� nextScene �ɃV�[����ύX����
	void ChangeScene(Scene NextScene) final;

};