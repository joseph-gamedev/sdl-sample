#pragma once

class IRenderer;
class IScene;
class ApplicationBase;

class IView
{
public:
    virtual ~IView() {};

    virtual void Init() = 0;

    virtual void ReInitialize() = 0;

    virtual void Update(ApplicationBase& appBase) = 0;

    virtual void Terminate() = 0;

    virtual void GetViewportSize() const = 0;

    virtual void GetViewSize() const = 0;

    virtual void* GetWindow() const = 0;

    virtual bool ShouldClose() const = 0;

    virtual void SetViewSize(int width, int height) = 0;

    virtual const std::string& GetTitle() const = 0;

    virtual void SetTitle(const std::string& title) = 0;

    virtual void Display(IScene* scene, IRenderer* renderer) = 0;
};