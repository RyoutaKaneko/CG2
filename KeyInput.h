#pragma once
#define DIRECTINPUT_VERSION  0x0800 //DirectInputのバージョン指定
#include <dinput.h>
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")

class KeyInput {
public:
	IDirectInput8* directInput;
	IDirectInputDevice8* keyboard;

public:
	KeyInput();
	~KeyInput();
	void Iniatialize(WNDCLASSEX w,HRESULT result,HWND hwnd);
};