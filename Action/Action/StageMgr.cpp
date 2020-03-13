#pragma once
#include "StageMgr.h"
#include "DxLib.h"
#include <fstream>
#include <assert.h>
#include "Player.h"
#include "Terrain.h"
#include "Camera.h"
#include "Item.h"
#include "ClearArea.h"
#include "ObjectDeta.h"
#include <stdio.h>

StageMgr::StageMgr(Sound* sound) {
	sound_ = sound;
}
//------------------------
//データからステージの生成
void StageMgr::CreateStage(const char* stagename) {
	char dataplace[50];
	sprintf_s(dataplace, "Stage/%s.txt", stagename);
	//std::ifstream infile("Stage/stage3.dat");//データの読込
	std::ifstream infile(dataplace);//データの読込
	ObjectDeta object_deta_;
	int i = 0;
	while (infile >> object_deta_.object_type_ >> object_deta_.x_ >> object_deta_.y_ >> object_deta_.height_ >> object_deta_.width_) {
		switch (object_deta_.object_type_) {
		case 0:
			stage_.push_back((Object*)new Terrain(object_deta_.x_, object_deta_.y_, object_deta_.height_, object_deta_.width_, sound_));
			break;
		case 1:
			stage_.push_back((Object*)new ClearArea(object_deta_.x_, object_deta_.y_, object_deta_.height_, object_deta_.width_, sound_));
			break;
		case 2:
			stage_.push_back((Object*)new Item(object_deta_.x_, object_deta_.y_, object_deta_.height_, object_deta_.width_, sound_));
			break;
		case 3:
			stage_.push_back((Object*)new Player(object_deta_.x_, object_deta_.y_, object_deta_.height_, object_deta_.width_, sound_));
			break;
		default:
			assert(false);
			break;
		}
		i++;
	}
	infile.close();
}
//--------------------------------
//ステージの生成とそのデータの保存
void StageMgr::CreateStageDeta(const char* stagename){
	stage_.push_back((Object*)new Terrain(0.0f, 440.0f, 40.0f, 1500.0f, sound_));
	stage_.push_back((Object*)new Terrain(200.0f, 340.0f, 50.0f, 50.0f, sound_));
	stage_.push_back((Object*)new Terrain(700.0f, 240.0f, 50.0f, 50.0f, sound_));
	stage_.push_back((Object*)new Terrain(850.0f, 390.0f, 100.0f, 50.0f, sound_));
	stage_.push_back((Object*)new ClearArea(1250.0f, 240.0f, 200.0f, 150.0f, sound_));
	stage_.push_back((Object*)new Item(250.0f, 390.0f, 50.0f, 100.0f, sound_));
	stage_.push_back((Object*)new Item(700.0f, 390.0f, 50.0f, 50.0f, sound_));
	stage_.push_back((Object*)new Item(700.0f, 340.0f, 50.0f, 50.0f, sound_));
	stage_.push_back((Object*)new Item(850.0f, 290.0f, 100.0f, 50.0f, sound_));
	stage_.push_back((Object*)new Item(700.0f, 190.0f, 100.0f, 50.0f, sound_));
	stage_.push_back((Object*)new Item(850.0f, 240.0f, 100.0f, 50.0f, sound_));
	stage_.push_back((Object*)new Item(1250.0f, 390.0f, 50.0f, 100.0f, sound_));
	stage_.push_back((Object*)new Player(50.0f, 340.0f, 50.0f, 50.0f, sound_));
	char dataplace[50];
	sprintf_s(dataplace, "Stage/%s.txt", stagename);
	std::ofstream outfile(dataplace, std::ios_base::out);
	for (auto i : stage_)
	{
		ObjectDeta objectdeta;
		if (typeid(*i) == typeid(Terrain)) {
			objectdeta.object_type_ = 0;
		}
		else if (typeid(*i) == typeid(ClearArea)) {
			objectdeta.object_type_ = 1;
		}
		else if (typeid(*i) == typeid(Item)) {
			objectdeta.object_type_ = 2;
		}
		else if (typeid(*i) == typeid(Player)) {
			objectdeta.object_type_ = 3;
		}
		else {
			objectdeta.object_type_ = -1;
		}
		objectdeta.x_ = i->x_;
		objectdeta.y_ = i->y_;
		objectdeta.height_ = i->height_;
		objectdeta.width_ = i->width_;
		outfile << objectdeta.object_type_ << " " << objectdeta.x_ << " " << objectdeta.y_ << " " 
			<< objectdeta.height_ << " " << objectdeta.width_  << std::endl;
	}
	outfile.close();
}

//-------------------
//ステージの初期処理
void StageMgr::Initialize(IGameStateChanger* itstateChanger) {
	CreateStageDeta("stage2");
	//CreateStage("stage2");
	collision_ = new Collision(stage_);
	for (auto i : stage_) {
		i->Initialize(itstateChanger, collision_);
	}
	playercamera_.Initialize(stage_,collision_);
}
//-------------------
//ステージの描写処理
void StageMgr::Draw() {
	DrawBox(0, 0, 640, 480, GetColor(127, 255, 212), TRUE);//背景色の設定
	for (auto i : stage_) {
		i->Draw();
	}
}
//-------------------
//ステージの変更処理
void StageMgr::Update() {
	for (auto i : stage_) {
		i->Update();
	}
	playercamera_.Update();
}
//-------------------
//ステージの終了処理
void StageMgr::Finalize() {
	for (auto i : stage_) {
		i->Finalize();
	}
}
//----------------------
//ステージのリトライ処理
void StageMgr::Retry() {
	for (auto i : stage_) {
		i->Retry();
	}
}