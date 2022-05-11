#pragma once
#include <Windows.h>

class WinInput {
public:
	//�E�B���h�E�T�C�Y
	const int window_width = 1280;//��
	const int window_height = 720;//�c
	WNDCLASSEX w{};
	//�E�B���h�E�T�C�Y{X���W,Y���W,����,����}
	RECT wrc;
	//�E�B���h�E�I�u�W�F�N�g�̐���
	HWND hwnd;

public:
	WinInput();
	~WinInput();
	void create();
	//�E�B���h�E�v���V�[�W��
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
};