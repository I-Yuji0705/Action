#include "GameMenu.h"
#include "DxLib.h"
#include <assert.h>
#include "TextDeta.h"
#include "GameOptionDeta.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�Q�[�����̃��j���[��ʂ̎�������</para>
///</summary>
GameMenu::GameMenu(Keyboard* keyboard,IGameStateChanger* statechanger)  : GameCanvasOptionBase(keyboard,statechanger){
	optiondeta_.push_back((OptionDetaBase*)new GameOptionDeta(300, 100, "�Â���", GetColor(0, 0, 0),statechanger, Game_Usually));
	optiondeta_.push_back((OptionDetaBase*)new GameOptionDeta(300, 150, "�łȂ���", GetColor(0, 0, 0), statechanger, Game_Exit));
	optiondeta_.push_back((OptionDetaBase*)new GameOptionDeta(300, 200, "���Ȃ���", GetColor(0, 0, 0), statechanger, Game_Retry));
}