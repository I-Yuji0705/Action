#include "Title.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "TitleUsually.h"
#include "TitleDelete.h"
#include "TitleStageSelect.h"

///<summary>
///<para>コンストラクタ</para>
///<para>追加で、タイトルに表示する画像と最初に表示する字幕の生成を行う</para>
///</summary>
Title::Title(Keyboard* keyboard, Sound* sound, ISceneChanger* changer) : BaseScene(keyboard, sound, changer) {
	titlecanvas_ = (CanvasBase*) new TitleUsually(keyboard_, this);
	title_ = LoadGraph("Title/title.png");
	nextstate_ = TitleState::Title_None;
}

///<summary>
///<para>初期化処理</para>
///<para>字幕の初期化処理を行う</para>
///</summary>
void Title::Initialize() {
	titlecanvas_->Initialize();
}

///<summary>
///<para>更新処理</para>
///<para>字幕の更新処理を行う</para>
///<para>nextstateが変更されていた場合、nextstateによって処理を行う</para>
///</summary>
void Title::Update(){
	if (nextstate_ != TitleState::Title_None) {
		titlecanvas_->Finalize();
		switch (nextstate_) {
		case TitleState::Title_Usually:
			titlecanvas_ = (CanvasBase*) new TitleUsually(keyboard_,this);
			titlecanvas_->Initialize();
			break;
		case TitleState::Title_Delete:
			titlecanvas_ = (CanvasBase*) new TitleDelete(keyboard_, this);
			titlecanvas_->Initialize();
			break;
		case TitleState::Title_Intersection:
			scenechanger_->ChangeScene(Scene::Scene_Manual);
			titlecanvas_->Initialize();
			break;
		case TitleState::Title_Game:
			scenechanger_->ChangeScene(Scene::Scene_Game,stagename_);
			titlecanvas_->Initialize();
			break;
		case TitleState::Title_StageSelect:
			titlecanvas_ = (CanvasBase*) new TitleStageSelect(keyboard_, this);
			titlecanvas_->Initialize();
			break;
		case TitleState::Title_Exit:
			DxLib_End();//プログラムを終了する
			break;
		default:
			assert(false);
			break;
		}
		nextstate_ = TitleState::Title_None;
	}
	titlecanvas_->Update();
}

///<summary>
///<para>描写処理</para>
///<para>タイトルと字幕の描写処理を行う</para>
///</summary>
void Title::Draw() {
	DrawBox(0, 0, 640, 480, GetColor(255,255,255), TRUE);//背景色の設定
	titlecanvas_->Draw();//字幕の表示
	DrawModiGraph(50,50,600,50,600,300,50,300,title_,FALSE);//タイトルの表示
}

///<summary>
///<para>終了処理</para>
///<para>メモリ上のタイトルの画像を削除し、字幕の終了処理を行う</para>
///</summary>
void Title::Finalize() {
	DeleteGraph(title_);
	titlecanvas_->Finalize();
}

///<summary>
///<para>Stateの変更処理</para>
///<para>nextstate_を引数の値に変更する</para>
///<para>引数:</para>
///<param name= "state"><para>nextstate_にCopyする値</para></param>
///</summary>
void Title::ChangeState(TitleState state){
	nextstate_ = state;
}


///<summary>
///<para>Stateの変更処理</para>
///<para>nextstate_を引数の値に変更する</para>
///<para>追加でステージの情報をコピーする</para>
///<para>引数:</para>
///<param name= "state"><para>nextstate_にCopyする値</para></param>
///<param name= "stagename"><para>stagename_にCopyする値</para></param>
///</summary>
void Title::ChangeState(TitleState state,const char stagename[30]) {
	memcpy(stagename_, stagename, 30);
	ChangeState(state);
}

///<summary>
///<para>現在鳴っているBGMを停止する</para>
///</summary>
void Title::StartBgm() {
	sound_->PlayBgm(BGM_Name::BGM_Menu);
}