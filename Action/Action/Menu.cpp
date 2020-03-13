#include "Menu.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "MenuUsually.h"
#include "MenuDelete.h"

Menu::Menu(Keyboard* keyboard,Sound* sound,ISceneChanger* changer) : BaseScene(keyboard,sound,changer) {
	menuselection_ = (MenuSelectionBase*) new MenuUsually(keyboard_, this);
	title_ = LoadGraph("Title/title.png");
	nextstate_ = Menu_None;
}
//初期化
void Menu::Initialize() {
	menuselection_->Initialize();
}
void Menu::Update(){
	if (nextstate_ != Menu_None) {
		menuselection_->Finalize();
		switch (nextstate_) {
		case Menu_Usually:
			menuselection_ = (MenuSelectionBase*) new MenuUsually(keyboard_,this);
			menuselection_->Initialize();
			break;
		case Menu_Delete:
			menuselection_ = (MenuSelectionBase*) new MenuDelete(keyboard_, this);
			menuselection_->Initialize();
			break;
		case Menu_Intersection:
			scenechanger_->ChangeScene(Scene_Manual);
			menuselection_->Initialize();
			break;
		case Menu_Game:
			scenechanger_->ChangeScene(Scene_Game);
			menuselection_->Initialize();
			break;
		case Menu_Exit:
			DxLib_End();//プログラムを終了する
			break;
		default:
			assert(false);
			break;
		}
		nextstate_ = Menu_None;
	}
	menuselection_->Update();
}

//描画
void Menu::Draw() {
	DrawBox(0, 0, 640, 480, GetColor(255,255,255), TRUE);//背景色の設定
	menuselection_->Draw();//字幕の表示
	DrawModiGraph(50,50,600,50,600,300,50,300,title_,FALSE);//タイトルの表示
}
void Menu::Finalize() {
	DeleteGraph(title_);
}

void Menu::ChangeState(MenuState state){
	nextstate_ = state;
}
void Menu::StartBgm() {
	sound_->PlayBgm(BGM_Menu);
}