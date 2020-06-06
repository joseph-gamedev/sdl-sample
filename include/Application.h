#pragma once

#include "ApplicationBase.h"
#include "LifeCycle.h"
#include "Time.h"

struct AppData
{
	std::string title;
	int width;
	int height;
};

class Application: public ApplicationBase, public ILifeCycle
{

public:
	Application();
	virtual ~Application();
	
	void SetAppData(const AppData& data);

	int Run();

	const Time& GetTime() const;

private:
	Time m_Time;
};

extern Application* CreateApplciation();