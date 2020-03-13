#include "PlayerDance.h"


PlayerDance::PlayerDance(Player *player) : PlayerAction(player) {
	dancetimer_ = 0;
	choreographnum_ = 0;
}
//次の振付に移行する
void PlayerDance::NextChoreoGrap() {
	dancetimer_ = 0;
	choreographnum_++;
}
void PlayerDance::Do() {
	//振付の番号によってプレイヤーの移動と向きを変更する
	switch (choreographnum_) {
	case 0:
		player_->vector_ = -1;
		player_->y_ -= 2;
		dancetimer_++;
		if (dancetimer_ > 15) {
			NextChoreoGrap();
		}
		break;
	case 1:
		player_->vector_ = -1;
		player_->y_ += 2;
		dancetimer_++;
		if (dancetimer_ > 15) {
			NextChoreoGrap();
		}
		break;
	case 2:
		player_->vector_ = 1;
		player_->y_ -= 2;
		dancetimer_++;
		if (dancetimer_ > 45) {
			NextChoreoGrap();
		}
		break;
		//全ての振付が終わった際にClearStateに変える
	default:
		player_->state_changer_->ChangeState(Game_Clear);
		break;
	}
}