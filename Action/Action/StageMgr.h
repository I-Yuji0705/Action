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
//�n�`�̏��
//�Q�[����ʃN���X
class StageMgr{
private:
	Sound* sound_;
	GameState state;
	std::vector<Object*> stage_;
	Camera playercamera_;
	void CreateStage(const char* stagename);//�e�L�X�g�t�@�C������X�e�[�W�𐶐�����
	void CreateStageDeta(const char* stagename);//�X�e�[�W������Ƀe�L�X�g�t�@�C���ɕۑ�����
	Collision *collision_;
public:
	StageMgr(Sound* sound);
	void Initialize(IGameStateChanger* istatechanger);	//����������
	void Finalize();		//�I������
	void Update();		//�X�V����
	void Draw();			//�`�ʏ���
	void Retry();			//���g���C����
};