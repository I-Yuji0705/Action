#include "PlayerGravity.h"

///<summary>
///<para>�R���X�g���N�^</para>
///</summary>
PlayerGravity::PlayerGravity(Sound* sound, Collision *collision, Player *player, PlayerHit* playerhit)  : PlayerMoveY(sound, collision, player,playerhit){
}

///<summary>
///<para>�s������</para>
///<para>�d�͕��AY���̈ړ��������s��</para>
///</summary>
void PlayerGravity::Do() {
	MoveY(gravity_.kGravity);
}