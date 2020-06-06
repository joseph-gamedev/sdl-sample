#include "Shader.h"
#include <glad/glad.h>
#include <iostream>
Shader::Shader(const char* vertexCode, const char* fragmentCode)
	:m_ShaderId(-1)
{
	CompileShader(vertexCode, fragmentCode);
}

Shader::~Shader()
{
	glDeleteProgram(m_ShaderId);
}

void Shader::Use()
{
	glUseProgram(m_ShaderId);
}

void Shader::Clear()
{
	glUseProgram(0);
}

void Shader::SetUniform4f(const std::string& name, float uniform[4])
{
	int location = GetUniformLocation(name);
	glUniform4f(location, uniform[0], uniform[1], uniform[2], uniform[3]);
}

void Shader::SetUniformMatrix4fv(const std::string& name, const float* matrix)
{
	int location = GetUniformLocation(name);
	glUniformMatrix4fv(location, 1, GL_FALSE, (matrix));
}

unsigned int Shader::CompileShader(unsigned int type, const char* code)
{
	GLint length = strlen(code);
	//Create and compile shader of specific type
	unsigned int shader = glCreateShader(type);
	glShaderSource(shader, 1, &code, &length);
	glCompileShader(shader);

	GLint result = 0;
	GLchar log[2048] = { 0 };
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

	if (!result)
	{
		glGetShaderInfoLog(shader, sizeof(log), nullptr, log);
		printf("%s", log);
		return 0;
	}
	return shader;
}

void Shader::CompileShader(const char* vertexCode, const char* fragmentCode)
{
	unsigned int vertexShader = CompileShader(GL_VERTEX_SHADER, vertexCode);
	unsigned int fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentCode);

	//Create program and attach shaders to it and link
	m_ShaderId = glCreateProgram();
	glAttachShader(m_ShaderId, vertexShader);
	glAttachShader(m_ShaderId, fragmentShader);
	glLinkProgram(m_ShaderId);

	//CleanUp
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

int Shader::GetUniformLocation(const std::string& name)
{
	return glGetUniformLocation(m_ShaderId, name.c_str());
}
