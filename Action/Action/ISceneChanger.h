#pragma once

enum Scene{
	Scene_Menu,    //メニュー画面
	Scene_Game,
	Scene_None,    //無し
};

//シーンを変更するためのインターフェイスクラス
class ISceneChanger {
public:
	virtual ~ISceneChanger() = 0;
	virtual void ChangeScene(Scene NextScene) = 0;//指定シーンに変更する
};