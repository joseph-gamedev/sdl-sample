#pragma once

#include "VertexArray.h"

struct Vertex
{
	void SetPosition(float x, float y , float z);
	void SetNormal(float x, float y, float z);
	void SetUV(float u ,float v);
	float position[3];
	float normal[3];
	//float uv[2];
};

class VertexBuffer
{
public:
	VertexBuffer(unsigned int usage);
	~VertexBuffer();

	void Use();
	void Clear();

	void Set(const void* data ,unsigned int size);
	void SetVertexAttributes();

private:
	void SetVertexAttributes(VertexArray<float>* vertexArrayPtr, int index, unsigned int type, unsigned int& offset);
private:
	void* m_Data;
	unsigned int m_BufferId;
	unsigned int m_BufferSize;
	unsigned int m_BufferUsage;

	VertexArray<float>* m_Positions;
	//VertexArray<float>* m_Colors;
	VertexArray<float>* m_Normals;
	VertexArray<float>* m_UVs;

};