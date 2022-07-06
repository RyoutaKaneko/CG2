#pragma once
#include <DirectXMath.h>
using namespace DirectX;

typedef struct ConstBufferDataMaterial {
	XMFLOAT4 color;//RGBA
};

typedef struct Vertex {
	XMFLOAT3 pos;//xyz���W
	XMFLOAT3 normal; //�@���x�N�g��
	XMFLOAT2 uv;//uv���W
};

//�萔�o�b�t�@�p�f�[�^�\����(3D�ϊ��s��)
typedef struct ConstBufferDataTransform {
	XMMATRIX mat;	//3D�ϊ��s��
};