#include "GameMenu.h"
#include "DxLib.h"
#include <assert.h>
#include "SelectionDeta.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�Q�[�����̃��j���[��ʂ̐���</para>
///</summary>
GameMenu::GameMenu(Keyboard* keyboard,IGameStateChanger* statechanger)  : GameSelectionBase(keyboard,statechanger){
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(300, 100, "�Â���", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(300, 150, "�łȂ���", GetColor(0, 0, 0)));
	choicedeta_.push_back((DrawingDeta*)new SelectionDeta(300, 200, "���Ȃ���", GetColor(0, 0, 0)));
}

///<summary>
///<para>�������ݒ�</para>
///<para>�Q�[�����̃��j���[��ʂ̐���</para>
///</summary>
void GameMenu::Initialize() {
	SelectionBase::Initialize();
}

///<summary>
///<para>�X�V����</para>
///<para>Enter�L�[���������ہA�I�񂾑I��������ĈقȂ�State�ɕύX����</para>
///</summary>
void GameMenu::Update() {
	SelectionBase::SelectSelection();
	SelectionBase::SelectionColorChange();
	if (keyboard_->CheckKey(KEY_INPUT_RETURN) == 1) {
		switch (selectnum_) {
		case 0:
			statechanger_->ChangeState(Game_Usually);
			break;
		case 1:
			statechanger_->ChangeState(Game_Exit);
			break;
		case 2:
			statechanger_->ChangeState(Game_Retry);
			break;
		default:
			assert(false);
			break;
		}
	}
}