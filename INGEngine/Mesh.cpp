#include "pch.h"
#include "Mesh.h"
#include <d3d11.h>

using namespace ING::Engine;


Mesh::Mesh() {

}

Mesh::~Mesh() {

}

void Mesh::BuildGBuffer() {
	/*
	gbuffer = new GBuffer();

	D3D11_BUFFER_DESC vbd;
	vbd.Usage = D3D11_USAGE_IMMUTABLE;
	vbd.ByteWidth = sizeof(Vertex) * data->vertices.size();
	vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vbd.CPUAccessFlags = 0;
	vbd.MiscFlags = 0;
	vbd.StructureByteStride = 0;
	D3D11_SUBRESOURCE_DATA vinitData;
	vinitData.pSysMem = &data->vertices[0];


	graphics->d3dDevice->CreateBuffer(&vbd, &vinitData, &gbuffer->vertexBuffer);



	D3D11_BUFFER_DESC ibd;
	ibd.Usage = D3D11_USAGE_IMMUTABLE;
	ibd.ByteWidth = sizeof(UINT) * data->indices.size();
	ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	ibd.CPUAccessFlags = 0;
	ibd.MiscFlags = 0;
	ibd.StructureByteStride = 0;
	D3D11_SUBRESOURCE_DATA iinitData;
	iinitData.pSysMem = &data->indices[0];

	graphics->d3dDevice->CreateBuffer(&ibd, &iinitData, &gbuffer->indicesBuffer);
	*/
}