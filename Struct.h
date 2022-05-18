#pragma once
#include <DirectXMath.h>
using namespace DirectX;

typedef struct ConstBufferDataMaterial {
	XMFLOAT4 color;//RGBA
};

typedef struct Vertex {
	XMFLOAT3 pos;//xyzç¿ïW
	XMFLOAT2 uv;//uvç¿ïW
};