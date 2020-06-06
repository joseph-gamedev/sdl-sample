#pragma once

class IndexBuffer
{
public:
	IndexBuffer(void* data, unsigned int count);
	~IndexBuffer();

	void Draw();
	void Set(void* data, unsigned int count);
	void Use();
	void Clear();
private:
	unsigned int m_BufferId;
	unsigned int m_Count;
};