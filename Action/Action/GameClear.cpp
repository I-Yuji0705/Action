#include "GameClear.h"
#include "DxLib.h"
#include <iostream>
#include "SelectionDeta.h"

GameClear::GameClear(Keyboard* keyboard,IGameStateChanger* statechanger) : GameSelectionBase(keyboard,statechanger) {
	drawingdeta_.push_back((DrawingDeta*)new SelectionDeta(250, 100, "�Q�[���N���A�I", GetColor(0, 0, 0)));
}
//�Q�[���N���A���̏���������
void GameClear::Initialize() {
	SelectionBase::Initialize();
}
//�Q�[���N���A���̍X�V����
void GameClear::Update() {
	if (keyboard_->CheckKey(KEY_INPUT_RETURN) == 1 ||
		keyboard_->CheckKey(KEY_INPUT_ESCAPE) == 1) {
		statechanger_->ChangeState(Game_Exit);//�V�[�������j���[�ɕύX
	}
}