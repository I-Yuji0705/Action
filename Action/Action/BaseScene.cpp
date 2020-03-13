#include "BaseScene.h"
#include "DxLib.h"
BaseScene::BaseScene(ISceneChanger* changer) {
	SceneChanger = changer;
}
void BaseScene::Finalize() {
}
