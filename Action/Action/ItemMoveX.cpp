#include "ItemMoveX.h"
#include <tuple>

///<summary>
///<para>コンストラクタ</para>
///<para>音を管理するクラスと接触を判定するクラス、接触後の処理を行うクラスのポインタを追加で収得する</para>
///<param name="sound"><para>sound:壁に接触した際に鳴らす音を管理するクラスのポインタ</para></param>
///<param name="collision"><para>collision:移動する先に衝突するObjectがあるかを調べるクラスのポインタ</para></param>
///<param name="itemhit"><para>itemhit:接触時に位置調整などの処理を行うクラスのポインタ</para></param>
///</summary>
ItemMoveX::ItemMoveX(Sound* sound, Collision *collision, Item *item,ItemHit* itemhit) : ItemAction(item) {
	sound_ = sound;
	collision_ = collision;
	itemhit_ = itemhit;
}

///<summary>
///<para>Y軸の移動処理</para>
///<para>移動しようとしている数字を受け取り、移動先に他のObjectに接触するかを調べる</para>
///<para>移動先にObjectない場合:xに数値を加算し、移動する</para>
///<para>移動先にObjectある場合:接触処理を行う</para>
///<param name="num"><para>num:X軸に加算しようとしている値</para></param>
///</summary>
void ItemMoveX::MoveX(float num) {
	bool hit = false;
	int hitpoint;
	float distance;
	std::vector<Object*> hitobjects;
	std::tie(hitpoint, distance, hitobjects) = collision_->HitCheckX(num, item_);//移動した際に当たるオブジェクトと当たる場所の算出
	if (hitpoint != 0 && !hitobjects.empty()) {//当たったObjectがあったか
		itemhit_->HitObjects(hitpoint, distance);//Hitした時のItemの位置を調整する
		if(distance != 0.0f)
			sound_->PlaySe(Se_Hit, item_);
		hit = true;
	}
	std::tie(hitpoint, distance) = collision_->MapCheck(item_->Left() + num, item_);
	if (hitpoint != 0) {//マップ外に移動してしまうか確認する処理
  		itemhit_->HitObjects(hitpoint, distance);
		hit = true;
		sound_->PlaySe(Se_Hit, item_);
	}
	if (!hit) {
		item_->x_ += num;
	}
}

///<summary>
///<para>行動処理</para>
///<para>item_の向きから移動先を決め、X軸の移動処理を行う</para>
///</summary>
void ItemMoveX::Do() {
	const float kThrowSpeed = 10.0f;
	MoveX(kThrowSpeed * item_->vector_);
}