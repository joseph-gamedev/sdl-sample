#pragma once

class IAudioManager;
class ICameraManager;
class IInput;
class ILightManager;
class IRenderer;
class IResourseManager;
class ISceneManager;
class IShaderManager;
class IView;
	
class ApplicationBase
{
public:

	virtual ~ApplicationBase() {}

	IAudioManager* GetAudioManager() { return m_AudioManager; }

	ICameraManager* GetCameraManager() { return m_CameraManager; }

	IInput* GetInput() { return m_Input; }

	ILightManager* GetLightManager() { return  m_LightManager; }

	IRenderer* GetRenderer() { return m_Renderer; }

	IResourseManager* GetResourceManager() { return m_ResourseManager; }

	ISceneManager* GetSceneManager() { return m_SceneManager; }

	IShaderManager* GetShaderManager() { return m_ShaderManager; }

	IView* GetView() { return m_View; }

protected:
	IAudioManager* m_AudioManager;
	ICameraManager* m_CameraManager;
	IInput* m_Input;
	ILightManager* m_LightManager;
	IRenderer* m_Renderer;
	IResourseManager* m_ResourseManager;
	ISceneManager* m_SceneManager;
	IShaderManager* m_ShaderManager;
	IView* m_View;

};