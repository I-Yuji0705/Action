#pragma once
#include "BaseScene.h"
#include "TextData.h"
#include "IManualStateChanger.h"
#include "ManualCanvasBase.h"

//�}�j���A����Scene�N���X
class Manual : public BaseScene, IManualStateChanger {
private:
	CanvasBase* manualcanvas_;
	ManualState nextstate_;//
public:
	Manual(Keyboard* keyboard, Sound* sound,ISceneChanger* changer);
	void ChangeState(ManualState state);
	void Initialize() final;    //����������
	void Update() final;        //�X�V����
	void Draw() final;            //�`�揈��
	void Finalize() final;	//�I������
	void StartBgm() final; //BGM�̍Đ�����
};