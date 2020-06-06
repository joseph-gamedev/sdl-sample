#include "Material.h"
#include "Shader.h"

Material::Material(Shader& shader)
	: m_Shader(&shader)
{ 

}

void Material::Begin()
{
	if (m_Shader)
	{
		m_Shader->Use();
	}
}

void Material::End()
{
	if (m_Shader)
	{
		m_Shader->Clear();
	}
}
