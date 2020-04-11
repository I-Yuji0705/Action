#include "GameMenu.h"
#include "DxLib.h"
#include <assert.h>
#include "TextData.h"
#include "GameOptionData.h"

///<summary>
///<para>コンストラクタ</para>
///<para>ゲーム時のメニュー画面の字幕生成</para>
///</summary>
GameMenu::GameMenu(Keyboard* keyboard,IGameStateChanger* statechanger)  : GameCanvasOptionBase(keyboard,statechanger){
	optionData_.push_back((OptionDataBase*)new GameOptionData(300, 100, "つづける", GetColor(0, 0, 0),statechanger, Game_Usually));
	optionData_.push_back((OptionDataBase*)new GameOptionData(300, 150, "でなおす", GetColor(0, 0, 0), statechanger, Game_Exit));
	optionData_.push_back((OptionDataBase*)new GameOptionData(300, 200, "やりなおす", GetColor(0, 0, 0), statechanger, Game_Retry));
}