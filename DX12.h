#pragma once
#include <d3d12.h>
#include <dxgi1_6.h>
#include <cassert>
#include <vector>
#include <string>
#include "KeyInput.h"
#include "WinInput.h"
#include "struct.h"
#include "Matrix4.h"
#include "Vector3.h"

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")

#include <DirectXMath.h>
using namespace DirectX;

#include <d3dcompiler.h>
#pragma comment(lib, "d3dcompiler.lib")

#include <DirectXTex.h>


class DX12 {
public:
	WinInput* winInput = new WinInput;
	KeyInput* keyInput = new KeyInput;

	BYTE key[256] = {};

	ID3D12Debug* debugController;

	HRESULT result;
	ID3D12Device* device = nullptr;
	IDXGIFactory7* dxgiFactory = nullptr;
	IDXGISwapChain4* swapChain = nullptr;
	ID3D12CommandAllocator* commandAllocator = nullptr;
	ID3D12GraphicsCommandList* commandList = nullptr;
	ID3D12CommandQueue* commandQueue = nullptr;
	ID3D12DescriptorHeap* rtvHeap = nullptr;

	//アダプターの列挙用
	std::vector<IDXGIAdapter4*> adapters;
	//ここに特定の名前を持つアダプターオブジェクトが入る
	IDXGIAdapter4* tmpAdapter = nullptr;

	//コマンドキューの設定
	D3D12_COMMAND_QUEUE_DESC commandQueueDesc{};

	//スワップチェーンの設定
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};

	//デスクリプターヒープの設定
	D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc{};

	//フェンスの生成
	ID3D12Fence* fence = nullptr;
	UINT64 fenceVal = 0;

	D3D12_RESOURCE_BARRIER barrierDesc{};

	ID3DBlob* vsBlob = nullptr; // 頂点シェーダオブジェクト
	ID3DBlob* psBlob = nullptr; // ピクセルシェーダオブジェクト
	ID3DBlob* errorBlob = nullptr; // エラーオブジェクト

	// ルートシグネチャ
	ID3D12RootSignature* rootSignature;
	// パイプランステートの生成
	ID3D12PipelineState* pipelineState = nullptr;

	//バックバッファ
	std::vector<ID3D12Resource*> backBuffers;

	// 頂点データ
	std::vector<Vertex> vertices;
	std::vector<unsigned short> indices;

	// 頂点バッファの設定
	D3D12_HEAP_PROPERTIES heapProp{}; // ヒープ設定
	//インデックスバッファ
	D3D12_INDEX_BUFFER_VIEW ibView{};
	//テクスチャバッファ
	D3D12_HEAP_PROPERTIES textureHeapProp{};//ヒープ設定
	// リソース設定
	D3D12_RESOURCE_DESC resDesc{};
	D3D12_RESOURCE_DESC textureResourceDesc{};
	
	//頂点バッファ
	ID3D12Resource* vertBuff = nullptr;
	Vertex* vertMap = nullptr;

	//テクスチャバッファ
	ID3D12Resource* texBuff = nullptr;

	// 頂点バッファビューの作成
	D3D12_VERTEX_BUFFER_VIEW vbView{};

	// グラフィックスパイプライン設定
	D3D12_GRAPHICS_PIPELINE_STATE_DESC pipelineDesc{};
	//ルートシグネイチャ
	D3D12_ROOT_SIGNATURE_DESC rootSignatureDesc{};
	// ルートシグネチャのシリアライズ
	ID3DBlob* rootSigBlob = nullptr;
	ID3D12Resource* constBuffMaterial = nullptr;
	//デスクリプターヒープ
	D3D12_DESCRIPTOR_HEAP_DESC srvHeapDesc{};
	ID3D12DescriptorHeap* srvHeap = nullptr;
	//シェーダーリソースビュー
	D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc{};//設定構造体
	//デスクリプタレンジ
	D3D12_DESCRIPTOR_RANGE descriptorRange{};
	//テクスチャーサンプラー
	D3D12_STATIC_SAMPLER_DESC samplerDesc{};
	//定数バッファの生成
	ID3D12Resource* constBuffTransform0 = nullptr;
	ConstBufferDataTransform* constMapTransform0 = nullptr;
	ID3D12Resource* constBuffTransform1 = nullptr;
	ConstBufferDataTransform* constMapTransform1 = nullptr;
	//深度バッファの生成
	D3D12_RESOURCE_DESC depthResourceDesc{};
	//深度値用ヒーププロパティ
	D3D12_HEAP_PROPERTIES depthHeapProp{};
	//深度値のクリア設定
	D3D12_CLEAR_VALUE depthClearValue{};
	//深度バッファの生成
	ID3D12Resource* depthBuff = nullptr;
	//深度ビュー用デスクリプターヒープ作成
	D3D12_DESCRIPTOR_HEAP_DESC dsvHeapDesc{};
	ID3D12DescriptorHeap* dsvHeap = nullptr;
	//深度ビュー作成
	D3D12_DEPTH_STENCIL_VIEW_DESC dsvDesc = {};

	//ビュー変換行列
	XMMATRIX matview;
	XMFLOAT3 eye;
	XMFLOAT3 target;
	XMFLOAT3 up;

	//射影変換行列
	XMMATRIX matProjection;
	//ワールド変換行列
	XMMATRIX matWorld;
	//スケーリング
	XMMATRIX matScale;
	//平行移動
	XMMATRIX matTrans;
	//回転
	XMMATRIX matRot;
	//座標
	XMFLOAT3 position;
	//回転角
	XMFLOAT3 rotation;
	//スケーリング倍率
	XMFLOAT3 scale;


	//ワールド変換行列
	XMMATRIX matWorld1;
	//スケーリング
	XMMATRIX matScale1;
	//平行移動
	XMMATRIX matTrans1;
	//回転
	XMMATRIX matRot1;

	float angle;

public:
	DX12();
	~DX12();
	void DXInput();
	void GraphInput();
	void DXUpdate();
	void GraphUpdate();
	void CreateCb();
	void GraphicsMatrix2D(ConstBufferDataTransform& mat);
};