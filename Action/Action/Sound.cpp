#include "Sound.h"
#include "DxLib.h"
#include <stdlib.h>

//BGM��SE�̐ݒ�
///<summary>
///<para>�R���X�g���N�^</para>
///<para>�v���O�������Ŏg�p����BGM��SE�̐ݒ��SE�̉��ʒ���</para>
///<para>���ݖ炵�Ă���BGM�𖳂��ɂ���</para>
///</summary>
Sound::Sound() {
	bgm_[BGM_Menu] = LoadSoundMem("Sound/BGM/Carmel_Latte.mp3");
	bgm_[BGM_Game] = LoadSoundMem("Sound/BGM/Attention_Shoppers.mp3");
	bgm_[BGM_Manual] = LoadSoundMem("Sound/BGM/04_Moanin'.mp3");
	se_[Se_Hit] = LoadSoundMem("Sound/SE/A1_19294.WAV");
	se_[Se_Pick] = LoadSoundMem("Sound/SE/A1_05089.WAV");
	se_[Se_Throw] = LoadSoundMem("Sound/SE/A1_16258.WAV");
	se_[Se_Put] = LoadSoundMem("Sound/SE/A1_05091.WAV");
	se_[Se_Cant] = LoadSoundMem("Sound/SE/A1_03065.WAV");
	se_[Se_Jump] = LoadSoundMem("Sound/SE/A1_18280.WAV");
	se_[Se_Clear] = LoadSoundMem("Sound/SE/Mind_Star_Seven_10.mp3");
	se_[Se_SceneChange] = LoadSoundMem("Sound/SE/A1_04087.WAV");
	sevolume_[Se_Hit] = 128;
	sevolume_[Se_Pick] = 128;
	sevolume_[Se_Throw] = 128;
	sevolume_[Se_Put] = 128;
	sevolume_[Se_Clear] = 128;
	sevolume_[Se_SceneChange] = 128;
	bgmname_ = BGM_None;
}

///<summary>
///<para>���ʂ̒���</para>
///<para>�����Ŏ󂯎����Object���o�����ʂ̒������s��</para>
///<para>�Ώۂ�Object����ʊO�ɂ��鎞�A����Ă���قǉ��͏������Ȃ�</para>
///<para>����:</para>
///<param name="sename"><para>sename:�炻���Ƃ��Ă���SE�̗񋓎q</para></param>
///<param name="num"><para>object:����炻���Ƃ��Ă���Object</para></param>
///<para>�߂�l:</para>
///<returns>
///<para>�炷����(0�`255)</para>
///</returns>
///</summary>
int Sound::RegulationSeVolume(Se_Name sename, const Object* object) {
	int volume = se_[sename];
	const float kWindowX = 640.0f;
	const float kWindowCenterX = kWindowX / 2;
	if (object->Center_X() < -kWindowX / 2 || object->Center_X() > kWindowX + kWindowX / 2) {
		volume = 0;
	}
	else if (object->Center_X() < 0.0f) {
		volume = (int)(se_[sename] * kWindowCenterX / abs(object->Center_X()) + kWindowCenterX);
	}
	else if (object->Center_X() > kWindowX) {
		volume = (int)(se_[sename] * kWindowCenterX / object->Center_X() - kWindowCenterX);
	}
	return volume;
}
//------------------------------------------------
//BGM�̍Đ�
//	����:
//		bgmname:�Đ�����BGM�̎��
///<summary>
///<para>BGM�̍Đ�</para>
///<para>�����Ŏ󂯎����BGM���Đ����A�Đ����Ă���BGM�̗񋓎q���X�V����</para>
///<para>�����Ŏ󂯎�����񋓎q�����ݖ炵�Ă���BGM�̏ꍇ�A�������Ȃ�</para>
///<para>����:</para>
///<param name="bgmname"><para>bgmname:�炻���Ƃ��Ă���BGM�̗񋓎q</para></param>
///</summary>
void Sound::PlayBgm(BGM_Name bgmname) {
	if (bgmname_ != bgmname) {
		StopBgm();
		bgmname_ = bgmname;
		ChangeVolumeSoundMem(128, bgm_[bgmname_]);
		PlaySoundMem(bgm_[bgmname_], DX_PLAYTYPE_LOOP);
	}
}

///<summary>
///<para>SE�̍Đ�</para>
///<para>�����Ŏ󂯎����SE���Đ�����</para>
///<para>����:</para>
///<param name="sename"><para>sename:�炻���Ƃ��Ă���se�̗񋓎q</para></param>
///</summary>
void Sound::PlaySe(Se_Name sename) {
	if (CheckSoundMem(se_[sename]) == 1) {
		StopSoundMem(se_[sename]);
	}
	ChangeVolumeSoundMem(sevolume_[sename], se_[sename]);
	PlaySoundMem(se_[sename], DX_PLAYTYPE_BACK);
}
//--------
//Se�̍Đ�
//	����:
//		sename:�Đ�����BGM�̎��
//		object:���𔭐�������object
///<summary>
///<para>SE�̍Đ�</para>
///<para>�����Ŏ󂯎����SE���Đ�����</para>
///<para>����:</para>
///<param name="sename"><para>sename:�炻���Ƃ��Ă���se�̗񋓎q</para></param>
///</summary>
void Sound::PlaySe(Se_Name sename,const Object* object) {
	if (CheckSoundMem(se_[sename]) == 1) {
		StopSoundMem(se_[sename]);
	}
	int volume = RegulationSeVolume(sename, object);
	ChangeVolumeSoundMem(volume, se_[sename]);
	PlaySoundMem(se_[sename], DX_PLAYTYPE_BACK);
}
//---------
//BGM�̒�~

///<summary>
///<para>SE�̍Đ�</para>
///<para>�����Ŏ󂯎����SE���Đ�����</para>
///<para>����:</para>
///<param name="sename"><para>sename:�炻���Ƃ��Ă���se�̗񋓎q</para></param>
///</summary>
void Sound::StopBgm() {
	if (bgmname_ != BGM_None) {
		StopSoundMem(bgm_[bgmname_]);
		bgmname_ = BGM_None;
	}
}

void Sound::StopSe() {
	for (int i = 0; i != Se_None; i++) {
		if (CheckSoundMem(se_[i]) == 1) {
			StopSoundMem(se_[i]);
		}
	}
}
void Sound::Finalize() {
	InitSoundMem();
}