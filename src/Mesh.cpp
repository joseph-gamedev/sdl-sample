#include "Mesh.h"
#include "IndexBuffer.h"
#include "Material.h"

Mesh::Mesh(Material& material)
{
    m_Material = &material;
}

Mesh::~Mesh()
{
    m_Indices.clear();
    m_BiNormals.clear();
    m_Normals.clear();
    m_Tangents.clear();
    m_Vertices.clear();
}

void Mesh::Load(const std::string& filepath)
{

}

void Mesh::Load(const std::vector<float>& vertices, const std::vector<unsigned int>& indices)
{
  //  m_Vertices = vertices;
    m_Indices = indices;

    for (size_t count = 0; count < vertices.size(); count+=3)
    {
        m_Vertices.push_back(glm::vec3(vertices[count], vertices[count + 1], vertices[count + 2]));
        m_Normals.push_back(glm::vec3(0));
        m_UVs.push_back(glm::vec2(0));
    }
    UseArrayBuffer();
    CombineData();
    ClearArrayBuffer();
}

int Mesh::GetSize()
{
    return m_Vertices.size() * sizeof(Vertex);
}

void Mesh::CombineData()
{
    for (int count = 0; count < m_Vertices.size(); count++)
    {
        Vertex vertex;
        vertex.SetPosition(m_Vertices[count].x, m_Vertices[count].y, m_Vertices[count].z);
        vertex.SetNormal(m_Normals[count].x, m_Normals[count].y, m_Normals[count].z);
       // vertex.SetUV(m_UVs[count].x, m_UVs[count].y);
       // = { m_Vertices[count],m_Normals[count], m_UVs[count] };
        auto pos = sizeof(Vertex);
        m_Data.push_back(vertex);
    }
    m_VertexBuffer = new VertexBuffer(0);
    m_VertexBuffer->Set(&m_Data[0], GetSize());

    m_IndexBuffer = new IndexBuffer(&m_Indices[0], m_Indices.size() );
}
