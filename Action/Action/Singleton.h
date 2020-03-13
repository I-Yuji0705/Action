#pragma once
//このヘッダーファイルはSingleton パターンの抽象クラス。
template <typename C> class Singleton {
protected:
	Singleton() {} // コンストラクタを private に置く。
	Singleton(const Singleton&); // コピーコンストラクタも private に置き、定義しない。
	Singleton& operator=(const Singleton&); // コピー代入演算子も private に置き、定義しない。
	~Singleton() {} // デストラクタを private に置く。
public:
	static C* getInstance();
};

template<typename C>inline C* Singleton<C>::getInstance() {
	static C inst; // private なコンストラクタを呼び出す。
	return &inst;
}