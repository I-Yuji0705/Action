#pragma once

enum class GameState {
	Game_Usually,//�Q�[���ʏ펞
	Game_Menu,//�Q�[�����ł̃��j���[���
	Game_Dance,//�N���A�����𖞂������ۂ̃_���X���
	Game_Clear,//�_���X��̃N���A���
	Game_Retry,//���g���C�����̗v��
	Game_Exit,//�Q�[�����I�����A���j���[�ɖ߂�v��

	Game_None//�v������
};

//Game����State������ύX���邽�߂̃C���^�[�t�F�[�X�N���X
class IGameStateChanger {
public:
	virtual ~IGameStateChanger() = 0;
	virtual void ChangeState(GameState state) = 0;
};