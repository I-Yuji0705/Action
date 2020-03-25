#include "Terrain.h"
#include "DxLib.h"

///<summary>
///<para>コンストラクタ</para>
///<para>追加で接触判定の初期化を行う</para>
///</summary>
Terrain::Terrain(float x, float y, float height, float width) : Object(x ,y ,height ,width) {
	quality_ = true;//接触判定を適用する
}

///<summary>
///<para>描写処理</para>
///<para>地形の範囲を黒色で覆う</para>
///</summary>
void Terrain::Draw() {
	DrawBoxAA(x_, y_, x_ + width_,  y_ + height_,GetColor(0,0,0), TRUE);//Float型の四点の座標から外枠を描写
}