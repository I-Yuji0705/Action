#include "Terrain.h"
#include "DxLib.h"
void Terrain::Set(float x, float y, float height, float width, int objNum) {
	Object::Set(x, y, height, width, objNum);
	switch (this->objNum) {
	case 0:
		graphHandle = LoadGraph("Image/Terrain.png");
		quality = true;
		damegeflg = false;
		break;
	default:
		break;
	}
}