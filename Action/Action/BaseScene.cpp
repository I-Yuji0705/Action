#include "BaseScene.h"
#include "DxLib.h"
BaseScene::BaseScene(ISceneChanger* changer) :
	ImageHandle(0) {
	SceneChanger = changer;
}
void BaseScene::Finalize() {
	DeleteGraph(ImageHandle);
}

void BaseScene::Draw() {
}