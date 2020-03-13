#include "Terrain.h"
#include "DxLib.h"
int Terrain::terrain_num = 0;
void Terrain::Set(float x, float y, float height, float width, int objNum) {
	Object::Set(x, y, height, width, objNum);
	switch (this->objNum) {
	case 0:
		graphHandle = LoadGraph("Image/Terrain.png");
		quality = true;
		damegeflg = false;
		break;
	case 1:
		graphHandle = LoadGraph("Image/warpstar.bmp");
		quality = false;
		damegeflg = false;
		break;
	default:
		break;
	}
	terrain_num++;
}
void Terrain::Update() {

}