#pragma once
#include "Object.h"
#include "Player.h"
enum ItemState {
	Item_Normal,
	Item_Picked,
	Item_Throw,

};
class Item : public Object {
private:
	ItemState state_;
	Object *map_left_,* map_right_;
	Object *carrier_;
	void Carry();
	void Throw();
	void Push(float num, Object * object);
	void Hit(int check, Object *object);
	int MapCheck(float num);
	void MapHit(int mapcheck);
public:
	Item(float x, float y, float height, float width, int object_number);
	void Initialize(IStateChanger *stateChanger,std::vector<Object*>& stage)override;
	void Update()override;
	void Draw()override;
	//int Check(float *point, float num,const Object *object)override;
	int CheckX(float num, const Object *object)override;
	int CheckY(float num, const Object *object)override;
	//bool CanMove(float * point, float num)override;
	bool CanMoveX(float num)override;
	bool CanMoveY(float num)override;
	//void Move(float *point, float num)override; //ˆÚ“®‚ğs‚¤
	void MoveX(float num)override; //ˆÚ“®‚ğs‚¤
	void MoveY(float num)override; //ˆÚ“®‚ğs‚¤
	bool CanPicked(const Object *object)override;
	void Picked( Object *object)override;
	bool CanPutted()override;
	void Putted()override;
	bool CanThrew()override;
	void Threw()override;
	void Retry()override;
};