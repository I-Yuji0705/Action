#include "GameMenu.h"
#include "DxLib.h"
#include <assert.h>
#include "TextData.h"
#include "GameOptionData.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�Q�[�����̃��j���[��ʂ̎�������</para>
///</summary>
GameMenu::GameMenu(Keyboard* keyboard,IGameStateChanger* statechanger)  : GameCanvasOptionBase(keyboard,statechanger){
	optionData_.push_back((OptionDataBase*)new GameOptionData(300, 100, "�Â���", GetColor(0, 0, 0),statechanger, Game_Usually));
	optionData_.push_back((OptionDataBase*)new GameOptionData(300, 150, "�łȂ���", GetColor(0, 0, 0), statechanger, Game_Exit));
	optionData_.push_back((OptionDataBase*)new GameOptionData(300, 200, "���Ȃ���", GetColor(0, 0, 0), statechanger, Game_Retry));
}