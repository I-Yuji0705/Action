#include "BaseScene.h"
#include "DxLib.h"

BaseScene::BaseScene(ISceneChanger* changer,Sound* sound) {
	SceneChanger = changer;
	sound_ = sound;
}
void BaseScene::Finalize() {
}
