#pragma once
#include "ISceneChanger.h"
#include "Sound.h"
//�v���O�������̃V�[���̊��N���X
class BaseScene {

protected:
	ISceneChanger* SceneChanger;    //�N���X���L���ɃV�[���؂�ւ���`����C���^�[�t�F�C�X
	Sound* sound_;
public:
	BaseScene(ISceneChanger* changer,Sound* sound);
	virtual void Initialize() {};    //����������
	virtual void Finalize();        //�I������
	virtual void Update() {};       //�X�V����
	virtual void Draw() {};            //�`�揈��
	virtual void StartBgm() = 0; //Scene���ɖ炷bgm�̐ݒ�
};
