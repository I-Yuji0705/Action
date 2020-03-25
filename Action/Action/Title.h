#pragma once
#include "BaseScene.h"
#include "TextDeta.h"
#include "ITitleStateChanger.h"
#include "CanvasBase.h"

//���j���[��Scene�N���X
class Title : public BaseScene ,ITitleStateChanger{
private:
	CanvasBase* titlecanvas_;
	TitleState nextstate_;//
	int title_;
public:
	Title(Keyboard* keyboard,Sound* sound,ISceneChanger* changer);
	void ChangeState(TitleState state);
	void Initialize() final;    //����������
	void Update() final;        //�X�V����
	void Draw() final;            //�`�揈��
	void Finalize() final;
	void StartBgm() final;
};
