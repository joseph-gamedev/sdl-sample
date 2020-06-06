#pragma once

class Shader;

class Material
{
public:
	Material(Shader& shader);

	void Begin();
	void End();

private:
	Shader* m_Shader;
};