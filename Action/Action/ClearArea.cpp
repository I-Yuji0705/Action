#include "ClearArea.h"
#include <typeinfo>
#include "DxLib.h"

///<summary>
///<para>コンストラクタ</para>
///<param name="sound"><para>sound:クリア時の音楽を鳴らすクラスのポインタ</para></param>
///<param name="collision"><para>collision:クリア判定を行うクラスのポインタ</para></param>
///<param name="color"><para>color:ステージ背景のカラーコード</para></param>
///</summary>
ClearArea::ClearArea(Sound* sound,Collision* collision,ColorCode color,float x, float y, float height, float width) : Object(x, y, height, width) {
	sound_ = sound; 
	collision_ = collision;
	color_ = GetColor(color.Red / 2, color.Green / 2, color.Blue / 2);
	quality_ = false;//当たり判定をなくす
}

///<summary>
///<para>初期化処理</para>
///<para>プレイヤーのポインタの取得</para>
///</summary>
void ClearArea::Initialize() {
	players_ = collision_->GetPlayer();
}

///<summary>
///<para>更新処理</para>
///<para>このObject内が他のObjectで満たされているかを確認する</para>
///<para>満たされている場合、音楽を鳴らし、playerにクリア時の処理を行わせる</para>
///</summary>
void ClearArea::Update() {
	if (collision_->AreaFullCheck(this) ) {
		bool canclear = true;
		for (auto i : players_) {
			if (!i->CanClear()) {
				canclear = false;
				break;
			}
		}
		if (canclear) {
			for (auto i : players_) {
				i->Clear();
			}
		sound_->StopBgm();//クリア時の音楽を鳴らすため、bgmを止める
		sound_->PlaySe(Se_Name::Se_Clear);
		}
	}
}

///<summary>
///<para>描写処理</para>
///<para>このObject内が他のObjectで満たされているかを確認する</para>
///<para>満たされている場合、音楽を鳴らし、playerにクリア時の処理を行わせる</para>
///</summary>
void ClearArea::Draw() {
	DrawBoxAA(x_, y_, x_ + width_, y_ + height_,color_, TRUE);//Float型の四点の座標から外枠を描写
}