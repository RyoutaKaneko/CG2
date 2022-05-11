#include <Windows.h>
#include "WinInput.h"
#include "KeyInput.h"
#include "DX12.h"


//Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//コンソールでの文字出力
	OutputDebugStringA("Hello,DirectX!!/n");

	MSG msg{};//メッセージ

	//Windows初期化
	WinInput* winInput = new WinInput;
	DX12* dx12 = new DX12;

	///-----DirectX初期化処理　ここから-----///
	
	dx12->DXInput();

	///-----DirectX初期化処理　ここまで-----///

		KeyInput* keyInput = new KeyInput;
		keyInput->Iniatialize(winInput->w,dx12->result,winInput->hwnd);

	///-----ゲームループ-----///
	while (true) {
		//メッセージがある?
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);//キー入力メッセージの処理
			DispatchMessage(&msg);//プロシージャにメッセージを作る
		}
		//×ボタンで終了メッセージが来たらゲームループを抜ける
		if (msg.message == WM_QUIT) {
			break;
		}

		//キーボード情報の取得開始
		keyInput->keyboard->Acquire();
		//全キーの入力状態を取得する
		BYTE key[256] = {};
		keyInput->keyboard->GetDeviceState(sizeof(key), key);

		//DirectX毎フレーム処理　ここから
		dx12->DXUpdate();

		//DirectX毎フレーム処理　ここまで
	}

	//ウィンドウクラスを登録解除
	UnregisterClass(winInput->w.lpszClassName, winInput->w.hInstance);



	delete keyInput;
	delete winInput;


	return 0;
}