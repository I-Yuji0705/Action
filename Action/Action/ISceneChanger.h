#pragma once

enum class Scene{
	Scene_Title,    //�^�C�g�����
	Scene_Game,	//�Q�[�����
	Scene_Manual,//�}�j���A�����

	Scene_None    //����
};

//�v���O�������̃V�[�������ύX���邽�߂̃C���^�[�t�F�[�X�N���X
class ISceneChanger {
public:
	virtual ~ISceneChanger() = 0;
	virtual void ChangeScene(Scene NextScene) = 0;//�w��V�[���ɕύX����
	virtual void ChangeScene(Scene NextScene,const char stagename[30]) = 0;
};