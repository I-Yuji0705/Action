#include "Terrain.h"
#include "DxLib.h"
//ObjectのSet処理に加え、object_numberによって描写する画像を変更する
Terrain::Terrain(float x, float y, float height, float width, int object_number) : Object(x ,y ,height ,width ,object_number ) {
	switch (this->object_number_) {
	case 0:
		//graph_handle_ = LoadGraph("Image/Terrain.png");
		quality_ = true;
		damegeflg_ = false;
		break;
	default:
		break;
	}
}
void Terrain::Draw() {
	DrawBoxAA(x_, y_, x_ + width_,  y_ + height_,GetColor(0,0,0), TRUE);//Float型の四点の座標から外枠を描写
	float distance = 5.0f;//地形の外側と内側の差
	//DrawBoxAA(x_ + distance, y_ + distance, x_ + width_ - distance, y_ + height_ - distance, GetColor(255,255,255), TRUE);//Float型の四点の座標とその差から内側を描写
}