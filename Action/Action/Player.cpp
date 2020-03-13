#include "Player.h"
#include "DxLib.h"
#include "Keyboard.h"
#include "PlayerMoveRight.h"
#include "PlayerMoveLeft.h"
#include "PlayerJump.h"
#include "PlayerThrow.h"
#include "PlayerPick.h"
#include "PlayerPut.h"
#include "PlayerGravity.h"
#include "PlayerDance.h"

Player::Player(Keyboard* keyboard,Sound* sound, IGameStateChanger* statechanger,Collision* collision,float x, float y, float height, float width) : Object(x, y, height, width) {
	keyboard_ = keyboard;
	sound_ = sound; 
	state_changer_ = statechanger;
	collision_ = collision;
	graph_handle_ = LoadGraph("Image/Player_2.png");
	quality_ = true;
	playerhit_ = new PlayerHit(collision_,this);
	playeraction_[Player_MoveRight] = new PlayerMoveRight(sound_,collision_, this,playerhit_);
	playeraction_[Player_MoveLeft] = new PlayerMoveLeft(sound_, collision_, this, playerhit_);
	playeraction_[Player_Jump] = new PlayerJump(sound_, collision_, this, playerhit_);
	playeraction_[Player_Throw] = new PlayerThrow(sound_,this);
	playeraction_[Player_Pick] = new PlayerPick(sound_, collision_,this);
	playeraction_[Player_Put] = new PlayerPut(sound_,this);
	playeraction_[Player_Gravity] = new PlayerGravity(sound_, collision_, this, playerhit_);
	playeraction_[Player_Dance] = new PlayerDance(this);
}
//プレイヤーのボタン入力を管理
void Player::Action() {
	if (keyboard_->CheckKey(KEY_INPUT_RIGHT) != 0 && //右キーが押されており、
		keyboard_->CheckKey(KEY_INPUT_LEFT) == 0) { //左キーが押されていなかったら
		playeraction_[Player_MoveRight]->Do();//右に移動する
	}
	else if (keyboard_->CheckKey(KEY_INPUT_LEFT) != 0 && //左キーが押されており、
		keyboard_->CheckKey(KEY_INPUT_RIGHT) == 0) { //右キーが押されていなかったら
		playeraction_[Player_MoveLeft]->Do();//左に移動する
	}
	//上キーを入力されたとき
	if ((keyboard_->CheckKey(KEY_INPUT_UP) == 1 && player_state_ == Player_Land) ||//プレイヤーが地上にいるときか
		(keyboard_->CheckKey(KEY_INPUT_UP) > 1 && angle_ != 0)) {//上キーを入力し続けているとき
		playeraction_[Player_Jump]->Do();
	}
	else if (angle_ != 0) {//上キーの入力をしていないとき、またはジャンプ中に入力をやめたとき
		angle_ = 0;//angleを0に設定する
	}
	//Spaceキーを入力したとき
	if (keyboard_->CheckKey(KEY_INPUT_SPACE) == 1) { 
		////何かものを持っているなら
		if(carryon_ != nullptr)
			playeraction_[Player_Throw]->Do();//Throw動作を行う
		else
			playeraction_[Player_Pick]->Do();//Pick動作を行う
	}
	//下キーを入力したとき、何か持っていたなら
	if (keyboard_->CheckKey(KEY_INPUT_DOWN) == 1 && carryon_ != nullptr)
		playeraction_[Player_Put]->Do();//Put動作を行う
	if (keyboard_->CheckKey(KEY_INPUT_LCONTROL) == 1 || keyboard_->CheckKey(KEY_INPUT_RCONTROL) == 1)
		vector_ *= -1;//プレイヤーの向きを反転
}
void Player::Initialize() {
	carryon_ = nullptr;
	vector_ = 1;
	angle_ = 0;
	player_state_ = Player_Air;
}
void Player::Update() {
	switch (player_state_) {
	case Player_Clear:
		playeraction_[Player_Dance]->Do();
		break;
	default:
		Action();
		playeraction_[Player_Gravity]->Do();
		break;
	}
}
void Player::Draw() {
	if(vector_ ==1) DrawModiGraphF(x_, y_, x_ + width_, y_, x_ + width_, y_ + height_, x_, y_ + height_, graph_handle_, TRUE);
	else DrawModiGraphF(x_ + width_, y_, x_, y_, x_, y_ + height_, x_ + width_, y_ + height_, graph_handle_, TRUE);
}

//クリアしたときの処理
void Player::Clear() {
	player_state_ = Player_Clear;
	state_changer_->ChangeState(Game_Dance);
}
//リトライしたときの処理
void Player::Retry() {
	Object::Retry();
	player_state_ = Player_Air;
	carryon_ = nullptr;
	vector_ = 1;
}
//クリア出来るかを返す処理
//	引数:
//		true:クリア可能
//		false:クリアできない
bool Player::CanClear() {
	bool canclear_ = true;
	if (player_state_ == Game_Clear) {//すでにクリアしている場合
		canclear_ = false;
	}
	return canclear_;
}