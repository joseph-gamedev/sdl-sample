#pragma once

class IRenderer
{
public:
    virtual ~IRenderer(){}

    virtual void Init() = 0;

    virtual void ClearColor(float,float,float,float) = 0;

    virtual void ReInitialize() = 0;

    virtual void SwapBuffers() = 0;

    virtual void Terminate() = 0;

};