#include "DrawTriangle.h"


void DrawTriangle::Initialize(HINSTANCE hInstance, int width, int height)
{
}

void DrawTriangle::Destroy()
{
}

void DrawTriangle::Render()
{
}

void DrawTriangle::InitTriangle()
{
	VERTEX vertices[]
	{
		{ 0.0f, 0.5f, 0.0f, {1.0f, 0.0f, 0.0f, 1.0f} },
		{ 0.45f, -0.5f, 0.0f, {0.0f, 1.0f, 0.0f, 1.0f} },
		{ -0.45f, -0.5f, 0.0f, {0.0f, 0.0f, 1.0f, 1.0f} }
	};

	// ���ؽ� ����
	CD3D11_BUFFER_DESC bd(
		sizeof(VERTEX) * 3,
		D3D11_BIND_VERTEX_BUFFER,
		D3D11_USAGE_DYNAMIC,	// GPU �б�, CPU ����
		D3D11_CPU_ACCESS_WRITE
	);
	mspDevice->CreateBuffer(
		&bd, nullptr,
		mspVertexBuffer.ReleaseAndGetAddressOf()
	);

	// �׷���ī�� ���ۿ� �����͸� ����(�������� �����϶�)
	D3D11_MAPPED_SUBRESOURCE ms;

	mspDeviceContext->Map(
		mspVertexBuffer.Get(),
		0,
		D3D11_MAP_WRITE_DISCARD,
		0,
		&ms
	);
	memcpy(ms.pData, vertices, sizeof(vertices));
	mspDeviceContext->Unmap(mspVertexBuffer.Get(), 0);

}

void DrawTriangle::InitPipeline()
{
	// ���̴� ������
	Microsoft::WRL::ComPtr<ID3DBlob> spVS; // Binary Large Object(Blob)
	Microsoft::WRL::ComPtr<ID3DBlob> spPS;

	D3DCompileFromFile(
		L"VertexShader.hlsl",
		nullptr, 
		nullptr,
		"main",
		"vs_4_0_level_9_3",
		0, 0,
		spVS.GetAddressOf(),
		nullptr
	);
	D3DCompileFromFile(
		L"PixelShader.hlsl",
		nullptr,
		nullptr,
		"main",
		"ps_4_0_level_9_3",
		0, 0,
		spPS.GetAddressOf(),
		nullptr
	);
	// ���ؽ� ���̴�
	// �ȼ� ���̴�
	mspDevice->CreateVertexShader(
		spVS->GetBufferPointer(),
		spVS->GetBufferSize(),
		nullptr,
		mspVertexShader.ReleaseAndGetAddressOf()
	);
	mspDevice->CreatePixelShader(
		spPS->GetBufferPointer(),
		spPS->GetBufferSize(),
		nullptr,
		mspPixelShader.ReleaseAndGetAddressOf()
	);

	// IA
	D3D11_INPUT_ELEMENT_DESC ied[]
	{
		{ "POSITION", 0,  },
		{}
	};
	// ���������� ����
		// Input Assempler(IA)
		// VS
		// PS
}
