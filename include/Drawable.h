#pragma once

class IndexBuffer;
class Material;
class VertexBuffer;

class Drawable
{
public:
	Drawable();
	void Draw();

	void UseArrayBuffer();

	void ClearArrayBuffer();
protected:
	IndexBuffer* m_IndexBuffer;
	Material* m_Material;
	VertexBuffer* m_VertexBuffer;
	unsigned int m_BufferId;
};