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

Player::Player(float x, float y, float height, float width,Sound* sound) : Object(x, y, height, width,sound) {
	graph_handle_ = LoadGraph("Image/Player_2.png");
	quality_ = true;
	vector_ = 1;
	angle_ = 0;
	player_state_ = Player_Air;
}
//プレイヤーのボタン入力を管理
void Player::Action() {
	//const float kSpeed = 5.0f;
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RIGHT) != 0 && //右キーが押されており、
		Keyboard::getInstance()->CheckKey(KEY_INPUT_LEFT) == 0) { //左キーが押されていなかったら
		playeraction_[Player_MoveRight]->Do();//右に移動する
	}
	else if (Keyboard::getInstance()->CheckKey(KEY_INPUT_LEFT) != 0 && //左キーが押されており、
		Keyboard::getInstance()->CheckKey(KEY_INPUT_RIGHT) == 0) { //右キーが押されていなかったら
		playeraction_[Player_MoveLeft]->Do();//左に移動する
	}
	//上キーを入力されたとき
	if ((Keyboard::getInstance()->CheckKey(KEY_INPUT_UP) == 1 && player_state_ == Player_Land) ||//プレイヤーが地上にいるときか
		(Keyboard::getInstance()->CheckKey(KEY_INPUT_UP) > 1 && angle_ != 0)) {//上キーを入力し続けているとき
		playeraction_[Player_Jump]->Do();
	}
	else if (angle_ != 0) {//上キーの入力をしていないとき、またはジャンプ中に入力をやめたとき
		angle_ = 0;//angleを0に設定する
	}
	//Spaceキーを入力したとき
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_SPACE) == 1) { 
		////何かものを持っているなら
		if(carryon_ != nullptr)
			playeraction_[Player_Throw]->Do();//Throw動作を行う
		else
			playeraction_[Player_Pick]->Do();//Pick動作を行う
	}
	//下キーを入力したとき、何か持っていたなら
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_DOWN) == 1 && carryon_ != nullptr)
		playeraction_[Player_Put]->Do();//Put動作を行う
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_LCONTROL) == 1 || Keyboard::getInstance()->CheckKey(KEY_INPUT_RCONTROL) == 1)
		vector_ *= -1;//プレイヤーの向きを反転
}

void Player::Initialize(IGameStateChanger *statechanger, Collision *collision) {
	Object::Initialize(statechanger, collision);
	this->collision_ = collision; 
	carryon_ = nullptr;
	playeraction_[Player_MoveRight] = new PlayerMoveRight(collision_, this, sound_);
	playeraction_[Player_MoveLeft] = new PlayerMoveLeft(collision_, this, sound_);
	playeraction_[Player_Jump] = new PlayerJump(collision_, this, sound_);
	playeraction_[Player_Throw] = new PlayerThrow(collision_, this, sound_);
	playeraction_[Player_Pick] = new PlayerPick(collision_, this, sound_);
	playeraction_[Player_Put] = new PlayerPut(collision_, this, sound_);
	playeraction_[Player_Gravity] = new PlayerGravity(collision_, this, sound_);
	playeraction_[Player_Dance] = new PlayerDance(collision_, this, sound_);
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