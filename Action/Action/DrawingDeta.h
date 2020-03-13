#pragma once

//€–Ú‚â‰æ‘œ‚ğ•\¦‚·‚é’ŠÛƒNƒ‰ƒX
class DrawingDeta {
public:
	virtual void Draw() = 0;
	virtual void ChangeColor(unsigned int color) {};
	virtual void Finalize() {};
};