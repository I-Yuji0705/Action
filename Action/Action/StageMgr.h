#pragma once

#include "BaseScene.h"
#include "ISceneChanger.h"
#include "Camera.h"
#include "IGameStateChanger.h"
#include <vector>
#include "Sound.h"
#include "Keyboard.h"
#include "ColorCode.h"

class Sound;
class Keyboard;
class Camera;
class Collision;
class Object;
//地形の情報
//ゲーム画面クラス
class StageMgr{
private:
	GameState state;
	std::vector<Object*>* stage_;
	Camera* playercamera_;
	Collision* collision_;
	ColorCode color_;
	void CreateStage(Keyboard*keyboard,Sound* sound,IGameStateChanger* statechanger,Collision* collision,const char stagename[30]);//テキストファイルからステージを生成する
	void CreateStageData(Keyboard*keyboard, Sound* sound,IGameStateChanger* statechanger,Collision* collision,const char* stagename);//ステージ生成後にテキストファイルに保存する
public:
	StageMgr(Keyboard* keyboard,Sound* sound, IGameStateChanger* statechanger);
	void Initialize();	//初期化処理
	void Finalize();		//終了処理
	void Update();		//更新処理
	void Draw();			//描写処理
	void Retry();			//リトライ処理
};