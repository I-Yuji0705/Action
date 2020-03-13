
#include "Menu.h"
#include "DxLib.h"
//#include "Keyboard.h"
Menu::Menu(ISceneChanger* changer) : BaseScene(changer) {
}

//������
void Menu::Initialize() {
	MenuNum = 0;
	state = State_Select;
	DeleteNum = 0;
	menudeta[0] = { 100,100,"�Q�[���X�^�[�g" };
	menudeta[1] = { 100,200,"�Q�[���I��" };
	deletemessage[0] = { 80,100,"�͂�" };
	deletemessage[1] = { 140,100,"������" };
}
void Menu::SelectMenu() {
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_DOWN) == 1 || 
		Keyboard::getInstance()->CheckKey(KEY_INPUT_UP) == 1) {
		MenuNum = (MenuNum + 1) % 2;
	}
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RETURN) == 1) {
		switch (MenuNum) {
		case 0:
			SceneChanger->ChangeScene(Scene_Game);
			break;
		case 1:
			state = State_Delete;
			break;
		}
	}
}
void Menu::SelectDelete() {

	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_LEFT) == 1 || 
		Keyboard::getInstance()->CheckKey(KEY_INPUT_RIGHT) == 1) {
		DeleteNum = (DeleteNum + 1) % 2;
	}
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RETURN) == 1) {
		switch (DeleteNum) {
		case 0:
			DxLib_End();
			break;
		case 1:
			state = State_Select;
			break;
		}
	}
}

//�X�V
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

//�`��
void Menu::Draw() {
	switch (state) {
	case State_Select:
		DrawString(0, 0, "���j���[��ʂł��B", GetColor(255, 255, 255));
		DrawString(menudeta[MenuNum].x - 20, menudeta[MenuNum].y, "��", GetColor(255, 255, 255));
		for (int i = 0; i < 2; i++) {
			DrawString(menudeta[i].x, menudeta[i].y, menudeta[i].name, GetColor(255, 255, 255));
		}
		break;
	case State_Delete:
		DrawString(0, 0, "�{���ɃQ�[�����I�����܂����H", GetColor(255, 255, 255));
		DrawString(deletemessage[DeleteNum].x - 20, 100, "��", GetColor(255, 255, 255));
		for (int i = 0; i < 2; i++) {
			DrawString(deletemessage[i].x, deletemessage[i].y, deletemessage[i].name, GetColor(255, 255, 255));
		}
		break;
	}
}
