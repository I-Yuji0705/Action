#include "PlayerPick.h"
#include <tuple>

PlayerPick::PlayerPick(Sound* sound, Collision *collision, Player *player) : PlayerAction(player) {
	sound_ = sound;
	collision_ = collision;
}

void PlayerPick::Do() {
	Object *goods = nullptr;
	const float krange = player_->GetWidth(); //Item‚ðE‚¦‚é‰¡•
	float posx[2];//E‚¦‚é”ÍˆÍ‚Ì¶’[‚Æ‰E’[‚ÌXŽ²
	float posy[2];//E‚¦‚é”ÍˆÍ‚Ìã’[‚Æ‰º’[‚ÌYŽ²
	posy[0] = player_->Top();
	posy[1] = player_->Base();
	if (player_->vector_ == 1) { 
		posx[0] = player_->Right();
		posx[1] = player_->Right() + krange;
	}
	else {
		posx[0] = player_->Left() - krange;
		posx[1] = player_->Left();
	}
	goods = collision_->AreaCheck(goods,posx[0],posy[0],posx[1],posy[1], player_);
	if (goods != nullptr){
		if (goods->CanPicked(player_)) {
			goods->Picked(player_);
			player_->carryon_ = goods;
			sound_->PlaySe(Se_Pick, player_);
		}
		else {
			sound_->PlaySe(Se_Cant, player_);
		}
	}
}