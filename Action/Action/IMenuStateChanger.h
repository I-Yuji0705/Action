#pragma once

enum MenuState {
	Menu_Usually,
	Menu_Delete,
	Menu_Game,
	Menu_Exit,
	Menu_Intersection,

	Menu_None//����
};
//Menu����State������ύX���邽�߂̃C���^�[�t�F�[�X�N���X
class IMenuStateChanger {
public:
	virtual ~IMenuStateChanger() = 0;
	virtual void ChangeState(MenuState state) = 0;
};