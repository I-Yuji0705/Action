#pragma once
#include "PlayerAction.h"
#include <vector>
#include "Keyboard.h"
#include "PlayerHit.h"

class Keyboard;
class Collison;
class Sound;
class PlayerHit;

//PlayerのX軸の移動を担当する抽象クラス
class PlayerMoveX : public PlayerAction {
protected:
	Keyboard *keyboard_;
	Collision* collision_;//アクション時の物理判定を計測する場所
	Sound* sound_;//アクション時に鳴らす音
	PlayerHit* playerhit_;
	const float kMoveSpeed = 5.0f;//Playerの横移動の速度
	void MoveX(float num);//Playerの移動
	bool Push(float num, std::vector<Object*> target, int check);//移動先のObjectを押し出し、押し出せたかを返す
private:
	bool firsthit_;//接触し始めたかを確認する変数
public:
	PlayerMoveX(Keyboard* keyboard,Sound* sound, Collision *collision, Player *player,PlayerHit* hit);
	void Do() override;
};