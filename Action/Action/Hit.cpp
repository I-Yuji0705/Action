#include "Hit.h"
#include <cassert>
//Object������Object�ɐڐG�����ۂ̏���
Hit::Hit(Collision *collision) {
	map_left_ = collision->GetMapLeft(map_left_);
	map_right_ = collision->GetMapRight(map_right_);
}

//item*,player*������Object*
//void Hit::HitObjects(int check, float distance) {
//	switch (check) {
//	case 1:
//	case 2:
//
//	}
//}