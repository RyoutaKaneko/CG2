#include "KeyInput.h"
#include <assert.h>

KeyInput::KeyInput() {
	directInput = nullptr;
	keyboard = nullptr;
	isPush = false;
}

KeyInput::~KeyInput() {};


void KeyInput::Iniatialize(WNDCLASSEX w, HRESULT result, HWND hwnd) {

	//Direct Inputの初期化
	result = DirectInput8Create(
		w.hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8,
		(void**)&directInput, nullptr
	);
	assert(SUCCEEDED(result));

	//キーボードデバイスの生成
	result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
	assert(SUCCEEDED(result));

	//入力データの形式セット
	result = keyboard->SetDataFormat(&c_dfDIKeyboard);//標準形式
	assert(SUCCEEDED(result));

	//排他制御レベルのセット
	result = keyboard->SetCooperativeLevel(
		hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY
	);
	assert(SUCCEEDED(result));
}

//float TPushSpace(BYTE key[]) {
//	if (key[DIK_SPACE]) {
//		if (isPush == true) {
//			return false;
//		}
//		else {
//			isPush = true;
//			return true;
//		}
//	}
//	else {
//		isPush = false;
//	}
//}