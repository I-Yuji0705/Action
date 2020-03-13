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
	StateCharacter playerState;
	Object *mapLeft, *mapRight;
	Object *carryon;//持っている物のアドレス
	bool isCarrier;//何かを持っているかを返す
	int angle;//ジャンプしている間の時間
	int danceTimer,danceNum;//一つの動きに掛ける時間と、動きの数
	void Action();//プレイヤーの行動
	void Push(float num,Object *object);
	void Pick();
	void Put();
	void Throw();
	bool Check(Object *object);
	void Hit(int check, Object *object);
	int MapCheck(float *point, float num);
	void RetryCheck();//リトライをする必要があるか(穴に落ちたか)を確認する
	void Dance();//クリア時の動きの処理
public :
	void Set(float x, float y, float height, float width, int objNum)override;
	void Initialize(IStateChanger *stateChanger,Object *stage[])override;
	void Update()override;
	void Draw()override;
	int Check(float *point, float num, Object *object)override;
	bool CanMove(float *point, float num)override;
	void Move(float *point, float num)override;//移動を行い、移動できたかを返す
	bool CanPicked(Object *object)override;
	void Picked(Object *object)override;
	void Clear()override;
	void Retry()override;
};