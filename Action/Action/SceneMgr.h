#pragma once

#include "ISceneChanger.h"
#include "BaseScene.h"

struct DepictionScreen {
	int x1;
	int y1;
	int x2;
	int y2;
};
enum SceneState {
	Normal_Scene,
	BlackOut_Scene,
	Lighting_Scene,
};
class SceneMgr : public ISceneChanger{

private:
	DepictionScreen screen;
	BaseScene* scene_;    //�V�[���Ǘ��ϐ�
	Scene next_scene_;    //���̃V�[���Ǘ��ϐ�
	void BlackOutScene();
	void LightingScene();
	void SetDepictionScreen(int x1, int y1, int x2, int y2);
	void MigrationScene();
	SceneState state;
public:
	SceneMgr();
	void Initialize();//������
	void Finalize();//�I������
	void Update();//�X�V
	void Draw();//�`��

	// ���� nextScene �ɃV�[����ύX����
	void ChangeScene(Scene NextScene) override;

};