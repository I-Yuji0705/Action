#include "Menu.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "MenuUsually.h"
#include "MenuDelete.h"

Menu::Menu(ISceneChanger* changer,Sound* sound) : BaseScene(changer,sound) {
}
//������
void Menu::Initialize() {
	nextstate_ = Menu_None;
	menuselection_ =(MenuSelectionBase*) new MenuUsually(this);
	menuselection_->Initialize();
	title_ = LoadGraph("Title/title.png");
}
void Menu::Update(){
	if (nextstate_ != Menu_None) {
		menuselection_->Finalize();
		switch (nextstate_) {
		case Menu_Usually:
			menuselection_ = (MenuSelectionBase*) new MenuUsually(this);
			menuselection_->Initialize();
			break;
		case Menu_Delete:
			menuselection_ = (MenuSelectionBase*) new MenuDelete(this);
			menuselection_->Initialize();
			break;
		case Menu_Intersection:
			SceneChanger->ChangeScene(Scene_Manual);
			menuselection_->Initialize();
			break;
		case Menu_Game:
			SceneChanger->ChangeScene(Scene_Game);
			menuselection_->Initialize();
			break;
		case Menu_Exit:
			DxLib_End();//�v���O�������I������
			break;
		default:
			assert(false);
			break;
		}
		nextstate_ = Menu_None;
	}
	menuselection_->Update();
}

//�`��
void Menu::Draw() {
	DrawBox(0, 0, 640, 480, GetColor(255,255,255), TRUE);//�w�i�F�̐ݒ�
	menuselection_->Draw();//�����̕\��
	DrawModiGraph(50,50,600,50,600,300,50,300,title_,FALSE);//�^�C�g���̕\��
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