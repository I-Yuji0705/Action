#pragma once
#include "Object.h"
#include "Player.h"
#include "ItemAction.h"

enum ItemState {
	Item_Normal,//Itemの通常状態
	Item_Picked,//Itemが拾われている状態
	Item_Throw,//Itemが投げられている状態
};
enum ItemActionList {
	Item_Baggage,//持たれている
	Item_StartThrow,//投げられ始めた
	Item_MoveX,//投げられている
	Item_Putted,//置かれた
	Item_MoveY,//重力を受けている

	Item_ActionNum
};
class Collision;
class ItemAction;
class ItemHit;

//ステージ上でPlayerが持ち上げられるItemの基底クラス
class Item : public Object {
private:
	Sound* sound_;
	Collision *collision_;
	ItemHit* itemhit_;
	ItemAction *itemaction_[Item_ActionNum];//Itemの行動を行うクラス配列
public:
	Item(Sound* sound,Collision* collision,float x, float y, float height, float width);
	ItemState state_;
	Object *carrier_;
	void Initialize()override;
	void Update()override;
	void Draw()override;
	float CanPushed(float num)override;
	void Pushed(float num)override;
	bool CanPicked(const Object *object)override;
	void Picked( Object *object)override;
	bool CanPutted()override;
	void Putted()override;
	bool CanThrew()override;
	void Threw()override;
	void Retry()override;
};