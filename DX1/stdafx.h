#include <Windows.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include <stdio.h>
#include "d3dx12.h"

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

// direct3d stuff
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
