#include "PlayerPut.h"
#include <tuple>
PlayerPut::PlayerPut(Sound* sound, Player *player) : PlayerAction(player) {
	sound_ = sound;
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