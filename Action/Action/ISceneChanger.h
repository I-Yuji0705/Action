#pragma once

enum Scene{
	Scene_Menu,    //���j���[���
	Scene_Game,
	Scene_None,    //����
};

//�V�[����ύX���邽�߂̃C���^�[�t�F�C�X�N���X
class ISceneChanger {
public:
	virtual ~ISceneChanger() = 0;
	virtual void ChangeScene(Scene NextScene) = 0;//�w��V�[���ɕύX����
};