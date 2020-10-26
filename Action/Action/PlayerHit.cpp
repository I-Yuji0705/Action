#include "PlayerHit.h"
#include <assert.h>

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�ǉ��ŁA���삷��Player�̃|�C���^���擾����</para>
///<param name="player"><para>player:���삷��Ώۂ�Player�N���X�̃|�C���^</para></param>
///</summary>
PlayerHit::PlayerHit(Collision* collision,Player* player) : Hit(collision) {
	player_ = player;
}

///<summary>
///<para>�ڐG����</para>
///<para>�����Ŏ󂯎����int�̐��l�ɂ����X����Y���Ɏ󂯎����float�̐��l�����Z���Aplayer_��state��ύX����</para>
///<para>int�̐�����4�̎��Aangle���ύX����</para>
///<param name="check"><para>check:Collision::HitCheckX��Collision::HitCheckX�ACollision::MapCheck�̖߂�l�̈�ł���int�^�̐��l</para></param>
///<param name="distance"><para>distance:Collision::HitCheckX��Collision::HitCheckX�ACollision::MapCheck�̖߂�l�̈�ł���float�^�̐��l</para></param>
///</summary>
void PlayerHit::HitObjects(int check, float distance) {
	int hitangle = 60;
	switch (check) {
	case 1:
	case 2:
		player_->Set(player_->Left() + distance, player_->Top());
		break;
	case 3:
		player_->Set(player_->Left(), player_->Top() + distance);
		player_->player_state_ = StateCharacter::Player_Land;
		break;
	case 4:
		player_->angle_ = hitangle;
		player_->Set(player_->Left(), player_->Top() + distance);
		break;
	default:
		assert(false);
		break;
	}
	if (player_->carryon_ != nullptr)
		player_->carryon_->Update();
}