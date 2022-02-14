#include <DirectXMath.h>
#include <Windows.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <d3dcompiler.h>
#include <stdio.h>
#include <initguid.h>
#include "d3dx12.h"

using namespace DirectX;

// this will only call release if an object exists (prevents exceptions calling release on non existant objects)
#define SAFE_RELEASE(p) { if ( (p) ) { (p)->Release(); (p) = 0; } }

// Handle to the window
HWND hwnd = NULL;
LPCTSTR WindowName = L"FirstApp";
LPCTSTR WindowTitle = L"Ljq Window";
int Width = 800;
int Height = 600;
bool FullScreen = false;
// we will exit the program when this becomes false
bool Running = true;

// direct3d stuff initiation
const int frameBufferCount = 3;
ID3D12Device* device;
IDXGISwapChain3* swapChain; // swapchain used to switch between render targets
ID3D12CommandQueue* commandQueue;
ID3D12DescriptorHeap* rtvDescriptorHeap; // a descriptor heap to hold resources like the render targets
ID3D12Resource* renderTargets[frameBufferCount];
ID3D12CommandAllocator* commandAllocator[frameBufferCount];
ID3D12GraphicsCommandList* commandList;
ID3D12Fence* fence[frameBufferCount];
HANDLE fenceEvent; // a handle to an event when our fence is unlocked by the gpu
UINT64 fenceValue[frameBufferCount]; // thsis value is incremented each frame. each fence will have its own value
int frameIndex; // current rtv we are on
int rtvDescriptorSize;

// drawing
ID3D12PipelineState* pipelineStateObject;
ID3D12RootSignature* rootSignature;
D3D12_VIEWPORT viewport;
D3D12_RECT scissorRect;
ID3D12Resource* vertexBuffer; // default buffer
ID3D12Resource* indexBuffer;
D3D12_VERTEX_BUFFER_VIEW vertexBufferView;
D3D12_INDEX_BUFFER_VIEW indexBufferView;
// depth test
ID3D12Resource* depthStencilBuffer;
ID3D12DescriptorHeap* dsDescriptorHeap;
// transformations and world view projection
struct ConstantBufferPerObject {
	XMFLOAT4X4 wvpMat;
};
int ConstantBufferPerObjectAlignedSize = (sizeof(ConstantBufferPerObject) + 255) & ~255;
ConstantBufferPerObject cbPerObject;
ID3D12Resource* constantBufferUploadHeaps[frameBufferCount];
UINT8* cbvGPUAddress[frameBufferCount]; // pointer to each constant buffer resource heap
XMFLOAT4X4 cameraProjMat; // projection matrix
XMFLOAT4X4 cameraViewMat; // view matrix
XMFLOAT4 cameraPosition; // camera position vector
XMFLOAT4 cameraTarget; 
XMFLOAT4 cameraUp; // word up vector

XMFLOAT4X4 cube1WorldMat;
XMFLOAT4X4 cube1RotMat; // rotation
XMFLOAT4 cube1Position; 

XMFLOAT4X4 cube2WorldMat;
XMFLOAT4X4 cube2RotMat;
XMFLOAT4 cube2PositionOffset; // from the first cube

int numCubeIndices; // number of indices to draw the cube

// create a window
bool InitializeWindow(HINSTANCE hInstance, int ShowWnd, int width, int height, bool fullscreen);

void mainloop();

// functions for d3d
bool InitD3D();

void Update();

void UpdatePipeline();

void Cleanup();

void Render();

void WaitForPreviousFrame();

// callback for window messages
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
