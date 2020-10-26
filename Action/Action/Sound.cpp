#include "Sound.h"
#include "DxLib.h"
#include <stdlib.h>


///<summary>
///<para>�R���X�g���N�^</para>
///<para>�v���O�������Ŏg�p����BGM��SE�̐ݒ��SE�̉��ʒ���</para>
///<para>���ݖ炵�Ă���BGM�𖳂��ɂ���</para>
///</summary>
Sound::Sound() {
	bgm_[static_cast<int>(BGM_Name::BGM_Menu)] = LoadSoundMem("Sound/BGM/Carmel_Latte.mp3");
	bgm_[static_cast<int>(BGM_Name::BGM_Game)] = LoadSoundMem("Sound/BGM/Attention_Shoppers.mp3");
	bgm_[static_cast<int>(BGM_Name::BGM_Manual)] = LoadSoundMem("Sound/BGM/04_Moanin'.mp3");
	se_[static_cast<int>(Se_Name::Se_Hit)] = LoadSoundMem("Sound/SE/A1_19294.WAV");
	se_[static_cast<int>(Se_Name::Se_Pick)] = LoadSoundMem("Sound/SE/A1_05089.WAV");
	se_[static_cast<int>(Se_Name::Se_Throw)] = LoadSoundMem("Sound/SE/A1_16258.WAV");
	se_[static_cast<int>(Se_Name::Se_Put)] = LoadSoundMem("Sound/SE/A1_05091.WAV");
	se_[static_cast<int>(Se_Name::Se_Cant)] = LoadSoundMem("Sound/SE/A1_03065.WAV");
	se_[static_cast<int>(Se_Name::Se_Jump)] = LoadSoundMem("Sound/SE/A1_18280.WAV");
	se_[static_cast<int>(Se_Name::Se_Clear)] = LoadSoundMem("Sound/SE/Mind_Star_Seven_10.mp3");
	se_[static_cast<int>(Se_Name::Se_SceneChange)] = LoadSoundMem("Sound/SE/A1_04087.WAV");
	sevolume_[static_cast<int>(Se_Name::Se_Hit)] = 128;
	sevolume_[static_cast<int>(Se_Name::Se_Pick)] = 128;
	sevolume_[static_cast<int>(Se_Name::Se_Throw)] = 128;
	sevolume_[static_cast<int>(Se_Name::Se_Put)] = 128;
	sevolume_[static_cast<int>(Se_Name::Se_Clear)] = 128;
	sevolume_[static_cast<int>(Se_Name::Se_SceneChange)] = 128;
	bgmname_ = BGM_Name::BGM_None;
}

///<summary>
///<para>���ʂ̒���</para>
///<para>�����Ŏ󂯎����Object���o�����ʂ̒������s��</para>
///<para>�Ώۂ�Object����ʊO�ɂ��鎞�A����Ă���قǉ��͏������Ȃ�</para>
///<param name="sename"><para>sename:�炻���Ƃ��Ă���SE�̗񋓎q</para></param>
///<param name="num"><para>object:����炻���Ƃ��Ă���Object</para></param>
///<returns>
///<para>�炷����(0�`255)</para>
///</returns>
///</summary>
int Sound::RegulationSeVolume(Se_Name sename, const Object* object) {
	int volume = se_[static_cast<int>(sename)];
	const float kWindowX = 640.0f;
	const float kWindowCenterX = kWindowX / 2;
	if (object->Center_X() < -kWindowX / 2 || object->Center_X() > kWindowX + kWindowX / 2) {
		volume = 0;
	}
	else if (object->Center_X() < 0.0f) {
		volume = (int)(se_[static_cast<int>(sename)] * kWindowCenterX / abs(object->Center_X()) + kWindowCenterX);
	}
	else if (object->Center_X() > kWindowX) {
		volume = (int)(se_[static_cast<int>(sename)] * kWindowCenterX / object->Center_X() - kWindowCenterX);
	}
	return volume;
}

///<summary>
///<para>BGM�̍Đ�</para>
///<para>�����Ŏ󂯎����BGM���Đ����A�Đ����Ă���BGM�̗񋓎q���X�V����</para>
///<para>�����Ŏ󂯎�����񋓎q�����ݖ炵�Ă���BGM�̏ꍇ�A�������Ȃ�</para>
///<param name="bgmname"><para>bgmname:�炻���Ƃ��Ă���BGM�̗񋓎q</para></param>
///</summary>
void Sound::PlayBgm(BGM_Name bgmname) {
	if (bgmname_ != bgmname) {
		StopBgm();
		bgmname_ = bgmname;
		ChangeVolumeSoundMem(128, bgm_[static_cast<int>(bgmname_)]);
		PlaySoundMem(bgm_[static_cast<int>(bgmname_)], DX_PLAYTYPE_LOOP);
	}
}

///<summary>
///<para>SE�̍Đ�</para>
///<para>�����Ŏ󂯎����SE���Đ�����</para>
///<param name="sename"><para>sename:�炻���Ƃ��Ă���se�̗񋓎q</para></param>
///</summary>
void Sound::PlaySe(Se_Name sename) {
	if (CheckSoundMem(se_[static_cast<int>(sename)]) == 1) {
		StopSoundMem(se_[static_cast<int>(sename)]);
	}
	ChangeVolumeSoundMem(sevolume_[static_cast<int>(sename)], se_[static_cast<int>(sename)]);
	PlaySoundMem(se_[static_cast<int>(sename)], DX_PLAYTYPE_BACK);
}

///<summary>
///<para>SE�̍Đ�</para>
///<para>�����Ŏ󂯎����SE���Đ�����</para>
///<param name="sename"><para>sename:�炻���Ƃ��Ă���se�̗񋓎q</para></param>
///</summary>
void Sound::PlaySe(Se_Name sename,const Object* object) {
	if (CheckSoundMem(se_[static_cast<int>(sename)]) == 1) {
		StopSoundMem(se_[static_cast<int>(sename)]);
	}
	int volume = RegulationSeVolume(sename, object);
	ChangeVolumeSoundMem(volume, se_[static_cast<int>(sename)]);
	PlaySoundMem(se_[static_cast<int>(sename)], DX_PLAYTYPE_BACK);
}

///<summary>
///<para>BGM�̒�~</para>
///<para>����BGM��炵�Ă���ꍇ�A��~������</para>
///</summary>
void Sound::StopBgm() {
	if (bgmname_ != BGM_Name::BGM_None) {
		StopSoundMem(bgm_[static_cast<int>(bgmname_)]);
		bgmname_ = BGM_Name::BGM_None;
	}
}

///<summary>
///<para>SE�̒�~</para>
///<para>���ݖ炵�Ă���SE��S�Ď~�߂�</para>
///</summary>
void Sound::StopSe() {
	for (int i = 0; i != static_cast<int>(Se_Name::Se_None); i++) {
		if (CheckSoundMem(se_[i]) == 1) {
			StopSoundMem(se_[i]);
		}
	}
}
///<summary>
///<para>�I������</para>
///<para>��������ɂ���BGM�̏����폜����</para>
///</summary>
void Sound::Finalize() {
	InitSoundMem();
}