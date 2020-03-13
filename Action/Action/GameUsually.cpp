#include "GameUsually.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "SelectionDeta.h"

GameUsually::GameUsually(IGameStateChanger *statechanger) : GameSelectionBase(statechanger) {
}
void GameUsually::Initialize() {
	drawingdeta_.push_back((DrawingDeta*)new SelectionDeta(10, 0, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(0, 0, 0)));
	SelectionBase::Initialize();

}
//�ʏ펞�̍X�V����
void GameUsually::Update() {
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_ESCAPE) == 1) { //Esc�L�[��������Ă�����
		statechanger_->ChangeState(Game_Menu);
	}
}