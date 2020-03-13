#pragma once

enum ManualState {
	Manual_Usually,
	Manual_Operation,
	Manual_Stage,
	Manual_Rule,
	Manual_Exit,

	Manual_None//����
};
//Manual����State������ύX���邽�߂̃C���^�[�t�F�[�X�N���X
class IManualStateChanger {
public:
	virtual ~IManualStateChanger() = 0;
	virtual void ChangeState(ManualState state) = 0;
};