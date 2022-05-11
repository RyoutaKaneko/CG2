#pragma once
#include <Windows.h>

class WinInput {
public:
	//ウィンドウサイズ
	const int window_width = 1280;//横
	const int window_height = 720;//縦
	WNDCLASSEX w{};
	//ウィンドウサイズ{X座標,Y座標,横幅,立幅}
	RECT wrc;
	//ウィンドウオブジェクトの生成
	HWND hwnd;

public:
	WinInput();
	~WinInput();
	void create();
	//ウィンドウプロシージャ
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
};