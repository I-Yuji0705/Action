#pragma once

enum class Scene{
	Scene_Title,    //タイトル画面
	Scene_Game,	//ゲーム画面
	Scene_Manual,//マニュアル画面

	Scene_None    //無し
};

//プログラム内のシーンだけ変更するためのインターフェースクラス
class ISceneChanger {
public:
	virtual ~ISceneChanger() = 0;
	virtual void ChangeScene(Scene NextScene) = 0;//指定シーンに変更する
	virtual void ChangeScene(Scene NextScene,const char stagename[30]) = 0;
};