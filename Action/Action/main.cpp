#include "DxLib.h"
#include "Keyboard.h"
#include "Fps.h"
#include "SceneMgr.h"
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);
	Keyboard* keyboard = new Keyboard();
	Sound* sound = new Sound();
	SceneMgr sceneMgr(keyboard,sound);
	Fps fps;
	sceneMgr.Initialize();
	SetTransColor(200, 200, 200);//追加で透過する色の設定(透過してほしい色がないため、使用しない色を設定)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0  && //メッセージ処理、画面のクリア、裏画面を表画面に反映
		keyboard->UpdateKey() ==0 &&fps.Update() ==0 ) {//キーの状態を更新、FPSを更新
		sceneMgr.Update();//Sceneの更新
		sceneMgr.Draw();//Sceneの描写
	}
	sceneMgr.Finalize();
	DxLib_End();
	return 0;
}