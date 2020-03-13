#pragma once
#include "BaseScene.h"
#include "SelectionDeta.h"
#include "IManualStateChanger.h"
#include "ManualSelectionBase.h"

//�}�j���A����Scene�N���X
class Manual : public BaseScene, IManualStateChanger {
private:
	ManualSelectionBase* manualselection_;
	ManualState nextstate_;//
public:
	Manual(ISceneChanger* changer, Sound* sound);
	void ChangeState(ManualState state);
	void Initialize() final;    //����������
	void Update() final;        //�X�V����
	void Draw() final;            //�`�揈��
	void Finalize() final;	//�I������
	void StartBgm() final; //BGM�̍Đ�����
};