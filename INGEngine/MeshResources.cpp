#include "pch.h"
#include "Resources.h"
#include <fstream>

using namespace ING::Engine;




MeshData* Resources::ImportMeshData_DemoFile(std::string path) {
	MeshData* data=new MeshData();


	std::ifstream fin(path);

	if (!fin)
	{
		return nullptr;
	}

	UINT vcount = 0;
	UINT tcount = 0;
	std::string ignore;

	fin >> ignore >> vcount;
	fin >> ignore >> tcount;
	fin >> ignore >> ignore >> ignore >> ignore;

	data->vertices.resize(vcount);
	for (UINT i = 0; i < vcount; ++i)
	{
		fin >> data->vertices[i].position.x >> data->vertices[i].position.y >> data->vertices[i].position.z;
		fin >> data->vertices[i].normal.x >> data->vertices[i].normal.y >> data->vertices[i].normal.z;
	}

	fin >> ignore;
	fin >> ignore;
	fin >> ignore;

	UINT mSkullIndexCount = 3 * tcount;

	data->indices.resize(mSkullIndexCount);
	for (UINT i = 0; i < tcount; i++) {
		fin >> data->indices[i * 3 + 0] >> data->indices[i * 3 + 1] >> data->indices[i * 3 + 2];
	}

	fin.close();

	return data;
}


Mesh* Resources::ImportMesh_DemoFile(std::string path) {
	Mesh* mesh = INGEngine->graphics->CreateMesh();
	mesh->data = ImportMeshData_DemoFile(path);
	mesh->BuildBuffer();
	return mesh;
}