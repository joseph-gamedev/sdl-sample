#include "VertexBuffer.h"
#include "VertexArray.h"

GLfloat vertices[] = {
 0.5f,  0.5f, 0.0f,  // Top Right
 0.5f, -0.5f, 0.0f,  // Bottom Right
-0.5f, -0.5f, 0.0f,  // Bottom Left
-0.5f,  0.5f, 0.0f   // Top Left 
};

std::vector<Vertex> vertexList;

VertexBuffer::VertexBuffer(unsigned int usage)
	: m_BufferId(0)
	, m_BufferSize(0)
	, m_BufferUsage(usage)
{
	glGenBuffers(1, &m_BufferId);

	m_Positions = new VertexArray<float>(3, 3 * sizeof(float), false);
	m_Normals = new VertexArray<float>(3,3 * sizeof(float), false);
	m_UVs = new VertexArray<float>(2,2 * sizeof(float), false);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_BufferId);
}

void VertexBuffer::Use()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferId);
}

void VertexBuffer::Clear()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::Set(const void* data, unsigned int size)
{

	/*for (size_t count = 0; count < 12; count+=3)
	{

		Vertex vertex;
		vertex.SetPosition(vertices[count], vertices[count + 1], vertices[count + 2]);
		vertexList.push_back(vertex);
	}*/
	//glBindBuffer(GL_ARRAY_BUFFER, m_BufferId);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertexList, GL_STATIC_DRAW);


	
	//glBindAttribLocation(3, 0, "position");
	//glBindAttribLocation(3, 1, "norm");
	GLint pos = glGetAttribLocation(3, "position");
	GLint nor = glGetAttribLocation(3, "color");
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferId);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

	//glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	//glEnableVertexAttribArray(nor);
	glVertexAttribPointer(nor, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (GLvoid*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	//SetVertexAttributes();
}

void VertexBuffer::SetVertexAttributes()
{
	unsigned int offset = 0;
	SetVertexAttributes(m_Positions, 0, GL_FLOAT ,offset);
	SetVertexAttributes(m_Normals,1, GL_FLOAT, offset);
	//SetVertexAttributes(m_UVs, 2, GL_FLOAT, offset);
}

void VertexBuffer::SetVertexAttributes(VertexArray<float>* vertexArrayPtr, int index, unsigned int type, unsigned int& offset)
{
	auto stride = vertexArrayPtr->GetStride();
	auto count = vertexArrayPtr->GetCount();
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, vertexArrayPtr->GetCount(), GLenum(type), GL_FALSE, vertexArrayPtr->GetStride(), (const void*)offset);
	
	offset += vertexArrayPtr->GetCount();
}

void Vertex::SetPosition(float x, float y, float z)
{
	position[0] = x;
	position[1] = y;
	position[2] = z;
}

void Vertex::SetNormal(float x, float y, float z)
{
	normal[0] = x;
	normal[1] = y;
	normal[2] = z;
}

void Vertex::SetUV(float u, float v)
{
	//uv[0] = u;
	//uv[1] = v;
}
