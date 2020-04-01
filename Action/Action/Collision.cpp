#include "Collision.h"
#include <vector>
#include <typeinfo>
#include <cassert>
#include "Player.h"

///<summary>
///Stageのポインタの収得
///</summary>
Collision::Collision(std::vector<Object*>* stage) {
	stage_ = stage;
}


///<summary>
///<para>初期化処理</para>
///<para>Stageのポインタから、ステージ右端と左端のTerrainの収得</para>
///</summary>
void Collision::Initialize() {
	map_left_, map_right_ = nullptr;
	for (auto i : *stage_) {
		if (typeid(*i) == typeid(Terrain)) {
			if (map_left_ == nullptr) map_left_ = i;
			else if (map_left_->Left() > i->Left()) map_left_ = i;
			if (map_right_ == nullptr) map_right_ = i;
			else if (map_right_->Right() < i->Right()) map_right_ = i;
		}
	}
}

///<summary>
///<para>
///対象のオブジェクトが指定した座標上に出る場合、指定したObjectに接触するかを返す
///</para>
///<param name="x"><para>x:対象のObjectが移動するX座標</para></param>
///<param name="y"><para>y:対象のObjectが移動するY座標</para></param>
///<param name="player"><para>player:対象のObjectのポインタ</para></param>
///<param name="object"><para>object:調べるObjectのポインタ</para></param>
///<returns>
///<para>true:Objectが接触する</para>
///<para>false:Objectが接触しない</para>
///</returns>
///</summary>
bool Collision::Check(float x, float y,const Object* player, const Object* object) {
	bool check = false;
	if (Check(x,y,x + player->GetWidth(), y + player->GetHeight(),object))
		check = true;
	return check;
}

///<summary>
///<para>
///指定した右上の座標と左下の座標を対角線とする四角形の中に、指定したObjectが接触しているかを返す
///</para>
///<param name="x1"><para>x1:調べる範囲の左上のX座標</para></param>
///<param name="y1"><para>y1:調べる範囲の左上のY座標</para></param>
///<param name="x2"><para>x2:調べる範囲の右下のX座標</para></param>
///<param name="y2"><para>y2:調べる範囲の右下のY座標</para></param>
///<param name="object"><para>object:対象のObjectのポインタ</para></param>
///<returns>
///<para>true:Objectが接触する</para>
///<para>false:Objectが接触しない</para>
///</returns>
///</summary>
bool Collision::Check(float x1, float y1, float x2, float y2,
	const Object* object) {
	bool check = false;
	if (object->quality_ && 
		y1  < object->Base() && object->Top() < y2 &&
		x1 < object->Right() && object->Left() < x2)
		check = true;
	return check;
}

///<summary>
///<para>接触する二つのオブジェクトが接触するまで移動するObjectが動ける数値</para>
///<param name="target"><para>target:playerが接触するObjectのポインタ</para></param>
///<param name="player"><para>player:移動するObjectのポインタ</para></param>
///<param name="check"><para>check:HitCheckXまたはHitCheckY内のcheck変数</para></param>
///<returns>
///<para>二つのオブジェクトが接触するまでplayerが動ける数値</para>
///</returns>
///</summary>
float Collision::ObjectDistance(const Object* target, const Object* player, int check) {
	float distance;
	switch (check)
	{
	case 1://objectの左側に接触
		distance = target->Left() - player->Right();
		break;
	case 2://objectの右側に接触
		distance = target->Right() - player->Left();
		break;
	case 3://objectの上側に接触
		distance = target->Top() - player->Base();
		break;
	case 4://objectの下側に接触
		distance = target->Base() - player->Top();
		break;
	default:
		assert(false);
		break;
	}
	return distance;
}

///<summary>
///<para>対象のObjectが画面端まで接触するまで動ける数値を返す</para>
///<param name="player"><para>player:移動するObjectのポインタ</para></param>
///<param name="check"><para>check:MapCheck内のcheck変数</para></param>
///<returns>
///<para>Objectがステージ左端または右端まに接触するまで動ける数値</para>
///</returns>
///</summary>
float Collision::MapDistance(const Object* player, int check) {
	float distance;
	switch (check) {
	case 1://ステージの右端に接触する
		distance = map_right_->Right() - player->Right();
		break;
	case 2://ステージの左端に接触する
		distance =map_left_->Left() - player->Left();
		break;
	default:
		assert(false);
		break;
	}
	return distance;
}

///<summary>
///<para>
///対象のオブジェクトが指定した座標上に出る場合、指定したObjectに接触するかを返す
///</para>
///<param name="x"><para>x:対象のObjectが移動するX座標</para></param>
///<param name="y"><para>y:対象のObjectが移動するY座標</para></param>
///<param name="player"><para>player:対象のObjectのポインタ</para></param>
///<returns>
///<para>true:Objectが接触する</para>
///<para>false:Objectが接触しない</para>
///</returns>
///</summary>
bool Collision::Check(float x, float y, const Object* player) {
	bool check = false; 
	for (auto i : *stage_) {
		if (i != player && i->quality_ &&
			Check(x , y , player, i)) {
			check = true;
			break;
		}
	}
	return check;
}

///<summary>
///<para>指定したX地点に移動した場合、ステージの外に出るかどうか、</para>
///<para>出る場合、現在の位置から接触するまで動ける数値を返す</para>
///<param name="num"><para>num:移動しようとしているX地点</para></param>
///<param name="player"><para>player:移動するObjectのポインタ</para></param>
///<returns>
///<para>int:Objectがステージ左端または右端に接触するか</para>
///<para>0:接触しない</para>
///<para>1:右端に接触する</para>
///<para>2:左端に接触する</para>
///<para>float:接触する場合、接触するまで動ける数値</para>
///<para>999.0f:接触しない</para>
///<para>999.0f以外:接触するまで動ける数値</para>
///</returns>
///</summary>
std::tuple<int,float> Collision::MapCheck(float num,const Object* player) {
	int check = 0;
	float distance = 999.0f;
	if (num + player->GetWidth() > map_right_->Right()) check = 1;
	else if (num < map_left_->Left()) check = 2;
	if(check != 0)distance = MapDistance(player, check);
	return std::forward_as_tuple(check, distance);
}

///<summary>
///<para>引数の座標地点にObjectがあるかどうか、あった場合はy座標からどの程度の高さかを返す</para>
///<para>あった場合はy座標からどの程度の高さかを返す</para>
///<param name="x"><para>x:調べる座標のX座標</para></param>
///<param name="y"><para>y:調べる座標のY座標</para></param>
///<param name="player"><para>player:移動するObjectのポインタ</para></param>
///<returns>
///<para>Objectが存在した場合、yからどの程度の高さか</para>
///<para>0:接触したObjectが存在しなかった</para>
///<para>0以外:接触したObjectのy地点からの高さ</para>
///</returns>
///</summary>
int Collision::PointCheck(float x, float y,const Object *player) {
	int length_y = 0;
	Object* object = nullptr;
	for (auto i : *stage_) {
		if (i != player && i->quality_ && 
			i->Left() <= x && x <= i->Right() &&
			i->Top() <= y && y <= i->Base()) {
			object = i;//長さを収得するObjectをセット
			break;
		}
	}
	if (object != nullptr) {
		length_y = (int)(object->Base() - y);//y地点からObjectの底辺までの距離
	}
	return length_y;
}

///<summary>
///<para>選択したObjectの内部すべてに他のObjectが存在するかを返す関数</para>
///<param name="area"><para>area:調べる対象Objectのポインタ</para></param>
///<returns>
///<para>true:area内部全てが他のOjbectで満たされている</para>
///<para>false:area内部全てが他のOjbectで満たされていない</para>
///</returns>
///</summary>
bool Collision::AreaFullCheck(const Object* area) {
	bool check = true;
	const int kPermissibleLength = 10;//多少外側からずれてても大丈夫な長さ
	const int kPermissibleGap = 1;//エリア内部で空いてても大丈夫な隙間の大きさ
	int gap = 0;
	for (int i = (int)area->Left() + kPermissibleLength; i < (int)area->Right() - kPermissibleLength; i++) {
		for (int j = (int)area->Top() + kPermissibleLength; j < (int)area->Base() - kPermissibleLength; j++) {
			if (PointCheck((float)i, (float)j, area) == 0) {
				if (gap >= kPermissibleGap) {
					check = false;
					break;
				}
				else
					gap++;
			}
			else {
				j += PointCheck((float)i, (float)j, area);
				gap = 0;
			}
		}
	}
	return check;
}

///<summary>
///<para>指定した右上の座標と左下の座標を対角線とする四角形の中に存在する他のObject一つを返す</para>
///<param name="target"><para>target:戻り値の格納先</para></param>
///<param name="x1"><para>x1:調べる範囲の左上のX座標</para></param>
///<param name="y1"><para>y1:調べる範囲の左上のY座標</para></param>
///<param name="x2"><para>x2:調べる範囲の右下のX座標</para></param>
///<param name="y2"><para>y2:調べる範囲の右下のY座標</para></param>
///<param name="player"><para>player:候補から外すObjectのポインタ</para></param>
///<returns>
///<para>nullptr:</para>
///<para>指定した範囲内にObjectが存在しない</para>
///<para>nullptr以外:</para>
///<para>指定した範囲の中にに存在し、</para>
///<para>playerに近かったObjectのポインタ</para>
///</returns>
///</summary>
Object* Collision::AreaCheck(Object* target, float x1, float y1, float x2, float y2, const Object* player) {
	target = nullptr;
	for (auto i : *stage_) {//ステージ上のオブジェクトから検索
		if (i != player && Check(x1,y1,x2,y2,i) &&//
			(target == nullptr ||
				abs(player->Center_X() - i->Center_X()) <= abs(player->Center_X() - target->Center_X()) &&
				(i->Base() < target->Base()))) {
			target = i;//持ち上げる対象を設定する
		}
	}
	return target;
}

///<summary>ステージの左端にある地形を返す
///<param name="target">target:戻り値の格納先</param>
///<returns>
///<para>ステージ右端のTerrainのポインタ</para>
///</returns>
///</summary>
Object* Collision::GetMapLeft(Object* target) {
	target = map_left_;
	return target;
}

///<summary>ステージの左端にある地形を返す
///<param name="target"><para>target:戻り値の格納先</para></param>
///<returns>
///<para>ステージ右端のTerrainのポインタ</para>
///</returns>
///</summary>
Object* Collision::GetMapRight(Object* target) {
	target = map_right_;
	return target;
}

///<summary>ステージ上にあるPlayer全てを返す
///<returns>
///<para>ステージ上にあるPlayer全て</para>
///</returns>
///</summary>
std::vector<Object*> Collision::GetPlayer() {
	std::vector<Object*> players;
	for (auto i: *stage_) {
		if (typeid(*i) == typeid(Player)) {
			players.push_back(i);
		}
	}
	return players;
}

///<summary>
///<para>対象のObjectのX軸に数値を追加した結果、他のObjectに接触するか、</para>
///<para>した場合にはどの部分に接触したか、接触したObject、</para>
///<para>接触したObjectのうち、一番近いObjectと接触するまで対象のObjectが動ける数値を返す</para>
///<param name="num"><para>num:対象のObjectのY座標に追加する予定の数値</para></param>
///<param name="player"><para>player:対象のObjectのポインタ</para></param>
///<returns>
///<para>int:Objectに接触したか、した場合はどの部分に接触したか</para>
///<para>0:接触しない</para>
///<para>1:objectの左側に接触</para>
///<para>2:objectの右側に接触</para>
///<para>float:numに対して、実際にplayerがX軸に追加できる値</para>
///<para>std::vector:接触した全てのObjectのポインタ</para>
///</returns>
///</summary>
std::tuple<int,float, std::vector<Object *>> 
	Collision::HitCheckX(float num, const Object* player) {
	int check = 0;
	float distance = 999.0f;//999.0f:初期値
	std::vector<Object*> hitobjects;
	for (auto i : *stage_) {
		if (i != player && i->quality_ &&
			Check(player->Left() + num, player->Top(), player, i)) {
			hitobjects.push_back(i);
			if (num > 0) check = 1;//地形の上側から衝突した時
			else check = 2;//地形の下から衝突した時
			if (check != 0 && std::abs(distance) > std::abs(ObjectDistance(i, player, check)))
				distance = ObjectDistance(i, player, check);
		}
	}
	return std::forward_as_tuple(check, distance, hitobjects);
}


///<summary>
///<para>対象のObjectのY軸に数値を追加した結果、他のObjectに接触するか、</para>
///<para>した場合にはどの部分に接触したか、接触したObject、</para>
///<para>接触したObjectのうち、一番近いObjectと接触するまで対象のObjectが動ける数値を返す</para>
///<param name="num"><para>num:対象のObjectのY座標に追加する予定の数値</para></param>
///<param name="player"><para>player:対象のObjectのポインタ</para></param>
///<returns>
///<para>int:Objectに接触したか、した場合はどの部分に接触したか</para>
///<para>0:接触しない</para>
///<para>3:objectの上側に接触</para>
///<para>4:objectの下側に接触</para>
///<para>float:numに対して、実際にplayerがY軸に追加できる値</para>
///<para>std::vector:接触した全てのObjectのポインタ</para>
///</returns>
///</summary>
std::tuple<int, float, std::vector<Object *>>
Collision::HitCheckY(float num, const Object* player) {
	int check = 0;
	float distance = 999.0f;//999.0f:初期値
	std::vector<Object*> hitobjects;
	for (auto i : *stage_) {
		if (i != player && i->quality_ &&
			Check(player->Left(), player->Top() + num, player, i)) {
			hitobjects.push_back(i);
			if (num > 0) check = 3;//地形の上側から衝突した時
			else check = 4;//地形の下から衝突した時
			if (check != 0 && std::abs(distance) > std::abs(ObjectDistance(i, player, check)))
				distance = ObjectDistance(i, player, check);
		}
	}
	return std::forward_as_tuple(check, distance, hitobjects);
}