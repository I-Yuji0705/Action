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
//�n�`�̏��
//�Q�[����ʃN���X
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
	void Initialize() override;    //�������������I�[�o�[���C�h�B
	void Finalize() override;        //�I���������I�[�o�[���C�h�B
	void Update() override;        //�X�V�������I�[�o�[���C�h�B
	void Draw() override;            //�`�揈�����I�[�o�[���C�h�B
	void ChangeState(State state)override;

};