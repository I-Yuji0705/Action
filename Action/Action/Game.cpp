#include "Game.h"
#include "DxLib.h"
#include "Keyboard.h"
#include "GameClear.h"
#include "GameUsually.h"
#include "GameMenu.h"
#include "GameDance.h"
#include <assert.h>
#include <typeinfo>


///<summary>
///<para>�R���X�g���N�^</para>
///<para>�ŏ��ɕ\�����鎚���ƃX�e�[�W���Ǘ�����N���X�̐���</para>
///</summary>
Game::Game(Keyboard* keyboard, Sound* sound,ISceneChanger* changer) : BaseScene(keyboard,sound,changer) {
	gameselection_ = (GameSelectionBase*) new GameUsually(keyboard_,this);
	stagemgr_ = (StageMgr*) new StageMgr(keyboard_,sound_,this);
}

///<summary>
///<para>����������</para>
///<para>�����ƃX�e�[�W�̏������������s��</para>
///</summary>
void Game::Initialize() {
	gameselection_->Initialize();
	stagemgr_->Initialize();
}

///<summary>
///<para>�X�V����</para>
///<para>���݂̃X�e�[�g�̕ύX�v���̊m�F�ƁA�����ƃX�e�[�W�̍X�V�������s��</para>
///</summary>
void Game::Update() {
	UpdateNextState();
	if (typeid(*gameselection_) == typeid(GameUsually) || typeid(*gameselection_) == typeid(GameDance)) {
		stagemgr_->Update(); 
	}
	gameselection_->Update();
}

///<summary>
///<para>�`�ʏ���</para>
///<para>�����ƃX�e�[�W�̕`�ʏ������s��</para>
///</summary>
void Game::Draw() {
	stagemgr_->Draw();
	gameselection_->Draw();
}

///<summary>
///<para>�I������</para>
///<para>�����ƃX�e�[�W�̏I���������s��</para>
///</summary>
void Game::Finalize() {
	BaseScene::Finalize();
	stagemgr_->Finalize();
}

///<summary>
///<para>�Q�[����ʂ�BGM���Đ�����</para>
///</summary>
void Game::StartBgm() {
	sound_->PlayBgm(BGM_Game);
}

///<summary>
///<para>State�̕ύX�v�����������ꍇ�A�ύX�������s��</para>
///</summary>
void Game::UpdateNextState(){
	if (nextstate_ != Game_None) {
		gameselection_->Finalize();
		switch (nextstate_) {
		case Game_Usually:
			gameselection_ = (GameSelectionBase*) new GameUsually(keyboard_,this);
			gameselection_->Initialize();
			break;
		case Game_Menu:
			gameselection_ = (GameSelectionBase*) new GameMenu(keyboard_, this);
			gameselection_->Initialize();
			break;
		case Game_Dance:
			gameselection_ = (GameSelectionBase*) new GameDance(keyboard_, this);
			gameselection_->Initialize();
			break;
		case Game_Clear:
			gameselection_ = (GameSelectionBase*) new GameClear(keyboard_, this);
			gameselection_->Initialize();
			break;
		case Game_Retry:
			stagemgr_->Retry();
			gameselection_ = (GameSelectionBase*) new GameUsually(keyboard_, this);
			gameselection_->Initialize();
			break;
		case Game_Exit:
			scenechanger_->ChangeScene(Scene_Title);
			break;
		default:
			assert(false);
			break;
		}
		nextstate_ = Game_None;
	}
}

///<summary>
///<para>State�̕ύX�v��</para>
///</summary>
void Game::ChangeState(GameState state) {
	this->nextstate_ = state;
}