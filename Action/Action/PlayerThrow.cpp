#include "PlayerThrow.h"

PlayerThrow::PlayerThrow(Collision *collision, Player *player, Sound* sound) : PlayerAction(collision, player,sound) {
}

void PlayerThrow::Do() {
	if (player_->carryon_->CanThrew()) {
		player_->carryon_->Threw();
		player_->carryon_ = nullptr;
		sound_->PlaySe(Se_Throw,player_);
	}
	else {
		sound_->PlaySe(Se_Cant, player_);
	}
}