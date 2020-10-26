#pragma once
#include "Object.h"

enum  class BGM_Name {//BGM�̎��
	BGM_Menu,//���j���[��ʂ�BGM
	BGM_Game,//�Q�[����ʂ�BGM
	BGM_Manual,//�}�j���A����ʂ�BGM

	BGM_None
};
enum class Se_Name {//SE�̎��
	Se_Hit,//Object�����̃I�u�W�F�N�g�ɐڐG��������Se
	Se_Pick,//Player��Item���E�����ۂ�Se
	Se_Throw,//Player��Item�𓊂����ۂ�Se
	Se_Put,//Player��Item��u�����ۂ�Se
	Se_Cant,//Player��Throw,Put,Pick���s���ۂɁA���̍s�����ł��Ȃ���������Se
	Se_Jump,//Player���W�����v���n�߂�����Se
	Se_Clear,//�Q�[�����N���A�����ۂ�Se(�t�@���t�@�[��)
	Se_SceneChange,//�V�[����ύX���Ă���ۂɖ炷Se

	Se_None
};
class Object;
//�v���O��������BGM��SE���Ǘ�������N���X
class Sound {
private:
	int bgm_[3];//BGM�ǂݍ��ݗp
	int se_[8];//SE�ǂݍ��ݗp
	int sevolume_[8];//SE�̉��ʒ���
	BGM_Name bgmname_; //���ݖ炵�Ă���BGM
	int RegulationSeVolume(Se_Name sename, const Object* object);
public:
	Sound();
	void PlayBgm(BGM_Name bgmname);
	void PlaySe(Se_Name sename);//�I�u�W�F�N�g�̈ʒu�ɂ�炸����炷�֐�
	void PlaySe(Se_Name sename, const Object* object);//�I�u�W�F�N�g�̈ʒu�ɂ���Ė炷���̑傫����ς���֐�
	void StopSe();
	void StopBgm();
	void Finalize();
};