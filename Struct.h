#pragma once
#include <DirectXMath.h>
using namespace DirectX;

typedef struct ConstBufferDataMaterial {
	XMFLOAT4 color;//RGBA
};

typedef struct Vertex {
	XMFLOAT3 pos;//xyz���W
	XMFLOAT2 uv;//uv���W
};