#pragma once
#include "BaseScene.h"
#include "TextData.h"
#include "ITitleStateChanger.h"
#include "CanvasBase.h"

//���j���[��Scene�N���X
class Title : public BaseScene ,ITitleStateChanger{
private:
	CanvasBase* titlecanvas_;
	TitleState nextstate_;//
	int title_;
	char stagename_[30];
public:
	Title(Keyboard* keyboard,Sound* sound,ISceneChanger* changer);
	void ChangeState(TitleState state);
	void ChangeState(TitleState state, const char stagename[30]);
	void Initialize() final;    //����������
	void Update() final;        //�X�V����
	void Draw() final;            //�`�揈��
	void Finalize() final;
	void StartBgm() final;
};
