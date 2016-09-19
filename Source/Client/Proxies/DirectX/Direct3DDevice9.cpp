#include <stdafx.hpp>
#include <Proxies/DirectX/Direct3DDevice9.hpp>

Proxies::Direct3DDevice9::Direct3DDevice9(IDirect3DDevice9* Original)
	: m_original(Original)
{
}

ULONG Proxies::Direct3DDevice9::AddRef()
{
	return m_original->AddRef();
}

HRESULT Proxies::Direct3DDevice9::BeginScene()
{
	return m_original->BeginScene();
}

HRESULT Proxies::Direct3DDevice9::BeginStateBlock()
{
	return m_original->BeginStateBlock();
}

HRESULT Proxies::Direct3DDevice9::Clear(DWORD Count, const D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil)
{
	return m_original->Clear(Count, pRects, Flags, Color, Z, Stencil);
}

HRESULT Proxies::Direct3DDevice9::ColorFill(IDirect3DSurface9* pSurface, const RECT* pRect, D3DCOLOR color)
{
	return m_original->ColorFill(pSurface, pRect, color);
}

HRESULT Proxies::Direct3DDevice9::CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DSwapChain9** ppSwapChain)
{
	return m_original->CreateAdditionalSwapChain(pPresentationParameters, ppSwapChain);
}

HRESULT Proxies::Direct3DDevice9::CreateCubeTexture(UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle)
{
	return m_original->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle);
}

HRESULT Proxies::Direct3DDevice9::CreateDepthStencilSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
	return m_original->CreateDepthStencilSurface(Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle);
}

HRESULT Proxies::Direct3DDevice9::CreateIndexBuffer(UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle)
{
	return m_original->CreateIndexBuffer(Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle);
}

HRESULT Proxies::Direct3DDevice9::CreateOffscreenPlainSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
	return m_original->CreateOffscreenPlainSurface(Width, Height, Format, Pool, ppSurface, pSharedHandle);
}

HRESULT Proxies::Direct3DDevice9::CreatePixelShader(const DWORD* pFunction, IDirect3DPixelShader9** ppShader)
{
	return m_original->CreatePixelShader(pFunction, ppShader);
}

HRESULT Proxies::Direct3DDevice9::CreateQuery(D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery)
{
	return m_original->CreateQuery(Type, ppQuery);
}

HRESULT Proxies::Direct3DDevice9::CreateRenderTarget(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
	return m_original->CreateRenderTarget(Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle);
}

HRESULT Proxies::Direct3DDevice9::CreateStateBlock(D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9** ppSB)
{
	return m_original->CreateStateBlock(Type, ppSB);
}

HRESULT Proxies::Direct3DDevice9::CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle)
{
	return m_original->CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle);
}

HRESULT Proxies::Direct3DDevice9::CreateVertexBuffer(UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle)
{
	return m_original->CreateVertexBuffer(Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle);
}

HRESULT Proxies::Direct3DDevice9::CreateVertexDeclaration(const D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl)
{
	return m_original->CreateVertexDeclaration(pVertexElements, ppDecl);
}

HRESULT Proxies::Direct3DDevice9::CreateVertexShader(const DWORD* pFunction, IDirect3DVertexShader9** ppShader)
{
	return m_original->CreateVertexShader(pFunction, ppShader);
}

HRESULT Proxies::Direct3DDevice9::CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle)
{
	return m_original->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle);
}

HRESULT Proxies::Direct3DDevice9::DeletePatch(UINT Handle)
{
	return m_original->DeletePatch(Handle);
}

HRESULT Proxies::Direct3DDevice9::DrawIndexedPrimitive(D3DPRIMITIVETYPE Type, INT BaseVertexIndex, UINT MinIndex, UINT NumVertices, UINT StartIndex, UINT PrimitiveCount)
{
	return m_original->DrawIndexedPrimitive(Type, BaseVertexIndex, MinIndex, NumVertices, StartIndex, PrimitiveCount);
}

HRESULT Proxies::Direct3DDevice9::DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, const void* pIndexData, D3DFORMAT IndexDataFormat, const void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
	return m_original->DrawIndexedPrimitiveUP(PrimitiveType, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT Proxies::Direct3DDevice9::DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
	return m_original->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);
}

HRESULT Proxies::Direct3DDevice9::DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, const void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
	return m_original->DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT Proxies::Direct3DDevice9::DrawRectPatch(UINT Handle, const float* pNumSegs, const D3DRECTPATCH_INFO* pRectPatchInfo)
{
	return m_original->DrawRectPatch(Handle, pNumSegs, pRectPatchInfo);
}

HRESULT Proxies::Direct3DDevice9::DrawTriPatch(UINT Handle, const float* pNumSegs, const D3DTRIPATCH_INFO* pTriPatchInfo)
{
	return m_original->DrawTriPatch(Handle, pNumSegs, pTriPatchInfo);
}

HRESULT Proxies::Direct3DDevice9::EndScene()
{
	return m_original->EndScene();
}

HRESULT Proxies::Direct3DDevice9::EndStateBlock(IDirect3DStateBlock9** ppSB)
{
	return m_original->EndStateBlock(ppSB);
}

HRESULT Proxies::Direct3DDevice9::EvictManagedResources()
{
	return m_original->EvictManagedResources();
}

UINT Proxies::Direct3DDevice9::GetAvailableTextureMem()
{
	return m_original->GetAvailableTextureMem();
}

HRESULT Proxies::Direct3DDevice9::GetBackBuffer(UINT iSwapChain, UINT BackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer)
{
	return m_original->GetBackBuffer(iSwapChain, BackBuffer, Type, ppBackBuffer);
}

HRESULT Proxies::Direct3DDevice9::GetClipPlane(DWORD Index, float* pPlane)
{
	return m_original->GetClipPlane(Index, pPlane);
}

HRESULT Proxies::Direct3DDevice9::GetClipStatus(D3DCLIPSTATUS9* pClipStatus)
{
	return m_original->GetClipStatus(pClipStatus);
}

HRESULT Proxies::Direct3DDevice9::GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS* pParameters)
{
	return m_original->GetCreationParameters(pParameters);
}

HRESULT Proxies::Direct3DDevice9::GetCurrentTexturePalette(UINT* pPaletteNumber)
{
	return m_original->GetCurrentTexturePalette(pPaletteNumber);
}

HRESULT Proxies::Direct3DDevice9::GetDepthStencilSurface(IDirect3DSurface9** ppZStencilSurface)
{
	return m_original->GetDepthStencilSurface(ppZStencilSurface);
}

HRESULT Proxies::Direct3DDevice9::GetDeviceCaps(D3DCAPS9* pCaps)
{
	return m_original->GetDeviceCaps(pCaps);
}

HRESULT Proxies::Direct3DDevice9::GetDirect3D(IDirect3D9** ppD3D9)
{
	return m_original->GetDirect3D(ppD3D9);
}

HRESULT Proxies::Direct3DDevice9::GetDisplayMode(UINT iSwapChain, D3DDISPLAYMODE* pMode)
{
	return m_original->GetDisplayMode(iSwapChain, pMode);
}

HRESULT Proxies::Direct3DDevice9::GetFrontBufferData(UINT iSwapChain, IDirect3DSurface9* pDestSurface)
{
	return m_original->GetFrontBufferData(iSwapChain, pDestSurface);
}

HRESULT Proxies::Direct3DDevice9::GetFVF(DWORD* pFVF)
{
	return m_original->GetFVF(pFVF);
}

void Proxies::Direct3DDevice9::GetGammaRamp(UINT iSwapChain, D3DGAMMARAMP* pRamp)
{
	return m_original->GetGammaRamp(iSwapChain, pRamp);
}

HRESULT Proxies::Direct3DDevice9::GetIndices(IDirect3DIndexBuffer9** ppIndexData)
{
	return m_original->GetIndices(ppIndexData);
}

HRESULT Proxies::Direct3DDevice9::GetLight(DWORD Index, D3DLIGHT9* pLight)
{
	return m_original->GetLight(Index, pLight);
}

HRESULT Proxies::Direct3DDevice9::GetLightEnable(DWORD Index, BOOL* pEnable)
{
	return m_original->GetLightEnable(Index, pEnable);
}

HRESULT Proxies::Direct3DDevice9::GetMaterial(D3DMATERIAL9* pMaterial)
{
	return m_original->GetMaterial(pMaterial);
}

FLOAT Proxies::Direct3DDevice9::GetNPatchMode()
{
	return m_original->GetNPatchMode();
}

UINT Proxies::Direct3DDevice9::GetNumberOfSwapChains()
{
	return m_original->GetNumberOfSwapChains();
}

HRESULT Proxies::Direct3DDevice9::GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY* pEntries)
{
	return m_original->GetPaletteEntries(PaletteNumber, pEntries);
}

HRESULT Proxies::Direct3DDevice9::GetPixelShader(IDirect3DPixelShader9** ppShader)
{
	return m_original->GetPixelShader(ppShader);
}

HRESULT Proxies::Direct3DDevice9::GetPixelShaderConstantB(UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
{
	return m_original->GetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT Proxies::Direct3DDevice9::GetPixelShaderConstantF(UINT StartRegister, float* pConstantData, UINT Vector4fCount)
{
	return m_original->GetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT Proxies::Direct3DDevice9::GetPixelShaderConstantI(UINT StartRegister, int* pConstantData, UINT Vector4iCount)
{
	return m_original->GetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT Proxies::Direct3DDevice9::GetRasterStatus(UINT iSwapChain, D3DRASTER_STATUS* pRasterStatus)
{
	return m_original->GetRasterStatus(iSwapChain, pRasterStatus);
}

HRESULT Proxies::Direct3DDevice9::GetRenderState(D3DRENDERSTATETYPE State, DWORD* pValue)
{
	return m_original->GetRenderState(State, pValue);
}

HRESULT Proxies::Direct3DDevice9::GetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9** ppRenderTarget)
{
	return m_original->GetRenderTarget(RenderTargetIndex, ppRenderTarget);
}

HRESULT Proxies::Direct3DDevice9::GetRenderTargetData(IDirect3DSurface9* pRenderTarget, IDirect3DSurface9* pDestSurface)
{
	return m_original->GetRenderTargetData(pRenderTarget, pDestSurface);
}

HRESULT Proxies::Direct3DDevice9::GetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD* pValue)
{
	return m_original->GetSamplerState(Sampler, Type, pValue);
}

HRESULT Proxies::Direct3DDevice9::GetScissorRect(RECT* pRect)
{
	return m_original->GetScissorRect(pRect);
}

BOOL Proxies::Direct3DDevice9::GetSoftwareVertexProcessing()
{
	return m_original->GetSoftwareVertexProcessing();
}

HRESULT Proxies::Direct3DDevice9::GetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9** ppStreamData, UINT* pOffsetInBytes, UINT* pStride)
{
	return m_original->GetStreamSource(StreamNumber, ppStreamData, pOffsetInBytes, pStride);
}

HRESULT Proxies::Direct3DDevice9::GetStreamSourceFreq(UINT StreamNumber, UINT* pDivider)
{
	return m_original->GetStreamSourceFreq(StreamNumber, pDivider);
}

HRESULT Proxies::Direct3DDevice9::GetSwapChain(UINT iSwapChain, IDirect3DSwapChain9** ppSwapChain)
{
	return m_original->GetSwapChain(iSwapChain, ppSwapChain);
}

HRESULT Proxies::Direct3DDevice9::GetTexture(DWORD Stage, IDirect3DBaseTexture9** ppTexture)
{
	return m_original->GetTexture(Stage, ppTexture);
}

HRESULT Proxies::Direct3DDevice9::GetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue)
{
	return m_original->GetTextureStageState(Stage, Type, pValue);
}

HRESULT Proxies::Direct3DDevice9::GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX* pMatrix)
{
	return m_original->GetTransform(State, pMatrix);
}

HRESULT Proxies::Direct3DDevice9::GetVertexDeclaration(IDirect3DVertexDeclaration9** ppDecl)
{
	return m_original->GetVertexDeclaration(ppDecl);
}

HRESULT Proxies::Direct3DDevice9::GetVertexShader(IDirect3DVertexShader9** ppShader)
{
	return m_original->GetVertexShader(ppShader);
}

HRESULT Proxies::Direct3DDevice9::GetVertexShaderConstantB(UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
{
	return m_original->GetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT Proxies::Direct3DDevice9::GetVertexShaderConstantF(UINT StartRegister, float* pConstantData, UINT Vector4fCount)
{
	return m_original->GetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT Proxies::Direct3DDevice9::GetVertexShaderConstantI(UINT StartRegister, int* pConstantData, UINT Vector4iCount)
{
	return m_original->GetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT Proxies::Direct3DDevice9::GetViewport(D3DVIEWPORT9* pViewport)
{
	return m_original->GetViewport(pViewport);
}

HRESULT Proxies::Direct3DDevice9::LightEnable(DWORD LightIndex, BOOL bEnable)
{
	return m_original->LightEnable(LightIndex, bEnable);
}

HRESULT Proxies::Direct3DDevice9::MultiplyTransform(D3DTRANSFORMSTATETYPE State, const D3DMATRIX* pMatrix)
{
	return m_original->MultiplyTransform(State, pMatrix);
}

HRESULT Proxies::Direct3DDevice9::Present(const RECT* pSourceRect, const RECT* pDestRect, HWND hDestWindowOverride, const RGNDATA* pDirtyRegion)
{
	return m_original->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

HRESULT Proxies::Direct3DDevice9::ProcessVertices(UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9* pDestBuffer, IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags)
{
	return m_original->ProcessVertices(SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags);
}

HRESULT Proxies::Direct3DDevice9::QueryInterface(REFIID riid, void** ppvObject)
{
	auto Result = m_original->QueryInterface(riid, ppvObject);

	if (SUCCEEDED(Result) && riid == __uuidof(IDirect3DDevice9))
	{
		*ppvObject = this;
	}

	return Result;
}

ULONG Proxies::Direct3DDevice9::Release()
{
	auto Count = m_original->Release();

	if (Count == 0)
	{
		delete this;
	}

	return Count;
}

HRESULT Proxies::Direct3DDevice9::Reset(D3DPRESENT_PARAMETERS* pPresentationParameters)
{
	return m_original->Reset(pPresentationParameters);
}

HRESULT Proxies::Direct3DDevice9::SetClipPlane(DWORD Index, const float* pPlane)
{
	return m_original->SetClipPlane(Index, pPlane);
}

HRESULT Proxies::Direct3DDevice9::SetClipStatus(const D3DCLIPSTATUS9* pClipStatus)
{
	return m_original->SetClipStatus(pClipStatus);
}

HRESULT Proxies::Direct3DDevice9::SetCurrentTexturePalette(UINT PaletteNumber)
{
	return m_original->SetCurrentTexturePalette(PaletteNumber);
}

void Proxies::Direct3DDevice9::SetCursorPosition(INT X, INT Y, DWORD Flags)
{
	return m_original->SetCursorPosition(X, Y, Flags);
}

HRESULT Proxies::Direct3DDevice9::SetCursorProperties(UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9* pCursorBitmap)
{
	return m_original->SetCursorProperties(XHotSpot, YHotSpot, pCursorBitmap);
}

HRESULT Proxies::Direct3DDevice9::SetDepthStencilSurface(IDirect3DSurface9* pNewZStencil)
{
	return m_original->SetDepthStencilSurface(pNewZStencil);
}

HRESULT Proxies::Direct3DDevice9::SetDialogBoxMode(BOOL bEnableDialogs)
{
	return m_original->SetDialogBoxMode(bEnableDialogs);
}

HRESULT Proxies::Direct3DDevice9::SetFVF(DWORD FVF)
{
	return m_original->SetFVF(FVF);
}

void Proxies::Direct3DDevice9::SetGammaRamp(UINT iSwapChain, DWORD Flags, const D3DGAMMARAMP* pRamp)
{
	return m_original->SetGammaRamp(iSwapChain, Flags, pRamp);
}

HRESULT Proxies::Direct3DDevice9::SetIndices(IDirect3DIndexBuffer9* pIndexData)
{
	return m_original->SetIndices(pIndexData);
}

HRESULT Proxies::Direct3DDevice9::SetLight(DWORD Index, const D3DLIGHT9* pLight)
{
	return m_original->SetLight(Index, pLight);
}

HRESULT Proxies::Direct3DDevice9::SetMaterial(const D3DMATERIAL9* pMaterial)
{
	return m_original->SetMaterial(pMaterial);
}

HRESULT Proxies::Direct3DDevice9::SetNPatchMode(float nSegments)
{
	return m_original->SetNPatchMode(nSegments);
}

HRESULT Proxies::Direct3DDevice9::SetPaletteEntries(UINT PaletteNumber, const PALETTEENTRY* pEntries)
{
	return m_original->SetPaletteEntries(PaletteNumber, pEntries);
}

HRESULT Proxies::Direct3DDevice9::SetPixelShader(IDirect3DPixelShader9* pShader)
{
	return m_original->SetPixelShader(pShader);
}

HRESULT Proxies::Direct3DDevice9::SetPixelShaderConstantB(UINT StartRegister, const BOOL* pConstantData, UINT BoolCount)
{
	return m_original->SetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT Proxies::Direct3DDevice9::SetPixelShaderConstantF(UINT StartRegister, const float* pConstantData, UINT Vector4fCount)
{
	return m_original->SetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT Proxies::Direct3DDevice9::SetPixelShaderConstantI(UINT StartRegister, const int* pConstantData, UINT Vector4iCount)
{
	return m_original->SetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT Proxies::Direct3DDevice9::SetRenderState(D3DRENDERSTATETYPE State, DWORD Value)
{
	return m_original->SetRenderState(State, Value);
}

HRESULT Proxies::Direct3DDevice9::SetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9* pRenderTarget)
{
	return m_original->SetRenderTarget(RenderTargetIndex, pRenderTarget);
}

HRESULT Proxies::Direct3DDevice9::SetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value)
{
	return m_original->SetSamplerState(Sampler, Type, Value);
}

HRESULT Proxies::Direct3DDevice9::SetScissorRect(const RECT* pRect)
{
	return m_original->SetScissorRect(pRect);
}

HRESULT Proxies::Direct3DDevice9::SetSoftwareVertexProcessing(BOOL bSoftware)
{
	return m_original->SetSoftwareVertexProcessing(bSoftware);
}

HRESULT Proxies::Direct3DDevice9::SetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride)
{
	return m_original->SetStreamSource(StreamNumber, pStreamData, OffsetInBytes, Stride);
}

HRESULT Proxies::Direct3DDevice9::SetStreamSourceFreq(UINT StreamNumber, UINT FrequencyParameter)
{
	return m_original->SetStreamSourceFreq(StreamNumber, FrequencyParameter);
}

HRESULT Proxies::Direct3DDevice9::SetTexture(DWORD Sampler, IDirect3DBaseTexture9* pTexture)
{
	return m_original->SetTexture(Sampler, pTexture);
}

HRESULT Proxies::Direct3DDevice9::SetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value)
{
	return m_original->SetTextureStageState(Stage, Type, Value);
}

HRESULT Proxies::Direct3DDevice9::SetTransform(D3DTRANSFORMSTATETYPE State, const D3DMATRIX* pMatrix)
{
	return m_original->SetTransform(State, pMatrix);
}

HRESULT Proxies::Direct3DDevice9::SetVertexDeclaration(IDirect3DVertexDeclaration9* pDecl)
{
	return m_original->SetVertexDeclaration(pDecl);
}

HRESULT Proxies::Direct3DDevice9::SetVertexShader(IDirect3DVertexShader9* pShader)
{
	return m_original->SetVertexShader(pShader);
}

HRESULT Proxies::Direct3DDevice9::SetVertexShaderConstantB(UINT StartRegister, const BOOL* pConstantData, UINT BoolCount)
{
	return m_original->SetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT Proxies::Direct3DDevice9::SetVertexShaderConstantF(UINT StartRegister, const float* pConstantData, UINT Vector4fCount)
{
	return m_original->SetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT Proxies::Direct3DDevice9::SetVertexShaderConstantI(UINT StartRegister, const int* pConstantData, UINT Vector4iCount)
{
	return m_original->SetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT Proxies::Direct3DDevice9::SetViewport(const D3DVIEWPORT9* pViewport)
{
	return m_original->SetViewport(pViewport);
}

BOOL Proxies::Direct3DDevice9::ShowCursor(BOOL bShow)
{
	return m_original->ShowCursor(bShow);
}

HRESULT Proxies::Direct3DDevice9::StretchRect(IDirect3DSurface9* pSourceSurface, const RECT* pSourceRect, IDirect3DSurface9* pDestSurface, const RECT* pDestRect, D3DTEXTUREFILTERTYPE Filter)
{
	return m_original->StretchRect(pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
}

HRESULT Proxies::Direct3DDevice9::TestCooperativeLevel()
{
	return m_original->TestCooperativeLevel();
}

HRESULT Proxies::Direct3DDevice9::UpdateSurface(IDirect3DSurface9* pSourceSurface, const RECT* pSourceRect, IDirect3DSurface9* pDestinationSurface, const POINT* pDestinationPoint)
{
	return m_original->UpdateSurface(pSourceSurface, pSourceRect, pDestinationSurface, pDestinationPoint);
}

HRESULT Proxies::Direct3DDevice9::UpdateTexture(IDirect3DBaseTexture9* pSourceTexture, IDirect3DBaseTexture9* pDestinationTexture)
{
	return m_original->UpdateTexture(pSourceTexture, pDestinationTexture);
}

HRESULT Proxies::Direct3DDevice9::ValidateDevice(DWORD* pNumPasses)
{
	return m_original->ValidateDevice(pNumPasses);
}
