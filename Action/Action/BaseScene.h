#pragma once

#include "Task.h"
#include "ISceneChanger.h"
//�V�[���̊��N���X�B
enum StateMenu {
	State_Select,
	State_Delete,

};
class BaseScene : public Task {

protected:
	//int ImageHandle;                //�摜�n���h���i�[�p�ϐ�
	ISceneChanger* SceneChanger;    //�N���X���L���ɃV�[���؂�ւ���`����C���^�[�t�F�C�X
	struct MenuDeta {
		int x, y;
		char name[128];
	};
public:
	BaseScene(ISceneChanger* changer);
	virtual ~BaseScene() {}
	virtual void Initialize() override {}    //�������������I�[�o�[���C�h�B
	virtual void Finalize() override;        //�I���������I�[�o�[���C�h�B
	virtual void Update() override {}       //�X�V�������I�[�o�[���C�h�B
	virtual void Draw() override {}            //�`�揈�����I�[�o�[���C�h�B
};
