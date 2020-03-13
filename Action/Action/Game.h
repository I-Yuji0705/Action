#pragma once

#include "BaseScene.h"
#include "ISceneChanger.h"
#include "IStateChanger.h"
#include "StageMgr.h"
#include <vector>
//�n�`�̏��
//�Q�[����ʃN���X
class Game : public BaseScene,IStateChanger {
private:
	State state;
	MenuDeta retryMessage_[2];
	MenuDeta menuMessage_[3];
	StageMgr* stagemgr_;
	int selectRetryNum;
	int selectMenuNum;
	void NormalUpdate();
	void NormalDraw();
	void MenuInitialize();
	void MenuUpdate();
	void MenuDraw();
	void RetryInitialize();
	void RetryUpdate();
	void RetryDraw();
	void Retry();
	void ClearUpdate();
	void ClearDraw();
public:
	Game(ISceneChanger* changer);
	void Initialize() override;
	void Finalize() override;        
	void Update() override;        
	void Draw() override;            
	void ChangeState(State state)override;
};