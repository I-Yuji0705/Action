#include "Player.h"
#include "DxLib.h"
#include "Keyboard.h"
#include "PlayerActionBaggage.h"
#include "PlayerDance.h"
#include "PlayerMoveX.h"
#include "PlayerMoveY.h"
#include "PlayerInversion.h"

///<summary>
///<para>コンストラクタ</para>
///<para>描写する画像の設定、当たった後の処理を行うクラス、行動を管理するクラスの生成</para>
///<para>引数:</para>
///<param name= "sound"><para>動作時に音を発生させるクラス</para></param>
///<param name= "collision"><para>動作時や動作確認時に接触判定を調べる</para></param>
///</summary>
Player::Player(Keyboard* keyboard,Sound* sound, IGameStateChanger* statechanger,Collision* collision,float x, float y, float height, float width) : Object(x, y, height, width) {
	sound_ = sound; 
	state_changer_ = statechanger;
	collision_ = collision;
	graph_handle_ = LoadGraph("Image/Player_2.png");
	quality_ = true;
	playerhit_ = new PlayerHit(collision_,this);
	playeraction_[Player_MoveX] = new PlayerMoveX(keyboard, sound_, collision_, this, playerhit_);//左右に移動する
	playeraction_[Player_MoveY] = new PlayerMoveY(keyboard, sound_, collision_, this, playerhit_);//上下に移動する
	playeraction_[Player_Baggage] = new PlayerActionBaggage(keyboard, sound_, collision_, this);//Itemに対してのアクション
	playeraction_[Player_Inversion] = new PlayerInversion(keyboard, this);//向き反転
	playeraction_[Player_Dance] = new PlayerDance(this);
}

///<summary>
///<para>プレイヤーのアクションの管理</para>
///<para>プレイヤーのキー入力とそれに対応するPlayerActionを行う</para>
///</summary>
void Player::Action() {
	for (int i = 0; i != Player_Dance; i++) {
		playeraction_[i]->Do();
	}
	//playeraction_[Player_MoveY]->Do();//上下に移動する
	//playeraction_[Player_Baggage]->Do();//Itemに対してのアクション
	//playeraction_[Player_Inversion]->Do();//向き反転
}

///<summary>
///<para>初期化処理</para>
///</summary>
void Player::Initialize() {
	carryon_ = nullptr;
	vector_ = 1;
	angle_ = 0;
	player_state_ = Player_Air;
}

///<summary>
///<para>更新処理</para>
///<para>Playerのstateがクリア状態の時のみ、Dance処理を行う</para>
///</summary>
void Player::Update() {
	switch (player_state_) {
	case Player_Clear:
		playeraction_[Player_Dance]->Do();
		break;
	default:
		Action();
		break;
	}
}

///<summary>
///<para>描写処理</para>
///<para>Playerの向きによって、描写する画像を反転する</para>
///</summary>
void Player::Draw() {
	if(vector_ ==1) DrawModiGraphF(x_, y_, x_ + width_, y_, x_ + width_, y_ + height_, x_, y_ + height_, graph_handle_, TRUE);
	else DrawModiGraphF(x_ + width_, y_, x_, y_, x_, y_ + height_, x_ + width_, y_ + height_, graph_handle_, TRUE);
}

///<summary>
///<para>クリア処理</para>
///<para>クリア条件を満たした際に、一度だけ呼ばれる関数</para>
///</summary>
void Player::Clear() {
	player_state_ = Player_Clear;
	state_changer_->ChangeState(Game_Dance);
}

///<summary>
///<para>リトライ処理</para>
///<para>Objectのリトライ処理に加え、初期化を行う</para>
///</summary>
void Player::Retry() {
	Object::Retry();
	Initialize();
}

///<summary>
///<para>今クリアできるかを返す</para>
///<returns>
///<para>true:自分投げることができる</para>
///<para>false:自分を投げることができない</para>
///</returns>
///</summary>
bool Player::CanClear() {
	bool canclear_ = true;
	if (player_state_ == Game_Clear) {//すでにクリアしている場合
		canclear_ = false;
	}
	return canclear_;
}