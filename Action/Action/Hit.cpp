#include "Hit.h"

//Object������Object�ɐڐG�����ۂ̏���
Hit::Hit(Collision *collision) {
	map_left_ = collision->GetMapLeft(map_left_);
	map_right_ = collision->GetMapRight(map_right_);
}