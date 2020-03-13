#include "DxLib.h"
#include "Keyboard.h"
#include "Fps.h"
#include "SceneMgr.h"
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);
	SceneMgr sceneMgr;
	sceneMgr.Initialize();
	SetTransColor(200, 200, 200);
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0  && //���b�Z�[�W�����A��ʂ̃N���A�A����ʂ�\��ʂɔ��f
		Keyboard::getInstance()->UpdateKey() ==0 &&Fps::getInstance()->Update() ==0 )//�L�[�̏�Ԃ��X�V�AFPS���X�V
	{
		sceneMgr.Update();
		sceneMgr.Draw();
	}

	sceneMgr.Finalize();

	DxLib_End();
	return 0;
}