#include "Hit.h"

///<summary>
///<para>コンストラクタ</para>
///<para>ステージの両端の地形を収得する</para>
///</summary>
Hit::Hit(Collision *collision) {
	map_left_ = collision->GetMapLeft(map_left_);
	map_right_ = collision->GetMapRight(map_right_);
}