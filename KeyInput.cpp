#include "KeyInput.h"
#include <assert.h>

KeyInput::KeyInput() {
	directInput = nullptr;
	keyboard = nullptr;
	isPush = false;
}

KeyInput::~KeyInput() {};


void KeyInput::Iniatialize(WNDCLASSEX w, HRESULT result, HWND hwnd) {

	//Direct Input�̏�����
	result = DirectInput8Create(
		w.hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8,
		(void**)&directInput, nullptr
	);
	assert(SUCCEEDED(result));

	//�L�[�{�[�h�f�o�C�X�̐���
	result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
	assert(SUCCEEDED(result));

	//���̓f�[�^�̌`���Z�b�g
	result = keyboard->SetDataFormat(&c_dfDIKeyboard);//�W���`��
	assert(SUCCEEDED(result));

	//�r�����䃌�x���̃Z�b�g
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