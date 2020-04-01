#pragma once
#include "ISceneChanger.h"
#include "Sound.h"
#include "Keyboard.h"
class Keyboard;
class Sound;
//�v���O�������̃V�[���̊��N���X
class BaseScene {
protected:
	Keyboard* keyboard_;
	Sound* sound_;
	ISceneChanger* scenechanger_;    //�N���X���L���ɃV�[���؂�ւ���`����C���^�[�t�F�C�X
public:
	BaseScene(Keyboard* keyboard,Sound* sound,ISceneChanger* changer);
	virtual void Initialize() {};    //����������
	virtual void Finalize() {};        //�I������
	virtual void Update() {};       //�X�V����
	virtual void Draw() {};            //�`�揈��
	virtual void StartBgm() = 0; //Scene���ɖ炷bgm�̐ݒ�
};
