#include "GameClear.h"
#include "DxLib.h"
#include <iostream>
#include "Keyboard.h"
#include "SelectionDeta.h"

GameClear::GameClear(IGameStateChanger* statechanger) : GameSelectionBase(statechanger) {
}
//�Q�[���N���A���̏���������
void GameClear::Initialize() {
	drawingdeta_.push_back((DrawingDeta*)new SelectionDeta(250, 100, "�Q�[���N���A�I", GetColor(0, 0, 0)));
	SelectionBase::Initialize();
}
//�Q�[���N���A���̍X�V����
void GameClear::Update() {
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RETURN) == 1 ||
		Keyboard::getInstance()->CheckKey(KEY_INPUT_ESCAPE) == 1) {
		statechanger_->ChangeState(Game_Exit);//�V�[�������j���[�ɕύX
	}
}