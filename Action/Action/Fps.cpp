#include "Fps.h"
#include "DxLib.h"
#define FPS 60
Fps::Fps(){
	startTime = 0;
	count = 0;
}
int Fps::Update() {
	try {
		if (count == 0) { 
			startTime = GetNowCount(); 
		}
		if (count == FPS){
			count = 0;
			startTime = GetNowCount();
		}
		int tookTime = GetNowCount() - startTime;
		int waitTime = count * 1000 / FPS - tookTime;
		if (waitTime > 0) {
			Sleep(waitTime);
		}
		return 0;
	}
	catch (...) {
		return -1;
	}
}