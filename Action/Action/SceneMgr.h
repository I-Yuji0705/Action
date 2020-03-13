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
	BaseScene* scene_;    //シーン管理変数
	Scene next_scene_;    //次のシーン管理変数
	void BlackOutScene();
	void LightingScene();
	void SetDepictionScreen(int x1, int y1, int x2, int y2);
	void MigrationScene();
	SceneState state;
public:
	SceneMgr();
	void Initialize();//初期化
	void Finalize();//終了処理
	void Update();//更新
	void Draw();//描画

	// 引数 nextScene にシーンを変更する
	void ChangeScene(Scene NextScene) override;

};