#include "IndexBuffer.h"

GLuint indices[] = {  // Note that we start from 0!
	0, 1, 3,  // First Triangle
	1, 2, 3   // Second Triangle
};

IndexBuffer::IndexBuffer(void* data, unsigned int count)
	: m_BufferId(0)
	, m_Count(count)
{
	Set(data, count);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &m_BufferId);
}

void IndexBuffer::Draw()
{
	glDrawElements(GL_TRIANGLES, m_Count, GL_UNSIGNED_INT, NULL);
}

void IndexBuffer::Set(void* data, unsigned int count)
{
	//glGenBuffers(1, &m_BufferId);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferId);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glGenBuffers(1, &m_BufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);

}

void IndexBuffer::Use()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferId);
}

void IndexBuffer::Clear()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
