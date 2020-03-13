#include "Camera.h"
#include "DxLib.h"
#include <typeinfo.h>

//----------------------------------------------------
//Cameraの初期化処理を行う場所
//ステージ右端、左端のTerrain、そしてPlayerを収得する
//	引数:
//		stage:ステージ上にあるobjectのvector配列
//		collision:プレイヤーとステージ右端、左端の
//					  オブジェクトのポインタを渡す
void Camera::Initialize(std::vector<Object*> stage,Collision* colllision) {
	stage_ = stage;
	map_left_ = colllision->GetMapLeft(map_left_);
	map_right_ =  colllision->GetMapRight(map_right_);
	player_ = *colllision->GetPlayer().begin();//中心に描写するPlayerの設定
}
//----------------------------------------------------
//Cameraの更新処理
//Playerがステージ右端、左端にいる場合を除いて、画面の中央に描写するように全体を動かす
void Camera::Update(){
	float distance = 0;//Playerと画面中央との差
	const float kWindowX = 640.0f;//画面の横幅
	if (player_->Center_X() != kWindowX / 2) {
		distance = (player_->Right() + player_->Left()) / 2 - kWindowX / 2;
	}	
	if (distance < 0 && map_left_->Left() < 0) {
		if (map_left_->Left() - distance > 0) distance = map_left_->Left();
		for (auto i : stage_) {
			i->Set(i->Left() - distance,i->Top());//オブジェクトの再設置
		}
	}
	if (distance > 0 && map_right_->Right() > kWindowX) {
		if (map_right_->Right() - distance < kWindowX) distance = map_right_->Right() - kWindowX;
		for (auto i : stage_) {
			i->Set(i->Left() - distance, i->Top());//オブジェクトの再設置
		}
	}
}