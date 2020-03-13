#include "PlayerPut.h"
#include <tuple>
PlayerPut::PlayerPut(Collision *collision, Player *player, Sound* sound) : PlayerAction(collision, player,sound) {
}

void PlayerPut::Do() {
	if (player_->carryon_->CanPutted()) {
		player_->carryon_->Putted();
		player_->carryon_ = nullptr;
		sound_->PlaySe(Se_Put, player_);
	}
	else {
		sound_->PlaySe(Se_Cant, player_);
	}
}