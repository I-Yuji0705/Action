#pragma once
#include "StageMgr.h"
#include "DxLib.h"
#include <fstream>
#include "Player.h"
#include "Terrain.h"
#include "Gate.h"
#include "Camera.h"
#include "Item.h"
#include "RelayPoint.h"
#include "ClearZone.h"
void StageMgr::CreateStage() { //データからステージの生成
	struct ObjectDeta {
		int object_type_;
		float x_;
		float y_;
		float height_;
		float width_;
		int object_number_;
	};
	std::ifstream infile("Stage/stage2.dat");//データの読込
	ObjectDeta object_deta_;
	int i = 0;
	while (infile >> object_deta_.object_type_ >> object_deta_.x_ >> object_deta_.y_ >> object_deta_.height_ >> object_deta_.width_
		>> object_deta_.object_number_) {
		switch (object_deta_.object_type_) {
		case 0:
			stage_.push_back(new Terrain(object_deta_.x_, object_deta_.y_, object_deta_.height_, object_deta_.width_, object_deta_.object_number_));
			break;
		case 1:
			stage_.push_back(new ClearZone(object_deta_.x_, object_deta_.y_, object_deta_.height_, object_deta_.width_, object_deta_.object_number_));
			break;
		case 2:
			stage_.push_back(new RelayPoint(object_deta_.x_, object_deta_.y_, object_deta_.height_, object_deta_.width_, object_deta_.object_number_));
			break;
		case 3:
			stage_.push_back(new Item(object_deta_.x_, object_deta_.y_, object_deta_.height_, object_deta_.width_, object_deta_.object_number_));
			break;
		case 4:
			stage_.push_back(new Player(object_deta_.x_, object_deta_.y_, object_deta_.height_, object_deta_.width_, object_deta_.object_number_));
			break;
		default:
			break;
		}
		i++;
	}
	infile.close();
}
void StageMgr::CreateStageDeta(){ //ステージの生成とそのデータの保存
	//stage_.push_back(new Terrain());
	//stage_[0]->Set(0.0f, 440.0f, 40.0f, 800.0f, 0);
	//stage_.push_back(new Terrain());
	//stage_[1]->Set(400.0f, 240.0f, 100.0f, 200.0f, 0);
	//stage_.push_back(new Terrain());
	//stage_[2]->Set(1200.0f, 440.0f, 40.0f, 800.0f, 0);
	//stage_.push_back(new Terrain());
	//stage_[3]->Set(1400.0f, 240.0f, 100.0f, 100.0f, 0);
	//stage_.push_back(new Terrain());
	//stage_[4]->Set(1700.0f, 340.0f, 100.0f, 100.0f, 0);
	//stage_.push_back(new Terrain());
	//stage_[5]->Set(2100.0f, 440.0f, 100.0f, 700.0f, 0);
	//stage_.push_back(new Terrain());
	//stage_[6]->Set(2800.0f, 240.0f, 300.0f, 300.0f, 0);
	//stage_.push_back(new Gate());
	//stage_[7]->Set(2900.0f, 140.0f, 100.0f, 100.0f, 0);
	//stage_.push_back(new RelayPoint());
	//stage_[8]->Set(1200.0f, 0.0f, 1000.0f, 10.0f, 0);
	//stage_.push_back(new RelayPoint());
	//stage_[9]->Set(2100.0f, 0.0f, 1000.0f, 10.0f, 0);
	//stage_.push_back(new Item());
	//stage_[10]->Set(500.0f, 340.0f, 100.0f, 100.0f, 0);
	//stage_.push_back(new Item());
	//stage_[11]->Set(1400.0f, 340.0f, 100.0f, 100.0f, 0);
	//stage_.push_back(new Item());
	//stage_[12]->Set(1700.0f, 240.0f, 100.0f, 100.0f, 0);
	//stage_.push_back(new Player());
	//stage_[13]->Set(100.0f, 340.0f, 100.0f, 100.0f, 0);
	stage_.push_back(new Terrain(0.0f, 440.0f, 40.0f, 1500.0f, 0));
	stage_.push_back(new Terrain(200.0f, 340.0f, 50.0f, 50.0f, 0));
	//stage_.push_back(new Terrain(600.0f, 440.0f, 40.0f, 400.0f, 0));
	stage_.push_back(new Terrain(700.0f, 240.0f, 50.0f, 50.0f, 0));
	stage_.push_back(new Terrain(850.0f, 390.0f, 100.0f, 50.0f, 0));
	//stage_.push_back(new Terrain(1050.0f, 440.0f, 100.0f, 350.0f, 0));
	//stage_.push_back(new Terrain(1400.0f, 240.0f, 300.0f, 150.0f, 0));
	stage_.push_back(new ClearZone(1250.0f, 240.0f, 200.0f, 150.0f, 0));
	//stage_.push_back(new RelayPoint(600.0f, 0.0f, 1000.0f, 10.0f, 0));
	//stage_.push_back(new RelayPoint(1050.0f, 0.0f, 1000.0f, 10.0f, 0));
	stage_.push_back(new Item(250.0f, 390.0f, 50.0f, 100.0f, 0));
	stage_.push_back(new Item(700.0f, 390.0f, 50.0f, 50.0f, 0));
	stage_.push_back(new Item(850.0f, 290.0f, 100.0f, 50.0f, 0));
	stage_.push_back(new Item(700.0f, 190.0f, 100.0f, 50.0f, 0));
	stage_.push_back(new Item(850.0f, 240.0f, 100.0f, 50.0f, 0));
	stage_.push_back(new Item(1250.0f, 390.0f, 50.0f, 100.0f, 0));
	stage_.push_back(new Player(50.0f, 340.0f, 50.0f, 50.0f, 0));
	struct ObjectDeta {
		int object_type_;
		float x_;
		float y_;
		float height_;
		float width_;
		int object_number_;
	};
	std::ofstream outfile("Stage/stage2.dat", std::ios_base::out);
	for (auto i : stage_)
	{
		ObjectDeta objectdeta;
		if (typeid(*i) == typeid(Terrain)) {
			objectdeta.object_type_ = 0;
		}
		else if (typeid(*i) == typeid(ClearZone)) {
			objectdeta.object_type_ = 1;
		}
		else if (typeid(*i) == typeid(RelayPoint)) {
			objectdeta.object_type_ = 2;
		}
		else if (typeid(*i) == typeid(Item)) {
			objectdeta.object_type_ = 3;
		}
		else if (typeid(*i) == typeid(Player)) {
			objectdeta.object_type_ = 4;
		}
		else {
			objectdeta.object_type_ = -1;
		}
		objectdeta.x_ = i->x_;
		objectdeta.y_ = i->y_;
		objectdeta.height_ = i->height_;
		objectdeta.width_ = i->width_;
		objectdeta.object_number_ = i->object_number_;
		outfile << objectdeta.object_type_ << " " << objectdeta.x_ << " " << objectdeta.y_ << " " 
			<< objectdeta.height_ << " " << objectdeta.width_ << " "
			<< objectdeta.object_number_ << " " << std::endl;
	}
	outfile.close();
}

//ステージの初期処理
void StageMgr::Initialize(IStateChanger* itstateChanger) {
	CreateStageDeta();
	//CreateStage();
	for (auto i : stage_) {
		i->Initialize(itstateChanger, stage_);
	}
	playerCamera.Initialize(stage_);
}
//ステージの描写処理
void StageMgr::Draw() {
	DrawBox(0, 0, 640, 480, GetColor(127, 255, 212), TRUE);//背景色の設定
	for (auto i : stage_) {
		i->Draw();
	}
}
//ステージの変更処理
void StageMgr::Update() {
	for (auto i : stage_) {
		i->Update();
	}
	playerCamera.Update();
}
//ステージの終了処理
void StageMgr::Finalize() {
	for (auto i : stage_) {
		i->Finalize();
	}
}
//ステージのリトライ処理
void StageMgr::Retry() {
	for (auto i : stage_) {
		i->Retry();
	}
}
StageMgr::StageMgr() {}