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
//プログラム内のSceneを管理する基底クラス
class SceneMgr : public ISceneChanger{
private:
	Keyboard* keyboard_;
	Screen screen;
	BaseScene* scene_;    //シーン管理変数
	Sound* sound_;
	Scene next_scene_;    //次のシーン管理変数
	void BlackOutScene();//画面の描写範囲を狭める
	void LightingScene();//画面の描写範囲を広げる
	void SetDepictionScreen(int x1, int y1, int x2, int y2);//描写範囲の設定
	SceneState state;//現在のSceneの状態
	char stagename_[30];
public:
	SceneMgr(Keyboard* keyboard,Sound* sound);
	void Initialize();//初期化
	void Finalize();//終了処理
	void Update();//更新
	void Draw();//描画

	// 引数 nextScene にシーンを変更する
	void ChangeScene(Scene NextScene) final;
	void ChangeScene(Scene NextScene,const char stagename[30]) final;

};