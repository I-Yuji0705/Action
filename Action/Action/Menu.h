#pragma once
#include "BaseScene.h"
//enum StateMenu {
//	State_Select,
//	State_Delete,
//
//};
//���j���[��ʃN���X
class Menu : public BaseScene {
private:
	int MenuNum;
	MenuDeta menudeta[3];
	MenuDeta deletemessage[2]; 
	StateMenu state;//
	void SelectMenu();//���j���[����
	void SelectDelete();//�I���m�F
	int DeleteNum;
public:
	Menu(ISceneChanger* changer);
	void Initialize() override;    //�������������I�[�o�[���C�h�B
	void Update() override;        //�X�V�������I�[�o�[���C�h�B
	void Draw() override;            //�`�揈�����I�[�o�[���C�h�B
};
