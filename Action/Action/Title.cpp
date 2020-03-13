#include "Title.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "TitleUsually.h"
#include "TitleDelete.h"

Title::Title(Keyboard* keyboard,Sound* sound,ISceneChanger* changer) : BaseScene(keyboard,sound,changer) {
	titleselection_ = (TitleSelectionBase*) new TitleUsually(keyboard_, this);
	title_ = LoadGraph("Title/title.png");
	nextstate_ = Title_None;
}
//初期化
void Title::Initialize() {
	titleselection_->Initialize();
}
void Title::Update(){
	if (nextstate_ != Title_None) {
		titleselection_->Finalize();
		switch (nextstate_) {
		case Title_Usually:
			titleselection_ = (TitleSelectionBase*) new TitleUsually(keyboard_,this);
			titleselection_->Initialize();
			break;
		case Title_Delete:
			titleselection_ = (TitleSelectionBase*) new TitleDelete(keyboard_, this);
			titleselection_->Initialize();
			break;
		case Title_Intersection:
			scenechanger_->ChangeScene(Scene_Manual);
			titleselection_->Initialize();
			break;
		case Title_Game:
			scenechanger_->ChangeScene(Scene_Game);
			titleselection_->Initialize();
			break;
		case Title_Exit:
			DxLib_End();//プログラムを終了する
			break;
		default:
			assert(false);
			break;
		}
		nextstate_ = Title_None;
	}
	titleselection_->Update();
}

//描画
void Title::Draw() {
	DrawBox(0, 0, 640, 480, GetColor(255,255,255), TRUE);//背景色の設定
	titleselection_->Draw();//字幕の表示
	DrawModiGraph(50,50,600,50,600,300,50,300,title_,FALSE);//タイトルの表示
}
void Title::Finalize() {
	DeleteGraph(title_);
}

void Title::ChangeState(TitleState state){
	nextstate_ = state;
}
void Title::StartBgm() {
	sound_->PlayBgm(BGM_Menu);
}