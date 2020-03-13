#include "GameUsually.h"
#include "DxLib.h"
#include <assert.h>
#include "SelectionDeta.h"

GameUsually::GameUsually(Keyboard* keyboard, IGameStateChanger *statechanger) : GameSelectionBase(keyboard,statechanger) {
	drawingdeta_.push_back((DrawingDeta*)new SelectionDeta(10, 0, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(10, 20, "���E�L�[:�v���C���[�̍��E�ړ�", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(10, 40, "��L�[:�v���C���[�̃W�����v", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(10, 60, "���L�[:�����Ă���A�C�e����u��", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(10, 80, "Ctrl�L�[:�v���C���[�̌����̔��]", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new SelectionDeta(10, 100, "Space�L�[:�A�C�e��������/�����Ă���A�C�e���𓊂���", GetColor(0, 0, 0)));
}
void GameUsually::Initialize() {
	SelectionBase::Initialize();
}
//�ʏ펞�̍X�V����
void GameUsually::Update() {
	if (keyboard_->CheckKey(KEY_INPUT_ESCAPE) == 1) { //Esc�L�[��������Ă�����
		statechanger_->ChangeState(Game_Menu);
	}
}