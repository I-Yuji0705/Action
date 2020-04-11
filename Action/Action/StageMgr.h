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
//�n�`�̏��
//�Q�[����ʃN���X
class StageMgr{
private:
	GameState state;
	std::vector<Object*>* stage_;
	Camera* playercamera_;
	Collision* collision_;
	ColorCode color_;
	void CreateStage(Keyboard*keyboard,Sound* sound,IGameStateChanger* statechanger,Collision* collision,const char stagename[30]);//�e�L�X�g�t�@�C������X�e�[�W�𐶐�����
	void CreateStageData(Keyboard*keyboard, Sound* sound,IGameStateChanger* statechanger,Collision* collision,const char* stagename);//�X�e�[�W������Ƀe�L�X�g�t�@�C���ɕۑ�����
public:
	StageMgr(Keyboard* keyboard,Sound* sound, IGameStateChanger* statechanger);
	void Initialize();	//����������
	void Finalize();		//�I������
	void Update();		//�X�V����
	void Draw();			//�`�ʏ���
	void Retry();			//���g���C����
};