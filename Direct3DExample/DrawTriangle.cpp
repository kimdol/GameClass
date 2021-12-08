#include <vector>
#include <fstream>
#include "DrawTriangle.h"


void DrawTriangle::Initialize(HINSTANCE hInstance, int width, int height)
{
	D3DFramework::Initialize(hInstance, width, height);

	InitPipeline();
	InitTriangle();

	CreateTextureFromBMP();
}

void DrawTriangle::Destroy()
{
	mspTextureView.Reset();
	mspTexture.Reset();

	mspVertexBuffer.Reset();
	mspInputLayout.Reset();
	mspPixelShader.Reset();
	mspVertexShader.Reset();

	D3DFramework::Destroy();
}

void DrawTriangle::Render()
{
	UINT offset = 0;
	UINT stride = sizeof(VERTEX);
	mspDeviceContext->IASetVertexBuffers(
		0, 1, mspVertexBuffer.GetAddressOf(), &stride, &offset
	);

	mspDeviceContext->IASetPrimitiveTopology(
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP
	);

	mspDeviceContext->PSSetShaderResources(
		0,
		1,
		mspTextureView.GetAddressOf()
	);

	mspDeviceContext->Draw(4, 0);
}

HRESULT DrawTriangle::CreateTextureFromBMP()
{
	// 1. ���� ����
	std::ifstream file;
	file.open("Data/32.bmp", std::ios::binary);

	BITMAPFILEHEADER bmh;
	BITMAPINFOHEADER bmi;

	// 2. BITMAPFILEHEADER �б�
	file.read(reinterpret_cast<char*>(&bmh), sizeof(BITMAPFILEHEADER));
	// 3. BITMAPINFOGHEADER �б�
	file.read(reinterpret_cast<char*>(&bmi), sizeof(BITMAPINFOHEADER));
	if (bmh.bfType != 0x4D42)
	{
		return E_FAIL;
	}
	if (bmi.biBitCount != 32)
	{
		return E_FAIL;
	}

	std::vector<char> pPixels(bmi.biSizeImage);
	// 4. �ȼ��� �ǳʶٱ�
	file.seekg(bmh.bfOffBits);
	// 5. ��Ʈ�� �б�
	int pitch = bmi.biWidth * (bmi.biBitCount / 8);
	for (int y = bmi.biHeight - 1; y >= 0; --y)
	{
		file.read(&pPixels[y * pitch], pitch);
	}

	file.close();

	// �ؽ��� ����
	CD3D11_TEXTURE2D_DESC td(
		DXGI_FORMAT_B8G8R8A8_UNORM,
		bmi.biWidth,
		bmi.biHeight,
		1,
		1	// 1�常 ����(0�� ������ ����)
	);

	D3D11_SUBRESOURCE_DATA initData;
	initData.pSysMem = (void*)&pPixels[0];
	initData.SysMemPitch = pitch;
	initData.SysMemSlicePitch = 0;

	mspDevice->CreateTexture2D(&td, &initData, mspTexture.ReleaseAndGetAddressOf());

	// View (ShaderResourceView)
	CD3D11_SHADER_RESOURCE_VIEW_DESC srvd(
		D3D11_SRV_DIMENSION_TEXTURE2D,
		td.Format,
		0,
		1
	);
	mspDevice->CreateShaderResourceView(
		mspTexture.Get(),
		&srvd,
		mspTextureView.ReleaseAndGetAddressOf()
	);

	return S_OK;

}

void DrawTriangle::InitTriangle()
{
	VERTEX vertices[]
	{
		{ -0.45f, 0.5f, 0.0f, 0.0f, 0.0f },
		{ 0.45f, 0.5f, 0.0f, 1.0f, 0.0f },
		{ -0.45f, -0.5f, 0.0f, 0.0f, 1.0f },
		{ 0.45f, -0.5f, 0.0f, 1.0f, 1.0f }
		/*{ 0.45f, -0.5f, 0.0f, {0.0f, 1.0f, 1.0f, 1.0f} },
		{ -0.45f, -0.5f, 0.0f, {0.0f, 0.0f, 1.0f, 1.0f} },
		{ 0.45f, 0.5f, 0.0f, {1.0f, 0.0f, 0.0f, 1.0f} },
		{ -0.45f, 0.5f, 0.0f, {1.0f, 0.0f, 0.0f, 1.0f} }*/
	};

	// ���ؽ� ����
	CD3D11_BUFFER_DESC bd(
		sizeof(vertices),
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
		{ "POSITION", 0,  DXGI_FORMAT_R32G32B32_FLOAT,
			0, // Slot Number
			0, // Offset
			D3D11_INPUT_PER_VERTEX_DATA, // Slot Classification
			0 // Instancing
		},
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,
			0,
			12,
			D3D11_INPUT_PER_VERTEX_DATA,
			0
		}
	};

	mspDevice->CreateInputLayout(
		ied,
		2,
		spVS->GetBufferPointer(),
		spVS->GetBufferSize(),
		mspInputLayout.ReleaseAndGetAddressOf()
	);


	// ���������� ����
		// Input Assempler(IA)
		// VS
		// PS
	mspDeviceContext->IASetInputLayout(mspInputLayout.Get());
	mspDeviceContext->VSSetShader(mspVertexShader.Get(), nullptr, 0);
	mspDeviceContext->PSSetShader(mspPixelShader.Get(), nullptr, 0);
}
