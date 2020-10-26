#pragma once

enum class TitleState {
	Title_Usually,//�������
	Title_Delete, //�I���m�F���
	Title_Game, //�Q�[���V�[���Ɉڍs
	Title_Exit, //�Q�[���I��
	Title_Intersection, //�����V�[���Ɉڍs
	Title_StageSelect, //�X�e�[�W�I����ʂɈڍs

	Title_None//����
};
//Title����State������ύX���邽�߂̃C���^�[�t�F�[�X�N���X
class ITitleStateChanger {
public:
	virtual ~ITitleStateChanger() = 0;
	virtual void ChangeState(TitleState state) = 0;
	virtual void ChangeState(TitleState state, const char stagename[30]) = 0;
};