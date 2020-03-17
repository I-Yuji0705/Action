#include "PlayerInversion.h"
#include "DxLib.h"

///<summary>
///<para>コンストラクタ</para>
///<para>追加でキーが押されているか確認するKeyboardクラスを取得する</para>
///</summary>
PlayerInversion::PlayerInversion(Keyboard* keyboard,Player *player) : PlayerAction(player) {
	keyboard_ = keyboard;
}

///<para>行動処理</para>
///<para>Ctrlキーを押した場合、プレイヤーの向きを変える</para>
///</summary>
void PlayerInversion::Do() {
	if (keyboard_->CheckKey(KEY_INPUT_LCONTROL) == 1 || keyboard_->CheckKey(KEY_INPUT_RCONTROL) == 1)
		player_->vector_ *= -1;//プレイヤーの向きを反転
}