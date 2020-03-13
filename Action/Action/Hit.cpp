#include "Hit.h"

//Object‚ª‘¼‚ÌObject‚ÉÚG‚µ‚½Û‚Ìˆ—
Hit::Hit(Collision *collision) {
	map_left_ = collision->GetMapLeft(map_left_);
	map_right_ = collision->GetMapRight(map_right_);
}