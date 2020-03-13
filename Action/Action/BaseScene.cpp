#include "BaseScene.h"
#include "DxLib.h"

///<summary>
///<para>キーボードとサウンドとシーンを変更するクラスのポインタを収得する</para>
///</summary>
BaseScene::BaseScene(Keyboard* keyboard,Sound* sound,ISceneChanger* changer) {
	keyboard_ = keyboard;
	sound_ = sound;
	scenechanger_ = changer;
}
void BaseScene::Finalize() {
}
