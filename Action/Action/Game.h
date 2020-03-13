#pragma once

#include "BaseScene.h"
#include "ISceneChanger.h"
#include "Camera.h"
#include "IStateChanger.h"
//�n�`�̏��
//�Q�[����ʃN���X
class Game : public BaseScene,IStateChanger {
private:
	MenuDeta retryMessage[2];
	Object *stage[15];
	Camera playerCamera;
	int selectNum;
	void NormalUpdate();
	void NormalDraw();
	void RetryInitialize();
	void RetryUpdate();
	void RetryDraw();
	void Retry();
	void DanceUpdate();
	void ClearUpdate();
	void ClearDraw();
	State state;
public:
	Game(ISceneChanger* changer);
	void Initialize() override;    //�������������I�[�o�[���C�h�B
	void Finalize() override;        //�I���������I�[�o�[���C�h�B
	void Update() override;        //�X�V�������I�[�o�[���C�h�B
	void Draw() override;            //�`�揈�����I�[�o�[���C�h�B
	void ChangeState(State state)override;

};