#pragma once
#include "Object.h"
#include "Terrain.h"
#include "Collision.h"
#include "PlayerAction.h"
//キャラクターの状態状態
enum StateCharacter {
	Player_Land,//地上にいる
	Player_Air,//空中にいる
	Player_Clear,//クリアした
};
enum PlayerActionList {
	Player_MoveRight,//右移動
	Player_MoveLeft,//左移動
	Player_Jump,//ジャンプ
	Player_Throw,//投げる
	Player_Pick,//拾う
	Player_Put,//置く
	Player_Gravity,//重力を受ける
	Player_Dance//踊る
};
class Collision;
class PlayerAction;

//ステージ上のプレイヤーの基底クラス
class Player : public Object{
private:
	Collision *collision_;
	PlayerAction *playeraction_[8];
	void Action();//キーの状態からプレイヤーの行動を行う
public :
	StateCharacter player_state_;
	int angle_;//ジャンプしている時間及びJump時の移動距離
	Object *carryon_;//持っている物のアドレス
	Player(float x, float y, float height, float width,Sound* sound);
	void Initialize(IGameStateChanger *statechanger, Collision *collision);
	void Update()override;
	void Draw()override;
	void Clear()override;
	void Retry()override;
	bool CanClear()override;
};