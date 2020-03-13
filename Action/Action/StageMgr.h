#pragma once

#include "BaseScene.h"
#include "ISceneChanger.h"
#include "Camera.h"
#include "IGameStateChanger.h"
#include <vector>
#include "Sound.h"

class Sound;
class Camera;
class Collision;
class Object;
//地形の情報
//ゲーム画面クラス
class StageMgr{
private:
	Sound* sound_;
	GameState state;
	std::vector<Object*> stage_;
	Camera playercamera_;
	void CreateStage(const char* stagename);//テキストファイルからステージを生成する
	void CreateStageDeta(const char* stagename);//ステージ生成後にテキストファイルに保存する
	Collision *collision_;
public:
	StageMgr(Sound* sound);
	void Initialize(IGameStateChanger* istatechanger);	//初期化処理
	void Finalize();		//終了処理
	void Update();		//更新処理
	void Draw();			//描写処理
	void Retry();			//リトライ処理
};