#include "BaseScene.h"
#include "DxLib.h"

///<summary>
///<para>�L�[�{�[�h�ƃT�E���h�ƃV�[����ύX����N���X�̃|�C���^����������</para>
///</summary>
BaseScene::BaseScene(Keyboard* keyboard,Sound* sound,ISceneChanger* changer) {
	keyboard_ = keyboard;
	sound_ = sound;
	scenechanger_ = changer;
}
void BaseScene::Finalize() {
}
