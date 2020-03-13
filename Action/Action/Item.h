#pragma once
#include "Object.h"
#include "Player.h"
#include "ItemAction.h"
#include "IMenuStateChanger.h"
enum ItemState {
	Item_Normal,//Itemの通常状態
	Item_Picked,//Itemが拾われている状態
	Item_Throw,//Itemが投げられている状態
};
enum ItemActionList {
	Item_Baggage,//持たれている
	Item_StartThrow,//投げられ始めた
	Item_Threw,//投げられている
	Item_Putted,//置かれた
	Item_Gravity//重力を受けている
};
class Collision;
class ItemAction;
//ステージ上でPlayerが持ち上げられるItemの基底クラス
class Item : public Object {
private:
public:
	Object *carrier_;
	Collision *collision_;
	ItemAction *itemaction_[5];//Itemの行動を行うクラス配列
	ItemState state_;
	Item(float x, float y, float height, float width,Sound* sound);
	void Initialize(IGameStateChanger *statechanger,Collision *collision)override;
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