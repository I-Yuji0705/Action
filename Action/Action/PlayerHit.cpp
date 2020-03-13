#include "PlayerHit.h"
#include <assert.h>
PlayerHit::PlayerHit(Collision* collision,Player* player) : Hit(collision) {
	player_ = player;
	collision->GetMapLeft(map_left_);
	collision->GetMapRight(map_right_);
}

//----------
//PlayerがObjectに当たった際の位置の調整とPlayerの状態を変更する
//引数：
//		check:int Check(float *point, float num,const Object *object)の返り値から、オブジェクトのどこに当たったかを求める
//		object:当ったオブジェクト
void PlayerHit::HitProcess(int hitcheck, Object* hitobject) {
	int hitangle = 60;
	switch (hitcheck) {
	case 1:
		player_->x_ = hitobject->Left() - player_->GetWidth();
		break;
	case 2:
		player_->x_ = hitobject->Right();
		break;
	case 3:
		player_->y_ = hitobject->Top() - player_->GetHeight();
		player_->player_state_ = Player_Land;
		break;
	case 4:
		player_->angle_ = hitangle;
		player_->y_ = hitobject->Base();
		break;
	default:
		assert(false);
		break;
	}
}

////----------
////Carryon(Playerが持っているItem)がObjectに当たった際の位置の調整とPlayerの状態を変更する
////引数：
////		check:int Check(float *point, float num,const Object *object)の返り値から、オブジェクトのどこに当たったかを求める
////		object:当ったオブジェクト
void PlayerHit::HitProcess(int hitcheck, Object* hitobject, Object* carryon) {
	int hitangle = 60;
	if (carryon == nullptr)
		HitProcess(hitcheck, hitobject);
	else {
		switch (hitcheck) {
		case 1:
			carryon->x_ = hitobject->Left() - carryon->width_;
			player_->x_ = carryon->Center_X() - player_->GetWidth() / 2;
			break;
		case 2:
			carryon->x_ = hitobject->Right();
			player_->x_ = carryon->Center_X() - player_->GetWidth() / 2;
			break;
		case 3:
			carryon->y_ = hitobject->Top() - carryon->GetHeight();
			player_->y_ = carryon->Base();
			player_->player_state_ = Player_Land;
			break;
		case 4:
			player_->angle_ = hitangle;
			carryon->y_ = hitobject->Base();
			player_->y_ = carryon->Base();
			break;
		default:
			assert(false);
			break;
		}
	}
}
void PlayerHit::MapHit(int mapcheck) {
	switch (mapcheck) {
	case 1:
		player_->x_ = map_right_->Right() - player_->width_;
		break;
	case 2:
		player_->x_ = map_left_->Left();
		break;
	default:
		assert(false);
		break;
	}
}