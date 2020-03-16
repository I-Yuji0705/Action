#include "PlayerDance.h"

///<summary>
///<para>コンストラクタ</para>
///<para>追加でDanceに使用する変数の初期化を行う</para>
///</summary>
PlayerDance::PlayerDance(Player *player) : PlayerAction(player) {
	dancetimer_ = 0;
	choreographnum_ = 0;
}

///<summary>
///<para>ダンスの次の振付に移行する</para>
///<para>ダンスで移動する時間をリセットし、振付を次の段階に移行させる</para>
///</summary>
void PlayerDance::NextChoreoGrap() {
	dancetimer_ = 0;
	choreographnum_++;
}

///<summary>
///<para>行動処理</para>
///<para>振付の番号によって、移動する軸、移動する距離、時間を決め、時間になったら次の振付に移行する</para>
///<para>振付が全て終わった時、GameのstateをClearに変更する</para>
///</summary>
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