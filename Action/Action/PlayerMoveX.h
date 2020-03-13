#pragma once
#include "PlayerAction.h"
#include <vector>
//PlayerのX軸の移動を担当する抽象クラス
class PlayerMoveX : public PlayerAction {
protected:
	const float kMoveSpeed = 5.0f;//Playerの横移動の速度
	void MoveX(float num);//Playerの移動
	bool Push(float num,std::vector<Object*> target);//移動先のObjectを押し出し、押し出せたかを返す
private:
	bool firsthit_;//接触し始めたかを確認する変数
public:
	PlayerMoveX(Collision *collision, Player *playe, Sound* sound);
	//virtual void Do()override = 0;
};