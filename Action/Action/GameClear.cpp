#include "GameClear.h"
#include "DxLib.h"
#include <iostream>
#include "SelectionDeta.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�Q�[���N���A���̎����̐���</para>
///</summary>
GameClear::GameClear(Keyboard* keyboard,IGameStateChanger* statechanger) : GameSelectionBase(keyboard,statechanger) {
	drawingdeta_.push_back((DrawingDeta*)new SelectionDeta(250, 100, "�Q�[���N���A�I", GetColor(0, 0, 0)));
}

///<summary>
///<para>����������</para>
///</summary>
void GameClear::Initialize() {
	SelectionBase::Initialize();
}

///<summary>
///<para>�X�V����</para>
///<para>Enter�L�[���AEscape�L�[���������ꍇ�A���j���[�V�[���Ɉڍs����</para>
///</summary>
void GameClear::Update() {
	if (keyboard_->CheckKey(KEY_INPUT_RETURN) == 1 ||
		keyboard_->CheckKey(KEY_INPUT_ESCAPE) == 1) {
		statechanger_->ChangeState(Game_Exit);//�V�[�������j���[�ɕύX
	}
}