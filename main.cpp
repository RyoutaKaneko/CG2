#include <Windows.h>
#include "WinInput.h"
#include "KeyInput.h"
#include "DX12.h"


//Windows�A�v���ł̃G���g���[�|�C���g(main�֐�)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//�R���\�[���ł̕����o��
	OutputDebugStringA("Hello,DirectX!!/n");

	MSG msg{};//���b�Z�[�W

	//Windows������
	WinInput* winInput = new WinInput;
	DX12* dx12 = new DX12;

	///-----DirectX�����������@��������-----///
	
	dx12->DXInput();

	///-----DirectX�����������@�����܂�-----///

		KeyInput* keyInput = new KeyInput;
		keyInput->Iniatialize(winInput->w,dx12->result,winInput->hwnd);

	///-----�Q�[�����[�v-----///
	while (true) {
		//���b�Z�[�W������?
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);//�L�[���̓��b�Z�[�W�̏���
			DispatchMessage(&msg);//�v���V�[�W���Ƀ��b�Z�[�W�����
		}
		//�~�{�^���ŏI�����b�Z�[�W��������Q�[�����[�v�𔲂���
		if (msg.message == WM_QUIT) {
			break;
		}

		//�L�[�{�[�h���̎擾�J�n
		keyInput->keyboard->Acquire();
		//�S�L�[�̓��͏�Ԃ��擾����
		BYTE key[256] = {};
		keyInput->keyboard->GetDeviceState(sizeof(key), key);

		//DirectX���t���[�������@��������
		dx12->DXUpdate();

		//DirectX���t���[�������@�����܂�
	}

	//�E�B���h�E�N���X��o�^����
	UnregisterClass(winInput->w.lpszClassName, winInput->w.hInstance);



	delete keyInput;
	delete winInput;


	return 0;
}