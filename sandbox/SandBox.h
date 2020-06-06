#pragma once

#include "GameFramework.h"
#include <memory>

class SandBox : public Application
{
public:
	SandBox();
	virtual void Start() override;
	virtual void Stop() override;
	virtual void Update() override;

private:
	std::unique_ptr<Camera> m_Camera;
	std::unique_ptr<Shader> m_Shader;
	std::unique_ptr<Mesh> m_Mesh;
};

Application* CreateApplciation()
{
	return new SandBox();
}