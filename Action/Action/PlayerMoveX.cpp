#include "PlayerMoveX.h"
#include <tuple>
#include "DxLib.h"
#include "Keyboard.h"
#include <vector>

PlayerMoveX::PlayerMoveX(Collision *collision, Player *player, Sound* sound) : PlayerAction(collision,player,sound) {
	firsthit_ = true;
}
//プレイヤーのX軸の移動を行う
//	引数:
//		num:移動しようする距離
void PlayerMoveX::MoveX(float num) {
	//プレイヤーのX軸の移動を行う
	bool hit = false;
	int hitpoint;
	std::vector<Object*> hitobject;
	std::tie(hitpoint, hitobject) = collision_->HitCheckX(num, player_);//移動した際に当たるオブジェクトと当たる場所の算出
	if (hitpoint != 0 && !hitobject.empty()) {//当たったObjectがあったか
		if(!Push(num / 2, hitobject))//オブジェクトを押す
			playerhit_->HitProcess(hitpoint, *hitobject.begin());//Hitした時のプレイヤーの位置を調整する
		if (firsthit_) {//Objectに接触し始めたとき
			firsthit_ = false;
			sound_->PlaySe(Se_Hit, player_);
		}
		hit = true;
	}
	if (player_->carryon_ != nullptr) {//何か背負っているとき
		player_->carryon_->Update();
		std::tie(hitpoint, hitobject) = collision_->HitCheckX(num, player_->carryon_);//背負っている物の当たり判定をチェックする
		if (hitpoint != 0 && !hitobject.empty()) {//当たったObjectがあったか
			if(!Push(num / 2, hitobject))//オブジェクトを押す
				playerhit_->HitProcess(hitpoint, *hitobject.begin(), player_->carryon_);//Hitした時のプレイヤーの位置を調整する
			if (firsthit_) {//Objectに接触し始めたとき
				firsthit_ = false;
				sound_->PlaySe(Se_Hit, player_);
			}
			hit = true;
		}
	}
	int mapcheck = collision_->MapCheck(player_->Left() + num, player_);
	if (mapcheck != 0) {//マップ外に移動してしまうか確認する処理
		playerhit_->MapHit(mapcheck);
		hit = true;
		if (firsthit_) {
			firsthit_ = false;
			sound_->PlaySe(Se_Hit, player_);
		}
	}
	if (!hit) {//移動先に何もオブジェクトがなく、マップ外に移動しない場合
		if(abs(num) == kMoveSpeed)//プレイヤーの最初の移動が成功したとき
			firsthit_ = true;//次にObjectに接触した際に音が鳴るようにする
		player_->x_ += num;
	}
}
//-----------------
//Objectを押し出し、少しでも押すことができたかを返す
//		引数:
//				num:押そうとする距離の初期値
//				target:押そうとする対象
//		返り値:
//				true:Objectを押し出すことができた
//				false:Objectを押し出せなかった
bool PlayerMoveX::Push(float num, std::vector<Object*> target) {
	float canpushed = 0.0f;
	bool push = false;
	if (player_->player_state_ == Player_Land) {//地上にいるとき
		for (auto i : target) {
			if (i == *target.begin() || canpushed > i->CanPushed(num)) {//
				canpushed = i->CanPushed(num);//押し出せる距離を算出
			}
		}
		for (auto i : target) {
			i->Pushed(canpushed);
		}
		MoveX(canpushed);
	}
	if (canpushed != 0.0f) push = true;
	return push;
}