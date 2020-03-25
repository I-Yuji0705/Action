#include "GameMenu.h"
#include "DxLib.h"
#include <assert.h>
#include "TextDeta.h"
#include "GameOptionDeta.h"

///<summary>
///<para>コンストラクタ</para>
///<para>ゲーム時のメニュー画面の字幕生成</para>
///</summary>
GameMenu::GameMenu(Keyboard* keyboard,IGameStateChanger* statechanger)  : GameCanvasOptionBase(keyboard,statechanger){
	optiondeta_.push_back((OptionDetaBase*)new GameOptionDeta(300, 100, "つづける", GetColor(0, 0, 0),statechanger, Game_Usually));
	optiondeta_.push_back((OptionDetaBase*)new GameOptionDeta(300, 150, "でなおす", GetColor(0, 0, 0), statechanger, Game_Exit));
	optiondeta_.push_back((OptionDetaBase*)new GameOptionDeta(300, 200, "やりなおす", GetColor(0, 0, 0), statechanger, Game_Retry));
}