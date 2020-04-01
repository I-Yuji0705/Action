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
	manualcanvas_ = (CanvasBase*) new ManualUsually(keyboard_,this);
}

///<summary>
///<para>初期化処理</para>
///<para>字幕の初期化処理を行う</para>
///</summary>
void Manual::Initialize() {
	manualcanvas_->Initialize();
}

///<summary>
///<para>更新処理</para>
///<para>字幕の更新処理を行う</para>
///<para>nextstate_が変更されていた場合、nextstate_によって処理を行う</para>
///</summary>
void Manual::Update() {
	if (nextstate_ != Manual_None) {
		manualcanvas_->Finalize();
		switch (nextstate_) {
		case Manual_Usually:
			manualcanvas_ = (CanvasBase*) new ManualUsually(keyboard_,this);
			manualcanvas_->Initialize();
			break;
		case Manual_Operation:
			manualcanvas_ = (CanvasBase*) new ManualOperation(keyboard_,this);
			manualcanvas_->Initialize();
			break;
		case Manual_Stage:
			manualcanvas_ = (CanvasBase*) new ManualStage(keyboard_,this);
			manualcanvas_->Initialize();
			break;
		case Manual_Rule:
			manualcanvas_ = (CanvasBase*) new ManualRule(keyboard_,this);
			manualcanvas_->Initialize();
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
	manualcanvas_->Update();
}

///<summary>
///<para>描写処理</para>
///<para>背景と字幕の描写処理を行う</para>
///</summary>
void Manual::Draw() {
	DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), TRUE);//背景の設定
	manualcanvas_->Draw();
}

///<summary>
///<para>終了処理</para>
///<para>字幕の終了処理を行う</para>
///</summary>
void Manual::Finalize() {
	manualcanvas_->Finalize();
}

///<summary>
///<para>Stateの変更処理</para>
///<para>nextstate_を引数の値に変更する</para>
///<param name= "state"><para>nextstate_にCopyする値</para></param>
///</summary>
void Manual::ChangeState(ManualState state) {
	nextstate_ = state;
}

///<summary>
///<para>マニュアル画面のBGMを再生する</para>
///</summary>
void Manual::StartBgm() {
	sound_->PlayBgm(BGM_Manual);
}