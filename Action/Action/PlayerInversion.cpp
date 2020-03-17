#include "PlayerInversion.h"
#include "DxLib.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�ǉ��ŃL�[��������Ă��邩�m�F����Keyboard�N���X���擾����</para>
///</summary>
PlayerInversion::PlayerInversion(Keyboard* keyboard,Player *player) : PlayerAction(player) {
	keyboard_ = keyboard;
}

///<para>�s������</para>
///<para>Ctrl�L�[���������ꍇ�A�v���C���[�̌�����ς���</para>
///</summary>
void PlayerInversion::Do() {
	if (keyboard_->CheckKey(KEY_INPUT_LCONTROL) == 1 || keyboard_->CheckKey(KEY_INPUT_RCONTROL) == 1)
		player_->vector_ *= -1;//�v���C���[�̌����𔽓]
}