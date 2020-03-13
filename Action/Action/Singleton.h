#pragma once
//���̃w�b�_�[�t�@�C����Singleton �p�^�[���̒��ۃN���X�B
template <typename C> class Singleton {
protected:
	Singleton() {} // �R���X�g���N�^�� private �ɒu���B
	Singleton(const Singleton&); // �R�s�[�R���X�g���N�^�� private �ɒu���A��`���Ȃ��B
	Singleton& operator=(const Singleton&); // �R�s�[������Z�q�� private �ɒu���A��`���Ȃ��B
	~Singleton() {} // �f�X�g���N�^�� private �ɒu���B
public:
	static C* getInstance();
};

template<typename C>inline C* Singleton<C>::getInstance() {
	static C inst; // private �ȃR���X�g���N�^���Ăяo���B
	return &inst;
}