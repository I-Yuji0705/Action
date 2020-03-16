#include "Manual.h"
#include "DxLib.h"
#include <assert.h>
#include "ManualUsually.h"
#include "ManualOperation.h"
#include "ManualStage.h"
#include "ManualRule.h"

///<summary>
///<para>コンストラクタ</para>
///<para>最初に表示する字幕を管理するクラスの生成</para>
///</summary>
Manual::Manual(Keyboard* keyboard, Sound* sound, ISceneChanger* changer) : BaseScene(keyboard, sound,changer) {
	nextstate_ = Manual_None;
	manualselection_ = (ManualSelectionBase*) new ManualUsually(keyboard_,this);
}

///<summary>
///<para>初期化処理</para>
///<para>字幕の初期化処理を行う</para>
///</summary>
void Manual::Initialize() {
	manualselection_->Initialize();
}

///<summary>
///<para>更新処理</para>
///<para>現在のステートの変更要請の確認と、字幕の更新処理を行う</para>
///<para>変更要請があった場合、変更処理を行う</para>
///</summary>
void Manual::Update() {
	if (nextstate_ != Manual_None) {
		manualselection_->Finalize();
		switch (nextstate_) {
		case Manual_Usually:
			manualselection_ = (ManualSelectionBase*) new ManualUsually(keyboard_,this);
			manualselection_->Initialize();
			break;
		case Manual_Operation:
			manualselection_ = (ManualSelectionBase*) new ManualOperation(keyboard_,this);
			manualselection_->Initialize();
			break;
		case Manual_Stage:
			manualselection_ = (ManualSelectionBase*) new ManualStage(keyboard_,this);
			manualselection_->Initialize();
			break;
		case Manual_Rule:
			manualselection_ = (ManualSelectionBase*) new ManualRule(keyboard_,this);
			manualselection_->Initialize();
			break;
		case Manual_Exit:
			scenechanger_->ChangeScene(Scene_Title);
			break;
		default:
			assert(false);
			break;
		}
		nextstate_ = Manual_None;
	}
	manualselection_->Update();
}

//描画
void Manual::Draw() {
	DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), TRUE);//背景の設定
	manualselection_->Draw();
}

///<summary>
///<para>終了処理</para>
///<para>字幕の終了処理を行う</para>
///</summary>
void Manual::Finalize() {
	manualselection_->Finalize();
}

void Manual::ChangeState(ManualState state) {
	nextstate_ = state;
}

///<summary>
///<para>マニュアル画面のBGMを再生する</para>
///</summary>
void Manual::StartBgm() {
	sound_->PlayBgm(BGM_Manual);
}