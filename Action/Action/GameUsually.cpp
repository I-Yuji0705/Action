#include "GameUsually.h"
#include "DxLib.h"
#include <assert.h>
#include "TextDeta.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�Q�[���̒ʏ펞�ɕ\�����鎚���̐���</para>
///</summary>
GameUsually::GameUsually(Keyboard* keyboard, IGameStateChanger *statechanger) : GameCanvasBase(keyboard,statechanger) {
	drawingdeta_.push_back((DrawingDeta*)new TextDeta(10, 0, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(10, 20, "���E�L�[:�v���C���[�̍��E�ړ�", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(10, 40, "��L�[:�v���C���[�̃W�����v", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(10, 60, "���L�[:�����Ă���A�C�e����u��", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(10, 80, "Ctrl�L�[:�v���C���[�̌����̔��]", GetColor(0, 0, 0)));
	drawingdeta_.push_back((DrawingDeta*) new TextDeta(10, 100, "Space�L�[:�A�C�e��������/�����Ă���A�C�e���𓊂���", GetColor(0, 0, 0)));
}

///<summary>
///<para>�X�V����</para>
///<para>Escape�L�[����͂���ƁA�Q�[�����j���[�̕\����v������</para>
///</summary>
void GameUsually::Update() {
	if (keyboard_->CheckKey(KEY_INPUT_ESCAPE) == 1) { //Esc�L�[��������Ă�����
		statechanger_->ChangeState(Game_Menu);
	}
}