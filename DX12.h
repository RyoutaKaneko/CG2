#pragma once
#include <d3d12.h>
#include <dxgi1_6.h>
#include <cassert>
#include <vector>
#include <string>
#include "KeyInput.h"
#include "WinInput.h"
#include "struct.h"

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

	ID3D12Debug* debugController;

	HRESULT result;
	ID3D12Device* device = nullptr;
	IDXGIFactory7* dxgiFactory = nullptr;
	IDXGISwapChain4* swapChain = nullptr;
	ID3D12CommandAllocator* commandAllocator = nullptr;
	ID3D12GraphicsCommandList* commandList = nullptr;
	ID3D12CommandQueue* commandQueue = nullptr;
	ID3D12DescriptorHeap* rtvHeap = nullptr;

	//�A�_�v�^�[�̗񋓗p
	std::vector<IDXGIAdapter4*> adapters;
	//�����ɓ���̖��O�����A�_�v�^�[�I�u�W�F�N�g������
	IDXGIAdapter4* tmpAdapter = nullptr;

	//�R�}���h�L���[�̐ݒ�
	D3D12_COMMAND_QUEUE_DESC commandQueueDesc{};

	//�X���b�v�`�F�[���̐ݒ�
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};

	//�f�X�N���v�^�[�q�[�v�̐ݒ�
	D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc{};

	//�t�F���X�̐���
	ID3D12Fence* fence = nullptr;
	UINT64 fenceVal = 0;

	D3D12_RESOURCE_BARRIER barrierDesc{};

	ID3DBlob* vsBlob = nullptr; // ���_�V�F�[�_�I�u�W�F�N�g
	ID3DBlob* psBlob = nullptr; // �s�N�Z���V�F�[�_�I�u�W�F�N�g
	ID3DBlob* errorBlob = nullptr; // �G���[�I�u�W�F�N�g

	// ���[�g�V�O�l�`��
	ID3D12RootSignature* rootSignature;
	// �p�C�v�����X�e�[�g�̐���
	ID3D12PipelineState* pipelineState = nullptr;

	//�o�b�N�o�b�t�@
	std::vector<ID3D12Resource*> backBuffers;

	// ���_�f�[�^
	std::vector<Vertex> vertices;
	std::vector<unsigned short> indices;

	// ���_�o�b�t�@�̐ݒ�
	D3D12_HEAP_PROPERTIES heapProp{}; // �q�[�v�ݒ�
	//�C���f�b�N�X�o�b�t�@
	D3D12_INDEX_BUFFER_VIEW ibView{};
	//�e�N�X�`���o�b�t�@
	D3D12_HEAP_PROPERTIES textureHeapProp{};//�q�[�v�ݒ�
	// ���\�[�X�ݒ�
	D3D12_RESOURCE_DESC resDesc{};
	D3D12_RESOURCE_DESC textureResourceDesc{};
	
	//���_�o�b�t�@
	ID3D12Resource* vertBuff = nullptr;
	Vertex* vertMap = nullptr;

	//�e�N�X�`���o�b�t�@
	ID3D12Resource* texBuff = nullptr;

	// ���_�o�b�t�@�r���[�̍쐬
	D3D12_VERTEX_BUFFER_VIEW vbView{};

	// �O���t�B�b�N�X�p�C�v���C���ݒ�
	D3D12_GRAPHICS_PIPELINE_STATE_DESC pipelineDesc{};
	//���[�g�V�O�l�C�`��
	D3D12_ROOT_SIGNATURE_DESC rootSignatureDesc{};
	// ���[�g�V�O�l�`���̃V���A���C�Y
	ID3DBlob* rootSigBlob = nullptr;
	ID3D12Resource* constBuffMaterial = nullptr;
	//�f�X�N���v�^�[�q�[�v
	D3D12_DESCRIPTOR_HEAP_DESC srvHeapDesc{};
	ID3D12DescriptorHeap* srvHeap = nullptr;
	//�V�F�[�_�[���\�[�X�r���[
	D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc{};//�ݒ�\����
	//�f�X�N���v�^�����W
	D3D12_DESCRIPTOR_RANGE descriptorRange{};
	//�e�N�X�`���[�T���v���[
	D3D12_STATIC_SAMPLER_DESC samplerDesc{};
	//�萔�o�b�t�@�̐���
	ID3D12Resource* constBuffTransform = nullptr;
	ConstBufferDataTransform* constMapTransform = nullptr;

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