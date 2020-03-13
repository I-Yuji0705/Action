
#include "Menu.h"
#include "DxLib.h"
#include "Keyboard.h"
//#include "Keyboard.h"
Menu::Menu(ISceneChanger* changer) : BaseScene(changer) {
}
//�Ă��̂P�F�I���������ڂ𒆐S�ɉ�ʂ̎��肪���ň͂܂�čs���A�������񍕂���ʂ����񂾌�A�v���C���[�𒆐S�ɍ�����ʂ������Ă䂭�B
//�Ă��̂Q�F�Q�[���X�^�[�g��I�����ɑI����ʂ����ɂ���čs���A�������񍕂���ʂ����񂾌�A�Q�[����ʂ��ォ��~��Ă���

//������
void Menu::Initialize() {
	MenuNum = 0;
	state = State_Select;
	DeleteNum = 0;
	menudeta[0] = { 100,100,"�Q�[���X�^�[�g" };
	menudeta[1] = { 100,200,"�Q�[���I��" };
	deletemessage[0] = { 250,300,"�͂�" };
	deletemessage[1] = { 350,300,"������" };
}
//���j���[��ʂ̃{�^�����͂��Ǘ�����
void Menu::SelectMenu() {
	//��L�[�����L�[�������ꂽ�Ƃ�
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_DOWN) == 1 || 
		Keyboard::getInstance()->CheckKey(KEY_INPUT_UP) == 1) {
		MenuNum = (MenuNum + 1) % 2;//�I�����Ă��鍀�ڂ����炷
	}
	//Enter�L�[����͂����Ƃ�
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
//�I���m�F��ʂ̃{�^�����͂��Ǘ�����
void Menu::SelectDelete() {

	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_LEFT) == 1 || 
		Keyboard::getInstance()->CheckKey(KEY_INPUT_RIGHT) == 1) {
		DeleteNum = (DeleteNum + 1) % 2;
	}
	if (Keyboard::getInstance()->CheckKey(KEY_INPUT_RETURN) == 1) {
		switch (DeleteNum) {
		case 0:
			DxLib_End();//�v���O�������I������
			break;
		case 1:
			state = State_Select;//���j���[��ʂɈڍs����
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
	DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), TRUE);//�w�i�F�̐ݒ�
	unsigned int  MenuColor = GetColor(0, 0, 0);
	switch (state) {
	case State_Select:
		DrawString(menudeta[MenuNum].x - 20, menudeta[MenuNum].y, "��", MenuColor);
		for (int i = 0; i < 2; i++) {
			DrawString(menudeta[i].x, menudeta[i].y, menudeta[i].name, MenuColor);
		}
		break;
	case State_Delete:
		DrawString(200,150, "�{���ɃQ�[�����I�����܂����H", MenuColor);
		DrawString(deletemessage[DeleteNum].x - 20, deletemessage[DeleteNum].y, "��", MenuColor);
		for (int i = 0; i < 2; i++) {
			DrawString(deletemessage[i].x, deletemessage[i].y, deletemessage[i].name, MenuColor);
		}
		break;
	}
}
