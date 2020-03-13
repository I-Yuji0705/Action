#pragma once
#include "BaseScene.h"
#include "SelectionDeta.h"
#include "IMenuStateChanger.h"
#include "MenuSelectionBase.h"

//���j���[��Scene�N���X
class Menu : public BaseScene ,IMenuStateChanger{
private:
	MenuSelectionBase* menuselection_;
	MenuState nextstate_;//
	int title_;
public:
	Menu(ISceneChanger* changer,Sound* sound);
	void ChangeState(MenuState state);
	void Initialize() final;    //����������
	void Update() final;        //�X�V����
	void Draw() final;            //�`�揈��
	void Finalize() final;
	void StartBgm() final;
};
