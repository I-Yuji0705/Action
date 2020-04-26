#pragma once

#include "BaseScene.h"
#include "ISceneChanger.h"
#include "IGameStateChanger.h"
#include "StageMgr.h"
#include <vector>
#include "GameCanvasBase.h"
//ゲームのシーンクラス
class Game : public BaseScene,IGameStateChanger {
private:
	CanvasBase* gamecanvas_;
	GameState nextstate_;
	StageMgr* stagemgr_;
	char stagename_[30];
public:
	Game(Keyboard* keyboard,Sound* sound,ISceneChanger* changer, const char stagename[30]);
	void Initialize() final;
	void Finalize() final; 
	void Update() final;        
	void Draw() final;
	void StartBgm() final;
	void UpdateNextState();
	void ChangeState(GameState state) final;
};