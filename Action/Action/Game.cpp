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
Game::Game(Keyboard* keyboard, Sound* sound,ISceneChanger* changer, const char stagename[30]) : BaseScene(keyboard,sound,changer) {
	gamecanvas_ = (CanvasBase*) new GameUsually(keyboard_,this); 
	memcpy(stagename_, stagename, 30);
	stagemgr_ = (StageMgr*) new StageMgr(keyboard_,sound_,this,stagename_);
	nextstate_ = GameState::Game_None;
}

///<summary>
///<para>����������</para>
///<para>�����ƃX�e�[�W�̏������������s��</para>
///</summary>
void Game::Initialize() {
	gamecanvas_->Initialize();
	stagemgr_->Initialize();
}

///<summary>
///<para>�X�V����</para>
///<para>�����̍X�V�������s��</para>
///<para>nextstate���ύX����Ă����ꍇ�A�ύX�������s��</para>
///</summary>
void Game::Update() {
	UpdateNextState();
	if (typeid(*gamecanvas_) == typeid(GameUsually) || typeid(*gamecanvas_) == typeid(GameDance)) {
		stagemgr_->Update(); 
	}
	gamecanvas_->Update();
}

///<summary>
///<para>�`�ʏ���</para>
///<para>�����ƃX�e�[�W�̕`�ʏ������s��</para>
///</summary>
void Game::Draw() {
	stagemgr_->Draw();
	gamecanvas_->Draw();
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
	sound_->PlayBgm(BGM_Name::BGM_Game);
}

///<summary>
///<para>nextstate_���ύX����Ă����ꍇ�Anextstate_�̒l�ɂ���đΉ����鏈�����s��</para>
///</summary>
void Game::UpdateNextState(){
	if (nextstate_ != GameState::Game_None) {
		gamecanvas_->Finalize();
		switch (nextstate_) {
		case GameState::Game_Usually:
			gamecanvas_ = (CanvasBase*) new GameUsually(keyboard_,this);
			gamecanvas_->Initialize();
			break;
		case GameState::Game_Menu:
			gamecanvas_ = (CanvasBase*) new GameMenu(keyboard_, this);
			gamecanvas_->Initialize();
			break;
		case GameState::Game_Dance:
			gamecanvas_ = (CanvasBase*) new GameDance(keyboard_, this);
			gamecanvas_->Initialize();
			break;
		case GameState::Game_Clear:
			gamecanvas_ = (CanvasBase*) new GameClear(keyboard_, this);
			gamecanvas_->Initialize();
			break;
		case GameState::Game_Retry:
			stagemgr_->Retry();
			gamecanvas_ = (CanvasBase*) new GameUsually(keyboard_, this);
			gamecanvas_->Initialize();
			break;
		case GameState::Game_Exit:
			scenechanger_->ChangeScene(Scene::Scene_Title);
			break;
		default:
			assert(false);
			break;
		}
		nextstate_ = GameState::Game_None;
	}
}

///<summary>
///<para>State�̕ύX����</para>
///<para>nextstate_�������̒l�ɕύX����</para>
///<param name= "state"><para>nextstate_��Copy����l</para></param>
///</summary>
void Game::ChangeState(GameState state) {
	this->nextstate_ = state;
}