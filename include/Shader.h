#pragma once

class Shader
{
public:
    Shader(const char* vertexCode, const char* fragmentCode);
    ~Shader();

    void Use();
    void Clear();

    void SetUniform4f(const std::string& name, float[4]);
    void SetUniformMatrix4fv(const std::string& name, const float* matrix);
private:
    unsigned int CompileShader(unsigned int type, const char* code);

    void CompileShader(const char* vertexCode, const char* fragmentCode);

    int GetUniformLocation(const std::string& name);

private:
    unsigned int m_ShaderId;
};