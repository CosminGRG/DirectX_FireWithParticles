////////////////////////////////////////////////////////////////////////////////
// Filename: fireshaderclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _FIRESHADERCLASS_H_
#define _FIRESHADERCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include <fstream>
#include <d3dx11effect.h>
using namespace DirectX;
using namespace std;


////////////////////////////////////////////////////////////////////////////////
// Class name: FireShaderClass
////////////////////////////////////////////////////////////////////////////////
class FireShaderClass
{
public:
	FireShaderClass();
	FireShaderClass(const FireShaderClass&);
	~FireShaderClass();

	bool Initialize(ID3D11Device*, HWND);
	void Shutdown();
	void Render(ID3D11DeviceContext*, int, XMMATRIX, XMMATRIX, XMMATRIX, ID3D11ShaderResourceView*, ID3D11ShaderResourceView*,
		ID3D11ShaderResourceView*, float, XMFLOAT3, XMFLOAT3, XMFLOAT2, XMFLOAT2, XMFLOAT2, float, float);

private:
	bool InitializeShader(ID3D11Device*, HWND, WCHAR*);
	void ShutdownShader();
	void OutputShaderErrorMessage(ID3DBlob*, HWND, WCHAR*);

	void SetShaderParameters(XMMATRIX, XMMATRIX, XMMATRIX, ID3D11ShaderResourceView*, ID3D11ShaderResourceView*,
		ID3D11ShaderResourceView*, float, XMFLOAT3, XMFLOAT3, XMFLOAT2, XMFLOAT2, XMFLOAT2,
		float, float);
	void RenderShader(ID3D11DeviceContext*, int);

private:
	ID3DX11Effect* m_effect;
	ID3DX11EffectTechnique* m_technique;
	ID3D11InputLayout* m_layout;

	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;

	ID3DX11EffectMatrixVariable* m_worldMatrixPtr;
	ID3DX11EffectMatrixVariable* m_viewMatrixPtr;
	ID3DX11EffectMatrixVariable* m_projectionMatrixPtr;

	ID3DX11EffectShaderResourceVariable* m_fireTexturePtr;
	ID3DX11EffectShaderResourceVariable* m_noiseTexturePtr;
	ID3DX11EffectShaderResourceVariable* m_alphaTexturePtr;

	ID3DX11EffectScalarVariable* m_frameTimePtr;
	ID3DX11EffectVectorVariable* m_scrollSpeedsPtr;
	ID3DX11EffectVectorVariable* m_scalesPtr;
	ID3DX11EffectVectorVariable* m_distortion1Ptr;
	ID3DX11EffectVectorVariable* m_distortion2Ptr;
	ID3DX11EffectVectorVariable* m_distortion3Ptr;
	ID3DX11EffectScalarVariable* m_distortionScalePtr;
	ID3DX11EffectScalarVariable* m_distortionBiasPtr;
};

#endif