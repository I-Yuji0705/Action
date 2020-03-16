#include "PlayerGravity.h"

///<summary>
///<para>コンストラクタ</para>
///</summary>
PlayerGravity::PlayerGravity(Sound* sound, Collision *collision, Player *player, PlayerHit* playerhit)  : PlayerMoveY(sound, collision, player,playerhit){
}

///<summary>
///<para>行動処理</para>
///<para>重力分、Y軸の移動処理を行う</para>
///</summary>
void PlayerGravity::Do() {
	MoveY(gravity_.kGravity);
}