#include "ClearArea.h"
#include <typeinfo.h>
#include "DxLib.h"

ClearArea::ClearArea(float x, float y, float height, float width,Sound* sound) : Object(x, y, height, width,sound) {
	quality_ = false;//当たり判定をなくす
}

void ClearArea::Initialize(IGameStateChanger *stateChanger, Collision *collision) {
	Object::Initialize(stateChanger, collision);
	collision_ = collision;
	players_ = collision_->GetPlayer();
	clearstart_ = true;
}
void ClearArea::Update() {
	if (collision_->AreaFullCheck(this) ) {
		bool canclear = true;
		for (auto i : players_) {
			if (!i->CanClear()) {
				canclear = false;
				break;
			}
		}
		if (canclear) {
			for (auto i : players_) {
				i->Clear();
			}
		sound_->StopBgm();//クリア時の音楽を鳴らすため、bgmを止める
		sound_->PlaySe(Se_Clear);
		}
	}
}
void ClearArea::Draw() {
	DrawBoxAA(x_, y_, x_ + width_, y_ + height_, GetColor(60, 128, 106), TRUE);//Float型の四点の座標から外枠を描写
}