#include "TitleStageSelect.h"
#include "DxLib.h"
#include "Keyboard.h"
#include <assert.h>
#include "TextData.h"
#include "TitleOptionData.h"
#include "TitleToGameOptionData.h"

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�����̐���</para>
///</summary>
TitleStageSelect::TitleStageSelect(Keyboard* keyboard, ITitleStateChanger* statechanger) :TitleCanvasOptionBase(keyboard, statechanger) {
	optionData_.push_back((OptionDataBase*) new TitleToGameOptionData(400, 300, "�Q�[���X�^�[�g", GetColor(0, 0, 0), statechanger, TitleState::Title_Game, "stage2"));
	optionData_.push_back((OptionDataBase*) new TitleToGameOptionData(400, 350, "�e�X�g�X�^�[�g", GetColor(0, 0, 0), statechanger, TitleState::Title_Game, "test"));
}