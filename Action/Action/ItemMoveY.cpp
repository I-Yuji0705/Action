#include "ItemMoveY.h"
#include <tuple>

///<summary>
///<para>コンストラクタ</para>
///<para>音を管理するクラスと接触を判定するクラス、接触後の処理を行うクラスのポインタを追加で収得する</para>
///<param name="sound"><para>sound:壁に接触した際に鳴らす音を管理するクラスのポインタ</para></param>
///<param name="collision"><para>collision:移動する先に衝突するObjectがあるかを調べるクラスのポインタ</para></param>
///<param name="sound"><para>itemhit:接触時に位置調整などの処理を行うクラスのポインタ</para></param>
///</summary>
ItemMoveY::ItemMoveY(Sound* sound, Collision *collision, Item *item, ItemHit* itemhit) : ItemAction(item) {
	sound_ = sound;
	collision_ = collision;
	itemhit_ = itemhit;
}


///<summary>
///<para>Y軸の移動処理</para>
///<para>移動しようとしている数字を受け取り、移動先に他のObjectに接触するかを調べる</para>
///<para>移動先にObjectない場合:y_に数値を加算し、移動する</para>
///<para>移動先にObjectある場合:接触処理を行う</para>
///<param name="num"><para>num:Y軸に加算しようとしている値</para></param>
///</summary>
void ItemMoveY::MoveY(float num) {
	bool hit = false;
	int hitpoint;
	float distance;
	std::vector<Object*> hitobject;
	std::tie(hitpoint, distance, hitobject) = collision_->HitCheckY(num, item_);
	if (hitpoint != 0  &&!hitobject.empty()) {
		itemhit_->HitObjects(hitpoint, distance);
		hit = true;
	}
	if (!hit) {
		item_->Set(item_->Left(), item_->Top() + num);
	}
}

///<summary>
///<para>行動処理</para>
///<para>重力分、Y軸の移動処理を行う</para>
///</summary>
void ItemMoveY::Do() {
	MoveY(gravity_.kGravity);
}