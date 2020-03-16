#include "Item.h"
#include "Terrain.h"
#include <typeinfo.h>
#include <assert.h>
#include <tuple>
#include "DxLib.h"
#include "ItemBaggage.h"
#include "ItemGravity.h"
#include "ItemPutted.h"
#include "ItemThrew.h"
#include "ItemStartThrow.h"

///<summary>
///<para>コンストラクタ</para>
///<para>描写する画像の設定、当たった後の処理を行うクラス、行動を管理するクラスの生成</para>
///<para>引数:</para>
///<param name= "sound"><para>動作時に音を発生させるクラス</para></param>
///<param name= "collision"><para>動作時や動作確認時に接触判定を調べる</para></param>
///</summary>
Item::Item(Sound* sound,Collision* collision,float x, float y, float height, float width) : Object(x, y, height, width) {
	sound_ = sound;
	collision_ = collision;
	graph_handle_ = LoadGraph("Image/Item.png");
	quality_ = true;
	itemhit_ = new ItemHit(collision_,this);
	itemaction_[Item_Baggage] = new ItemBaggage(this);
	itemaction_[Item_StartThrow] = new ItemStartThrow(this);
	itemaction_[Item_Threw] = new ItemThrew(sound_, collision_, this,itemhit_);
	itemaction_[Item_Putted] = new ItemPutted(this);
	itemaction_[Item_Gravity] = new ItemGravity(sound_, collision_, this,itemhit_);
}

///<summary>
///<para>初期化処理</para>
///<para>自分を持っているPlayerのポインタをnullptrにする</para>
///</summary>
void Item::Initialize() {
	vector_ = 1;
	state_ = Item_Normal;
	carrier_ = nullptr;
}

///<summary>
///<para>更新処理</para>
///<para>Itemの状態によってで行う行動を変える</para>
///</summary>
void Item::Update() {
	switch (state_) {
	case Item_Normal:
		itemaction_[Item_Gravity]->Do();
		break;
	case Item_Picked:
		itemaction_[Item_Baggage]->Do();
		break;
	case Item_Throw:
		itemaction_[Item_Threw]->Do();
		break;
	default:
		assert(false);
		break;
	}
}

///<summary>
///<para>描写処理</para>
///<para>Itemの向きによって、描写する画像を反転する</para>
///</summary>
void Item::Draw() {
	if (vector_ == 1) DrawModiGraphF(x_, y_, x_ + width_, y_, x_ + width_, y_ + height_, x_, y_ + height_, graph_handle_, TRUE);
	else DrawModiGraphF(x_ + width_, y_, x_, y_, x_, y_ + height_, x_ + width_, y_ + height_, graph_handle_, TRUE);
}

///<summary>
///<para>Objectに持たれるかを返す</para>
///<para>Objectの頭上に自身を置くことができるかを調べ、返す</para>
///<para>引数:</para>
///<param name="object"><para>object:自分を持つObject</para></param>
///<para>戻り値:</para>
///<returns>
///<para>true:自分を持つことができる</para>
///<para>false:自分を持つことができない</para>
///</returns>
///</summary>
bool Item::CanPicked(const Object *object) {
	bool canpicked = true;
	if (collision_->Check(object->Center_X() - GetWidth() / 2, object->Top() - GetHeight(), this)) {
		canpicked = false;
	}
	return canpicked;
}

///<summary>
///<para>Objectに持たれた始める際の処理</para>
///<para>自分のstateを変更し、持たれる対象をポインタに保存し、自分の位置を変更する</para>
///<para>引数:</para>
///<param name="object"><para>object:自分を持つObject</para></param>
///</summary>
void Item::Picked(Object *object) {
	state_ = Item_Picked;
	carrier_ = object;
	itemaction_[Item_Baggage]->Do();
}

///<summary>
///<para>carrier_に置かれることができるかを返す</para>
///<para>Objectの頭上に自身を置くことができるかを調べ、返す</para>
///<para>戻り値:</para>
///<returns>
///<para>true:自分を持つことができる</para>
///<para>false:自分を持つことができない</para>
///</returns>
///</summary>
bool Item::CanPutted() {
	bool canputted = true;
	if (state_ != Item_Picked) {
		canputted = false;
	}
	else {
		float posx;
		float posy = carrier_->Base() - GetHeight();
		if (vector_ == 1) {
			posx = carrier_->Right();
		}
		else {
			posx = carrier_->Left() - GetWidth();
		}
		int mapcheck;
		float distance;
		std::tie(mapcheck, distance) = collision_->MapCheck(posx, this);
		if (collision_->Check(posx, posy, this) || mapcheck != 0) {
			canputted = false;
		}
	}
	return canputted;
}

///<summary>
///<para>Objectに持たれた始める際の処理</para>
///<para>stateと持たれる対象をポインタに保存し、自分の位置を変更する</para>
///<para>引数:</para>
///<param name="object"><para>object:自分を持つObject</para></param>
///</summary>
void Item::Putted() {
	itemaction_[Item_Putted]->Do();
}

///<summary>
///<para>carrier_に投げられる際、投げれるかを返す</para>
///<para>Itemのvector_から投げる際に自分がいる位置に他のObjectがないか調べる</para>
///<para>戻り値:</para>
///<returns>
///<para>true:自分投げることができる</para>
///<para>false:自分を投げることができない</para>
///</returns>
///</summary>
bool Item::CanThrew() {
	bool canthrew = true;
	if (state_ != Item_Picked) {
		canthrew = false;
	}
	else {
		float posx;
		float posy = carrier_->Base() - GetHeight();
		if (vector_ == 1) {
			posx = carrier_->Right();
		}
		else {
			posx = carrier_->Left() - GetWidth();
		}
		int mapcheck;
		float distance;
		std::tie(mapcheck, distance) = collision_->MapCheck(posx, this);
		if (collision_->Check(posx, posy, this) || mapcheck != 0) {
			canthrew = false;
		}
	}
	return canthrew;
}

///<summary>
///<para>投げられる際の処理</para>
///<para>自分の位置を変更する</para>
///</summary>
void Item::Threw() {
	itemaction_[Item_StartThrow]->Do();
}

///<summary>
///<para>リトライ処理</para>
///<para>自分の位置を最初の位置に戻し、初期化処理を行う</para>
///</summary>
void Item::Retry() {
	Object::Retry();
	Initialize();
}

///<summary>
///<para>押されようとしている数字から、自分が押されることのできる数字を返す</para>
///<para>ステージ端に移動してしまう場合、その差の数字を返す</para>
///<para>自分が押される分数字を半分にした後、移動先にObjectがあった場合そのObjectのCapushedを再帰させ、一番小さい数字を返す</para>
///<para>引数:</para>
///<param name="num"><para>num:現在の位置から動かそうとしている座標への差</para></param>
///<para>戻り値:</para>
///<returns>
///<para>numに対して、実際にこのObjectを動かせる距離</para>
///</returns>
///</summary>
float Item::CanPushed(float num) {
	float canpushed = num / 2;
	int hitpoint;
	float distance;
	std::vector<Object*> hitobject;
	std::tie(hitpoint, distance) = collision_->MapCheck(Left() + num / 2, this);
	if (hitpoint != 0) {
		canpushed = distance;
	}
	else {
		std::tie(hitpoint, distance, hitobject) = collision_->HitCheckX(num / 2, this);
		if (hitpoint != 0 ){
			if (distance != 0.0f) {
				canpushed = distance;
			}else if(!hitobject.empty()) {
				for (auto i : hitobject) {
					if (std::abs(canpushed) > std::abs(i->CanPushed(num / 2))) {
						canpushed = i->CanPushed(num / 2);
					}
				}
			}
		}
	}
	return canpushed;
}

///<summary>
///<para>引数で受け取った数字分座標を移動する</para>
///<para>移動先に他のObjectがあった場合、そのObjectもPushedを使い、再帰させる</para>
///<para>引数:</para>
///<param name="num"><para>num:現在の位置から動かそうとしている座標への差</para></param>
///</summary>
void Item::Pushed(float num) {
	int hitpoint;
	float distance;
	std::vector<Object*> hitobject;
	std::tie(hitpoint, distance, hitobject) = collision_->HitCheckX(num, this);
	if (hitpoint != 0 && !hitobject.empty()) {
		for (auto i : hitobject) {
			i->Pushed(num);
		}
	}
	Set(Left() + num, Top());
}
