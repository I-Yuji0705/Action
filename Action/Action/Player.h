#pragma once
#include "Object.h"
#include "Terrain.h"
#include "IStateChanger.h"
//キャラクターの状態状態
enum StateCharacter {
	State_Land,//地上にいる
	State_Air,//空中にいる
	State_Clear,
	State_Retry
};
class Player :public Object{
private:
	int kaku;
	StateCharacter playerState;
	bool isCarrier;//何かを持っているかを返す
	Object *carryon;//持っている物のアドレス
	int danceTimer,danceNum;//一つの動きに掛ける時間と、動きの数
	void Action();//プレイヤーの行動
	bool Check(Object *object);
	void Hit(int check, Object *object);
	void Pick();
	void Throw();
	void Put();
	void Dance();//クリア時の踊り
	void Push(Object *object);
	Object *mapLeft, *mapRight;
	int MapCheck(float *point, float num);
public :
	void Clear()override;
	bool CanPicked(Object *object)override;
	void Move(float *point, float num)override;//移動を行い、移動できたかを返す
	void Initialize(IStateChanger *stateChanger,Object **stage)override;
	void Initialize(IStateChanger *stateChanger);
	void RetryCheck();//リトライをする必要があるか(穴に落ちたか)を確認する
	void Retry()override;
	void Set(float x, float y, float height, float width, int objNum)override;
	void Update();
	void Draw()override;
	void Picked(Object *object)override;
	void Putted()override;
	bool CanPutted()override;
	int Check(float *point,float num,Object *object);
};