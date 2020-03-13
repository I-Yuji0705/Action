#pragma once
#include "Object.h"
#include "Player.h"
enum ItemState {
	State_Normal,
	State_Picked,
	State_Throw,

};
class Item : public Object {
private:
	ItemState state;
	Object *mapLeft,* mapRight;
	Object *carrier;
	void Carry();
	void Throw();
	void Push(float num, Object * object);
	void Hit(int check, Object *object);
	int MapCheck(float *point,float num);
public:
	void Set(float x, float y, float height, float width, int objNum)override;
	void Initialize(IStateChanger *stateChanger, Object *stage[])override;
	void Update()override;
	void Draw()override;
	int Check(float *point, float num,Object *object)override;
	bool CanMove(float * point, float num)override;
	void Move(float *point, float num)override; //à⁄ìÆÇçsÇ§
	bool CanPicked(Object *object)override;
	void Picked(Object *object)override;
	bool CanPutted()override;
	void Putted()override;
	bool CanThrew()override;
	void Threw()override;
	void Retry()override;
};