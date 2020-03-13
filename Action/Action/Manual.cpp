#include "Manual.h"
#include "DxLib.h"
#include <assert.h>
#include "ManualUsually.h"
#include "ManualOperation.h"
#include "ManualStage.h"
#include "ManualRule.h"

Manual::Manual(ISceneChanger* changer, Sound* sound) : BaseScene(changer, sound) {
}
//‰Šú‰»
void Manual::Initialize() {
	nextstate_ = Manual_None;
	manualselection_ = (ManualSelectionBase*) new ManualUsually(this);
	manualselection_->Initialize();
}
void Manual::Update() {
	if (nextstate_ != Manual_None) {
		manualselection_->Finalize();
		switch (nextstate_) {
		case Manual_Usually:
			manualselection_ = (ManualSelectionBase*) new ManualUsually(this);
			manualselection_->Initialize();
			break;
		case Manual_Operation:
			manualselection_ = (ManualSelectionBase*) new ManualOperation(this);
			manualselection_->Initialize();
			break;
		case Manual_Stage:
			manualselection_ = (ManualSelectionBase*) new ManualStage(this);
			manualselection_->Initialize();
			break;
		case Manual_Rule:
			manualselection_ = (ManualSelectionBase*) new ManualRule(this);
			manualselection_->Initialize();
			break;
		case Manual_Exit:
			SceneChanger->ChangeScene(Scene_Menu);
			break;
		default:
			assert(false);
			break;
		}
		nextstate_ = Manual_None;
	}
	manualselection_->Update();
}

//•`‰æ
void Manual::Draw() {
	DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), TRUE);//”wŒiF‚ÌÝ’è
	manualselection_->Draw();
}

void Manual::Finalize() {
	manualselection_->Finalize();
}
void Manual::ChangeState(ManualState state) {
	nextstate_ = state;
}
void Manual::StartBgm() {
	sound_->PlayBgm(BGM_Manual);
}