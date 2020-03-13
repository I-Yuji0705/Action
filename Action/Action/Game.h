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
//地形の情報
//ゲーム画面クラス
class Game : public BaseScene,IStateChanger {
private:
	MenuDeta retryMessage[2];
	Object *stage[15];
	Terrain terrain[10];
	Item item[3];
	Gate gate;
	RelayPoint relaypoint[3];
	Player player;
	Camera playerCamera;
	int selectNum;
	void RetryInitialize();
	void RetryUpdate();
	void RetryDraw();
	void Retry();
	void ClearUpdate();
	void ClearDraw();
	void Select();
	void Normal();
	State state;
public:
	Game(ISceneChanger* changer);
	void Initialize() override;    //初期化処理をオーバーライド。
	void Finalize() override;        //終了処理をオーバーライド。
	void Update() override;        //更新処理をオーバーライド。
	void Draw() override;            //描画処理をオーバーライド。
	void ChangeState(State state)override;

};