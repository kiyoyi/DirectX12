#include <DirectXMath.h>
#include <stdio.h>

using namespace DirectX;

struct Vertex {
	Vertex(float x, float y, float z, float r, float g, float b, float a) : pos(x, y, z), color(r, g, b, a) {}
	XMFLOAT3 pos;
	XMFLOAT4 color;
};

int main()
{
	// below can build successfully
	Vertex test[3] = {
		{ 	0.0f,	0.0f,	0.0f,	0.0f,	0.0f,	1.0f,	1.0f },
		{ 	0.0f,	0.0f,	0.0f,	0.0f,	0.0f,	1.0f,	1.0f },
		{ 	0.0f,	0.0f,	0.0f,	0.0f,	0.0f,	1.0f,	1.0f },
	};

	// what I want is ::::
	 //Vertex test[3];
	 //test[0] = { 	0.0f,	0.0f,	0.0f,	0.0f,	0.0f,	1.0f,	1.0f };

	return 0;
}