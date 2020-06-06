#pragma once

class ILifeCycle
{
public:
	virtual ~ILifeCycle() {}

	virtual void Start() = 0;

	virtual void Stop() = 0;

	virtual void Update() = 0;
};