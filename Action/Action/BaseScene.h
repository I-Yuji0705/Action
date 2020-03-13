#pragma once
#include "ISceneChanger.h"
//�V�[���̊��N���X�B
enum StateMenu {
	State_Select,
	State_Delete,
};
class BaseScene {

protected:
	ISceneChanger* SceneChanger;    //�N���X���L���ɃV�[���؂�ւ���`����C���^�[�t�F�C�X
	struct MenuDeta {
		int x, y;
		char name[128];
	};
public:
	BaseScene(ISceneChanger* changer);
	virtual void Initialize() {};    //�������������I�[�o�[���C�h
	virtual void Finalize();        //�I���������I�[�o�[���C�h
	virtual void Update() {};       //�X�V�������I�[�o�[���C�h
	virtual void Draw() {};            //�`�揈�����I�[�o�[���C�h
};
