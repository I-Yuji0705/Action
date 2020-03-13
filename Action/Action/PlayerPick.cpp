#include "PlayerPick.h"
#include <tuple>

PlayerPick::PlayerPick(Sound* sound, Collision *collision, Player *player) : PlayerAction(player) {
	sound_ = sound;
	collision_ = collision;
}

void PlayerPick::Do() {
	Object *goods = nullptr;
	const float krange = player_->GetWidth(); //Item���E���鉡��
	float posx[2];//�E����͈͂̍��[�ƉE�[��X��
	float posy[2];//�E����͈͂̏�[�Ɖ��[��Y��
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