#include "Drawable.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "Material.h"

Drawable::Drawable()
	: m_IndexBuffer(nullptr)
	, m_Material(nullptr)
	, m_VertexBuffer(nullptr)
	, m_BufferId(0)
{
	glGenVertexArrays(1, &m_BufferId);
}

void Drawable::Draw()
{
	if (m_Material)
	{
		m_Material->Begin();
	}
	glBindVertexArray(m_BufferId);
	m_IndexBuffer->Use();
	m_IndexBuffer->Draw();
	m_IndexBuffer->Clear();
	glBindVertexArray(0);
	if (m_Material)
	{
		m_Material->End();
	}
}

void Drawable::UseArrayBuffer()
{
	glBindVertexArray(m_BufferId);
}

void Drawable::ClearArrayBuffer()
{
	glBindVertexArray(0);
}
