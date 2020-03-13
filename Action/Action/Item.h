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
	Object *carrier;
	void Carry();
	void Hit(int check, Object *object);
	int MapCheck(float *point,float num);
	Object *mapLeft,* mapRight;
public:
	void Retry()override;
	bool CanPicked(Object *object)override;
	int Check(float *point, float num,Object *object);
	int Check(float x, float y, Object *object);
	void Initialize(Object **stage) override;
	void Set(float x, float y, float height, float width, int objNum)override;
	bool Move(float *pofloat, float num, Terrain *terrain); //移動を行い、移動できたかを返す
	void Move(float *pofloat, float num)override; //移動を行い、移動できたかを返す
	void Picked(Object *object)override;
	void Throw();
	void Update(Terrain *terrain);
	void Update();
	void Draw();
	void Putted()override;
	bool CanPutted()override;
	bool CanThrew()override;
	void Threw()override;
	void Initialize(IStateChanger *stateChanger, Object **stage)override;
};