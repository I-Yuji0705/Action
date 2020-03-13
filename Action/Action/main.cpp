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
	SetTransColor(200, 200, 200);//�ǉ��œ��߂���F�̐ݒ�(���߂��Ăق����F���Ȃ����߁A�g�p���Ȃ��F��ݒ�)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0  && //���b�Z�[�W�����A��ʂ̃N���A�A����ʂ�\��ʂɔ��f
		keyboard->UpdateKey() ==0 &&fps.Update() ==0 ) {//�L�[�̏�Ԃ��X�V�AFPS���X�V
		sceneMgr.Update();//Scene�̍X�V
		sceneMgr.Draw();//Scene�̕`��
	}
	sceneMgr.Finalize();
	DxLib_End();
	return 0;
}