
#include "Menu.h"
#include "DxLib.h"
#include "Keyboard.h"
//#include "Keyboard.h"
Menu::Menu(ISceneChanger* changer) : BaseScene(changer) {
}
//案その１：選択した項目を中心に画面の周りが黒で囲まれて行き、いったん黒い画面を挟んだ後、プレイヤーを中心に黒い画面が引いてゆく。
//案その２：ゲームスタートを選択時に選択画面が下にずれて行き、いったん黒い画面を挟んだ後、ゲーム画面が上から降りてくる

//初期化
void Menu::Initialize() {
	MenuNum = 0;
	state = State_Select;
	DeleteNum = 0;
	menudeta[0] = { 100,100,"ゲームスタート" };
	menudeta[1] = { 100,200,"ゲーム終了" };
	deletemessage[0] = { 250,300,"はい" };
	deletemessage[1] = { 350,300,"いいえ" };
}
//メニュー画面のボタン入力を管理する
void Menu::SelectMenu() {
	//上キーか下キーを押されたとき
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_DOWN) == 1 || 
		Keyboard::getInstance()->CheckKey(KEY_INPUT_UP) == 1) {
		MenuNum = (MenuNum + 1) % 2;//選択している項目をずらす
	}
	//Enterキーを入力したとき
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RETURN) == 1) {
		switch (MenuNum) {
		case 0:
			SceneChanger->ChangeScene(Scene_Game);
			break;
		case 1:
			state = State_Delete;
			break;
		default:
			break;
		}
	}
}
//終了確認画面のボタン入力を管理する
void Menu::SelectDelete() {

	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_LEFT) == 1 || 
		Keyboard::getInstance()->CheckKey(KEY_INPUT_RIGHT) == 1) {
		DeleteNum = (DeleteNum + 1) % 2;
	}
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RETURN) == 1) {
		switch (DeleteNum) {
		case 0:
			DxLib_End();//プログラムを終了する
			break;
		case 1:
			state = State_Select;//メニュー画面に移行する
			break;
		}
	}
}

//更新
void Menu::Update() {
	switch (state)
	{
	case State_Select:
		SelectMenu();
		break;
	case State_Delete:
		SelectDelete();
		break;
	}
}

//描画
void Menu::Draw() {
	DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), TRUE);//背景色の設定
	unsigned int  MenuColor = GetColor(0, 0, 0);
	switch (state) {
	case State_Select:
		DrawString(menudeta[MenuNum].x - 20, menudeta[MenuNum].y, "●", MenuColor);
		for (int i = 0; i < 2; i++) {
			DrawString(menudeta[i].x, menudeta[i].y, menudeta[i].name, MenuColor);
		}
		break;
	case State_Delete:
		DrawString(200,150, "本当にゲームを終了しますか？", MenuColor);
		DrawString(deletemessage[DeleteNum].x - 20, deletemessage[DeleteNum].y, "●", MenuColor);
		for (int i = 0; i < 2; i++) {
			DrawString(deletemessage[i].x, deletemessage[i].y, deletemessage[i].name, MenuColor);
		}
		break;
	}
}
