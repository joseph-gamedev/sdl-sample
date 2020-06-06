#pragma once 

#include "Drawable.h"
#include "VertexBuffer.h"

class Mesh : public Drawable
{
public:
    Mesh() {}
    Mesh(Material& material);
    ~Mesh();
    void Load(const std::string& filepath);

    //test function
    void Load(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);

    void* GetData() { return &m_Data; }
    int GetSize();

    const std::vector<unsigned int>& GetIndices() { return m_Indices; }
    const std::vector<glm::vec3>& GetBinormals() { return m_BiNormals; }
    const std::vector<glm::vec3>& GetNormals() { return m_Normals; }
    const std::vector<glm::vec3>& GetTangents() { return m_Tangents; }
    const std::vector<glm::vec3>& GetVertices() { return m_Vertices; }
    const std::vector<glm::vec2>& GetUVs() { return m_UVs; }

private:
    void CombineData();

private:

    std::vector<Vertex> m_Data;

    std::vector<unsigned int> m_Indices;
    std::vector<glm::vec3> m_BiNormals;   
    std::vector<glm::vec3> m_Normals;
    std::vector<glm::vec3> m_Tangents;
    std::vector<glm::vec3> m_Vertices;
    std::vector<glm::vec2> m_UVs;
};