#pragma once

enum GameState {
	Game_Usually,
	Game_Menu,
	Game_Retry,
	Game_Dance,
	Game_Clear,
	Game_Exit,

	Game_None//����
};

//Game����State������ύX���邽�߂̃C���^�[�t�F�[�X�N���X
class IGameStateChanger {
public:
	virtual ~IGameStateChanger() = 0;
	virtual void ChangeState(GameState state) = 0;
};