#include "SandBox.h"
#include <iostream>

const GLchar* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"layout (location = 1) in vec3 color;\n"
"uniform mat4 viewprojection;\n"
"void main()\n"
"{\n"
"vec3 test = color;\n"
"gl_Position = viewprojection * vec4(position.x, position.y, color.z, 1.0);\n"
"}\0";
const GLchar* fragmentShaderSource = "#version 330 core\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";


GLuint VBO, VAO, EBO;


SandBox::SandBox()
	:Application()
{
}

void SandBox::Start()
{
	SetAppData(AppData{ "test", 1366,768 });

	std::vector<float> vertices { 0.5f,  0.5f, 0.0f,
								 0.5f, -0.5f, 0.0f,
								-0.5f, -0.5f, 0.0f, };
	std::vector<unsigned int> indices{ 0, 1, 2};


	m_Shader = std::make_unique<Shader>(vertexShaderSource, fragmentShaderSource);
	m_Camera = std::make_unique<OrthoGraphicCamera>(-1, 1, -1, 1 ,-1 ,1);
	m_Camera->SetPosition(glm::vec3(0, 1, 0));

	m_Mesh = std::make_unique<Mesh>();

	m_Mesh->Load(vertices, indices);

	int y = 0;
}

void SandBox::Stop()
{
}

void SandBox::Update()
{
	Time time = GetTime();
	time.GetDeltaTime();
	std::cout << time.GetDeltaTime() << std::endl;

	m_Camera->UpdateViewMatrix();
	glm::mat4 mat = m_Camera->GetViewProjectionMatrix();

	m_Shader->Use();
	m_Shader->SetUniformMatrix4fv("viewprojection", &mat[0][0]);
	m_Mesh->Draw();
	m_Shader->Clear();
	int x = 0;
}
