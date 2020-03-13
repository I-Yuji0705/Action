#include "Terrain.h"
#include "DxLib.h"

Terrain::Terrain(float x, float y, float height, float width,Sound* sound) : Object(x ,y ,height ,width,sound) {
	quality_ = true;//地形の接触判定を適用する
}
//描写処理
void Terrain::Draw() {
	DrawBoxAA(x_, y_, x_ + width_,  y_ + height_,GetColor(0,0,0), TRUE);//Float型の四点の座標から外枠を描写
}
//-------
//初期化処理
//何も行わない
void Terrain::Initialize(IGameStateChanger *stateChanger, Collision *collision) {
}