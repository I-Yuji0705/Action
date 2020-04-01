#include "PlayerActionBaggage.h"
#include <tuple>
#include "DxLib.h"

///<summary>
///<para>コンストラクタ</para>
///<para>キーが押されているか確認するKeyboardクラス、拾う範囲に他のObjectがないか確認するクラス、行動時の音を管理するクラスを追加で取得する</para>
///<param name= "keyboard"><para>キーが押されているか確認するクラス</para></param>
///<param name= "sound"><para>動作時に音を発生させるクラス</para></param>
///<param name= "collision"><para>拾う範囲に他のObjectがないか確認するクラス</para></param>
///</summary>
PlayerActionBaggage::PlayerActionBaggage(Keyboard* keyboard, Sound* sound, Collision *collision, Player *player) : PlayerAction(player) {
	keyboard_ = keyboard;
	collision_ = collision;
	sound_ = sound;
}
///<summary>
///<para>行動処理</para>
///<para>押されたキーと、PlayerがObjectを持っているかどうかによって行動が変わる</para>
///<para>Spaceキーを押した時、PlayerがObjectを持っていた場合:Throw処理</para>
///<para>Spaceキーを押した時、PlayerがObjectを持っていない場合:Pick処理</para>
///<para>下キーを押したとき、PlayerがObjectを持っていた場合:Put処理</para>
///</summary>
void PlayerActionBaggage::Do() {
	if (keyboard_->CheckKey(KEY_INPUT_SPACE) == 1) {
		////何かものを持っているなら
		if (player_->carryon_ != nullptr)
			Throw();//Throw動作を行う
		else
			Pick();//Pick動作を行う
	}
	//下キーを入力したとき、何か持っていたなら
	else if (keyboard_->CheckKey(KEY_INPUT_DOWN) == 1 && player_->carryon_ != nullptr)
		Put();//Put動作を行う
}

///<summary>
///<para>拾う行動処理</para>
///<para>player_の位置と向きから拾う範囲を設定し、その範囲内にObjectがあった場合、そのObjectに対して拾えるかを確認する</para>
///<para>拾える場合、player_のcarryonの値をそのObjectに更新し、そのObjectに拾われた時の動作を行わせる</para>
///</summary>
void PlayerActionBaggage::Pick() {
	Object *goods = nullptr;
	const float krange = player_->GetWidth(); //Itemを拾える横幅
	float posx[2];//拾える範囲の左端と右端のX軸
	float posy[2];//拾える範囲の上端と下端のY軸
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
	goods = collision_->AreaCheck(goods, posx[0], posy[0], posx[1], posy[1], player_);
	if (goods != nullptr) {
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

///<summary>
///<para>投げる行動処理</para>
///<para>carryonに対して投げられるかを確認する</para>
///<para>投げられる場合、player_のcarryonの値をnullptrに更新し、そのObjectに投げられた時の動作を行わせる</para>
///</summary>
void PlayerActionBaggage::Throw() {
	if (player_->carryon_->CanThrew()) {
		player_->carryon_->Threw();
		player_->carryon_ = nullptr;
		sound_->PlaySe(Se_Throw, player_);
	}
	else {
		sound_->PlaySe(Se_Cant, player_);
	}
}
///<summary>
///<para>置く行動処理</para>
///<para>carryonに対して置けるかを確認する</para>
///<para>置ける場合、player_のcarryonの値をnullptrに更新し、そのObjectに置かれた時の動作を行わせる</para>
///</summary>
void PlayerActionBaggage::Put() {
	if (player_->carryon_->CanPutted()) {
		player_->carryon_->Putted();
		player_->carryon_ = nullptr;
		sound_->PlaySe(Se_Put, player_);
	}
	else {
		sound_->PlaySe(Se_Cant, player_);
	}
}