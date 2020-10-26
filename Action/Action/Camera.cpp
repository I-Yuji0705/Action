#include "Camera.h"
#include "DxLib.h"
#include <typeinfo>


///<summary>
///<para>コンストラクタ</para>
///<para>描写するステージとCpllisionクラスのポインタの取得</para>
///<para>state:描写するステージのポインタ</para>
///<para>collision:プレイヤーとステージ右端、左端オブジェクトのポインタを貰う</para>
///</summary>
Camera::Camera(std::vector<Object*>* stage, Collision* collision) {
	stage_ = stage;
	collision_ = collision;
}

///<summary>
///<para>初期化処理</para>
///<para>ステージの右端、左端、画面の中央に描写するPlayerのポインタの取得</para>
///</summary>
void Camera::Initialize() {
	map_left_ = collision_->GetMapLeft(map_left_);
	map_right_ =  collision_->GetMapRight(map_right_);
	player_ = *collision_->GetPlayer().begin();//中心に描写するPlayerの設定
}

///<summary>
///<para>更新処理</para>
///<para>playerがステージ右端、左端にいる場合を除いて、画面の中央に描写するように全体を動かす</para>
///</summary>
void Camera::Update(){
	float distance = 0;//Playerと画面中央との差
	const float kWindowX = 640.0f;//画面の横幅
	if (player_->Center_X() != kWindowX / 2) {
		distance = (player_->Right() + player_->Left()) / 2 - kWindowX / 2;
	}	
	if (distance < 0 && map_left_->Left() < 0) {
		if (map_left_->Left() - distance > 0) distance = map_left_->Left();
		for (auto i : *stage_) {
			i->Set(i->Left() - distance,i->Top());//オブジェクトの再設置
		}
	}
	if (distance > 0 && map_right_->Right() > kWindowX) {
		if (map_right_->Right() - distance < kWindowX) distance = map_right_->Right() - kWindowX;
		for (auto i : *stage_) {
			i->Set(i->Left() - distance, i->Top());//オブジェクトの再設置
		}
	}
}