#pragma once
#include "StageMgr.h"
#include "DxLib.h"
#include <fstream>
#include <assert.h>
#include "Player.h"
#include "Terrain.h"
#include "Item.h"
#include "ClearArea.h"
#include "ObjectData.h"
#include <stdio.h>

///<summary>
///<para>�R���X�g���N�^</para>
///<para>�L�����N�^�[�ɓn��Keyboard�N���X�ASound�N���X�AIGameStateChanger�N���X���󂯎��</para>
///<para>�Q�[���̃X�e�[�W�𐶐�����</para>
///<param name= "keyboard"><para>Player�̑���Ɏg�p����N���X�̃|�C���^</para></param>
///<param name= "sound"><para></para>Object����SE�𔭐�������N���X</param>
///<param name= "statechanger"><para>Game��State��ύX����N���X</para></param>
///</summary>
StageMgr::StageMgr(Keyboard* keyboard,Sound* sound,IGameStateChanger* statechanger) {
	stage_ = new std::vector<Object*>;
	collision_ = new Collision(stage_);
	playercamera_ = new Camera(stage_, collision_);
	color_ = { 127, 255, 212 };//�w�i�F�̐ݒ�
	//CreateStageData(keyboard,sound,statechanger, collision_,"test");//�X�e�[�W�̐����ƁA�e�L�X�g�t�@�C���ւ̕ۑ�
	CreateStage(keyboard,sound,statechanger,collision_,"stage2");//�e�L�X�g�t�@�C������̃X�e�[�W�̐���
}

///<summary>
///<para>�X�e�[�W�̐�������</para>
///<para>�����œn���ꂽ�X�e�[�W���̃e�L�X�g�t�@�C������A�X�e�[�W����ǂݍ��݁A�X�e�[�W�𐶐�����</para>
///<para>���̊֐����g�p����ꍇ�ACreateStageData�֐���</para>
///<param name= "keyboard"><para>Player�̑���Ɏg�p����N���X�̃|�C���^</para></param>
///<param name= "sound"><para></para>Object����SE�𔭐�������N���X</param>
///<param name= "statechanger"><para>Game��State��ύX����N���X</para></param>
///<param name= "collision"><para>Object�̐ڐG�����S������N���X</para></param>
///<param name= "stagename"><para>�ǂݍ��ރe�L�X�g�t�@�C���̖��O</para></param>
///</summary>
void StageMgr::CreateStage(Keyboard* keyboard, Sound* sound,IGameStateChanger* statechanger, Collision* collision, const char stagename[30]) {
	char dataplace[41];
	sprintf_s(dataplace, "Stage/%s.txt", stagename);
	std::ifstream infile(dataplace);//�f�[�^�̓Ǎ�
	ObjectData object_Data_;
	int i = 0;
	while (infile >> object_Data_.object_type_ >> object_Data_.x_ >> object_Data_.y_ >> object_Data_.height_ >> object_Data_.width_) {
		switch (object_Data_.object_type_) {
		case 0:
			stage_->push_back((Object*)new Terrain(object_Data_.x_, object_Data_.y_, object_Data_.height_, object_Data_.width_));
			break;
		case 1:
			stage_->push_back((Object*)new ClearArea(sound, collision,color_, object_Data_.x_, object_Data_.y_, object_Data_.height_, object_Data_.width_));
			break;
		case 2:
			stage_->push_back((Object*)new Item(sound,collision,object_Data_.x_, object_Data_.y_, object_Data_.height_, object_Data_.width_));
			break;
		case 3:
			stage_->push_back((Object*)new Player(keyboard,sound, statechanger, collision, object_Data_.x_, object_Data_.y_, object_Data_.height_, object_Data_.width_));
			break;
		default:
			assert(false);
			break;
		}
		i++;
	}
	infile.close();
}

///<summary>
///<para>�X�e�[�W�̐�������</para>
///<para>CreateStage�Ƃ͈Ⴂ�A�v���O���������琶�������X�e�[�W�����e�L�X�g�t�@�C���ɏo�͂���</para>
///<param name= "keyboard"><para>Player�̑���Ɏg�p����N���X�̃|�C���^</para></param>
///<param name= "sound"><para></para>Object����SE�𔭐�������N���X</param>
///<param name= "statechanger"><para>Game��State��ύX����N���X</para></param>
///<param name= "collision"><para>Object�̐ڐG�����S������N���X</para></param>
///<param name= "stagename"><para>�o�͂���e�L�X�g�t�@�C���̖��O</para></param>
///</summary>
void StageMgr::CreateStageData(Keyboard* keyboard, Sound* sound,IGameStateChanger* statechanger, Collision* collision, const char* stagename) {
	stage_->push_back((Object*)new Terrain(0.0f, 440.0f, 40.0f, 1400.0f));
	stage_->push_back((Object*)new Terrain(400.0f, 100.0f, 100.0f, 50.0f));
	stage_->push_back((Object*)new Terrain(800.0f, 100.0f, 100.0f, 50.0f));
	stage_->push_back((Object*)new Terrain(1300.0f, 100.0f, 100.0f, 50.0f));
	//stage_->push_back((Object*)new Terrain(700.0f, 240.0f, 50.0f, 50.0f));
	//stage_->push_back((Object*)new Terrain(850.0f, 390.0f, 100.0f, 50.0f));
	stage_->push_back((Object*)new ClearArea(sound,collision,color_,1250.0f, 240.0f, 200.0f, 150.0f));
	stage_->push_back((Object*)new Item(sound,collision,101.0f, 240.0f, 100.0f, 200.0f));
	stage_->push_back((Object*)new Item(sound, collision, 301.0f, 190.0f, 50.0f, 50.0f));
	stage_->push_back((Object*)new Item(sound, collision, 351.0f, 240.0f, 100.0f, 100.0f));
	stage_->push_back((Object*)new Item(sound, collision, 451.0f, 240.0f, 100.0f, 100.0f));
	//stage_->push_back((Object*)new Item(sound,collision,700.0f, 340.0f, 50.0f, 50.0f));
	//stage_->push_back((Object*)new Item(sound,collision,850.0f, 290.0f, 100.0f, 50.0f));
	//stage_->push_back((Object*)new Item(sound,collision,700.0f, 190.0f, 100.0f, 50.0f));
	//stage_->push_back((Object*)new Item(sound,collision,850.0f, 240.0f, 100.0f, 50.0f));
	//stage_->push_back((Object*)new Item(sound,collision,1250.0f, 390.0f, 50.0f, 100.0f));
	stage_->push_back((Object*)new Player(keyboard, sound,statechanger,collision,50.0f, 340.0f, 50.0f, 50.0f));
	char dataplace[50];
	sprintf_s(dataplace, "Stage/%s.txt", stagename);
	std::ofstream outfile(dataplace, std::ios_base::out);
	for (auto i : *stage_)
	{
		ObjectData objectData;
		if (typeid(*i) == typeid(Terrain)) {
			objectData.object_type_ = 0;
		}
		else if (typeid(*i) == typeid(ClearArea)) {
			objectData.object_type_ = 1;
		}
		else if (typeid(*i) == typeid(Item)) {
			objectData.object_type_ = 2;
		}
		else if (typeid(*i) == typeid(Player)) {
			objectData.object_type_ = 3;
		}
		else {
			objectData.object_type_ = -1;
		}
		objectData.x_ = i->x_;
		objectData.y_ = i->y_;
		objectData.height_ = i->height_;
		objectData.width_ = i->width_;
		outfile << objectData.object_type_ << " " << objectData.x_ << " " << objectData.y_ << " " 
			<< objectData.height_ << " " << objectData.width_  << std::endl;
	}
	outfile.close();
}

///<summary>
///<para>����������</para>
///<para>�X�e�[�W���Object�ƃJ�����̏������������s��</para>
///</summary>
void StageMgr::Initialize() {
	collision_->Initialize();
	for (auto i : *stage_) {
		i->Initialize();
	}
	playercamera_->Initialize();
}

///<summary>
///<para>�`�ʏ���</para>
///<para>�X�e�[�W���Object�̕`�ʏ������s��</para>
///</summary>
void StageMgr::Draw() {
	unsigned int backgroundcolor = GetColor(color_.Red, color_.Green, color_.Blue);
	DrawBox(0, 0, 640, 480, backgroundcolor, TRUE);//�w�i�F�̐ݒ�
	for (auto i : *stage_) {
		i->Draw();
	}
}

///<summary>
///<para>�X�V����</para>
///<para>�X�e�[�W���Object�̍X�V�������s��</para>
///</summary>
void StageMgr::Update() {
	for (auto i : *stage_) {
		i->Update();
	}
	playercamera_->Update();
}

///<summary>
///<para>�I������</para>
///<para>�X�e�[�W���Object�̏I���������s��</para>
///</summary>
void StageMgr::Finalize() {
	for (auto i : *stage_) {
		i->Finalize();
	}
}

///<summary>
///<para>���g���C��������</para>
///<para>�X�e�[�W���Object�̃��g���C�������s��</para>
///</summary>
void StageMgr::Retry() {
	for (auto i : *stage_) {
		i->Retry();
	}
}