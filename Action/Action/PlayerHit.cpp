#include "PlayerHit.h"
#include <assert.h>

///<summary>
///<para>コンストラクタ</para>
///<para>追加で、操作するPlayerのポインタを取得する</para>
///<param name="player"><para>player:操作する対象のPlayerクラスのポインタ</para></param>
///</summary>
PlayerHit::PlayerHit(Collision* collision,Player* player) : Hit(collision) {
	player_ = player;
}

///<summary>
///<para>接触処理</para>
///<para>引数で受け取ったintの数値によってX軸かY軸に受け取ったfloatの数値分加算し、player_のstateを変更する</para>
///<para>intの数字が4の時、angleも変更する</para>
///<param name="check"><para>check:Collision::HitCheckXやCollision::HitCheckX、Collision::MapCheckの戻り値の一つであるint型の数値</para></param>
///<param name="distance"><para>distance:Collision::HitCheckXやCollision::HitCheckX、Collision::MapCheckの戻り値の一つであるfloat型の数値</para></param>
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