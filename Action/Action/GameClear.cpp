#include "GameClear.h"
#include "DxLib.h"
#include <iostream>
#include "TextData.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�Q�[���N���A���̎����̐���</para>
///</summary>
GameClear::GameClear(Keyboard* keyboard,IGameStateChanger* statechanger) : GameCanvasBase(keyboard,statechanger) {
	drawingData_.push_back((DrawingData*)new TextData(250, 100, "�Q�[���N���A�I", GetColor(0, 0, 0)));
}

///<summary>
///<para>�X�V����</para>
///<para>Enter�L�[���AEscape�L�[���������ꍇ�A�^�C�g���V�[���Ɉڍs����</para>
///</summary>
void GameClear::Update() {
	if (keyboard_->CheckKey(KEY_INPUT_RETURN) == 1 ||
		keyboard_->CheckKey(KEY_INPUT_ESCAPE) == 1) {
		statechanger_->ChangeState(GameState::Game_Exit);//�V�[�����^�C�g���ɕύX
	}
}