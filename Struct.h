#pragma once
#include <DirectXMath.h>
using namespace DirectX;

typedef struct ConstBufferDataMaterial {
	XMFLOAT4 color;//RGBA
};

typedef struct Vertex {
	XMFLOAT3 pos;//xyz座標
	XMFLOAT3 normal; //法線ベクトル
	XMFLOAT2 uv;//uv座標
};

//定数バッファ用データ構造体(3D変換行列)
typedef struct ConstBufferDataTransform {
	XMMATRIX mat;	//3D変換行列
};