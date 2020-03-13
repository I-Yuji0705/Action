#pragma once

#include "BaseScene.h"
#include "ISceneChanger.h"
#include "Player.h"
#include "Terrain.h"
#include "Gate.h"
#include "Camera.h"
#include "Item.h"
#include "RelayPoint.h"
#include "IStateChanger.h"
#include <vector>
//地形の情報
//ゲーム画面クラス
class StageMgr{
private:
	State state;
	std::vector<Object*> stage_;
	Camera playerCamera;
	void CreateStage();
	void CreateStageDeta();
public:
	StageMgr();
	void Initialize(IStateChanger* istatechanger);
	void Finalize();
	void Update();
	void Draw();
	void Retry();
};