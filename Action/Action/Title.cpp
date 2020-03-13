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
//������
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
			DxLib_End();//�v���O�������I������
			break;
		default:
			assert(false);
			break;
		}
		nextstate_ = Title_None;
	}
	titleselection_->Update();
}

//�`��
void Title::Draw() {
	DrawBox(0, 0, 640, 480, GetColor(255,255,255), TRUE);//�w�i�F�̐ݒ�
	titleselection_->Draw();//�����̕\��
	DrawModiGraph(50,50,600,50,600,300,50,300,title_,FALSE);//�^�C�g���̕\��
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