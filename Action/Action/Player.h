#pragma once
#include "Object.h"
#include "Terrain.h"
#include "IStateChanger.h"
//キャラクターの状態状態
enum StateCharacter {
	Player_Land,//地上にいる
	Player_Air,//空中にいる
	Player_Clear,
	Player_Retry
};
class Player :public Object{
private:
	StateCharacter player_state_;
	Object *map_left_, *map_right_;
	Object *carryon_;//持っている物のアドレス
	bool is_carrier_;//何かを持っているかを返す
	int angle_;//ジャンプしている間の時間
	int dance_timer_,dance_num_;//一つの動きに掛ける時間と、動きの数
	void Action();//プレイヤーの行動
	void Push(float num,Object *object);
	void Pick();
	void Put();
	void Throw();
	bool Check(Object *object);
	int MapCheck(float num);
	void MapHit(int mapcheck);
	void RetryCheck();//リトライをする必要があるか(穴に落ちたか)を確認する
	void Dance();//クリア時の動きの処理
	void Hit(int check ,Object * object);
	void HitCarryon(int check, Object *object);
	void Jump();
public :
	Player(float x, float y, float height, float width, int object_number);
	void Initialize(IStateChanger *stateChanger,std::vector<Object*>& stage) override;
	void Update()override;
	void Draw()override;
	int CheckX(float num, const Object *object)override;
	int CheckY(float num, const Object *object)override;
	bool CanMoveX(float num)override;
	bool CanMoveY(float num)override;
	void MoveX(float num)override;//移動を行い、移動できたかを返す
	void MoveY(float num)override;
	bool CanPicked(const Object *object)override;
	void Picked(Object *object)override;
	void Clear()override;
	void Retry()override;
	bool CanClear()override;
};