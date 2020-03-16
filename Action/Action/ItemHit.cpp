#include "ItemHit.h"
#include <assert.h>

///<summary>
///<para>コンストラクタ</para>
///<para>操作するitemのポインタを追加で受け取る</para>
///<para>引数:</para>
///<param name="item"><para>item:操作するitemのポインタ</para></param>
///</summary>
ItemHit::ItemHit(Collision *collision,Item* item) : Hit(collision){
	item_ = item;
}

///<summary>
///<para>接触処理</para>
///<para>item_のstateを変更した後、引数で受け取ったintの数値によってX軸かY軸に受け取ったfloatの数値分加算する</para>
///<para>引数:</para>
///<param name="check"><para>check:Collision::HitCheckXやCollision::HitCheckX、Collision::MapCheckの戻り値の一つであるint型の数値</para></param>
///<param name="distance"><para>distance:Collision::HitCheckXやCollision::HitCheckX、Collision::MapCheckの戻り値の一つであるfloat型の数値</para></param>
///</summary>
void ItemHit::HitObjects(int check,float distance) {
	item_->state_ = Item_Normal;
	switch (check) {
	case 1:
	case 2:
		item_->Set(item_->Left() + distance, item_->Top());
		break;
	case 3:
	case 4:
		item_->Set(item_->Left(), item_->Top() + distance);
		break;
	default:
		assert(false);
		break;
	}
}