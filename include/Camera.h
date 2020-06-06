#pragma once

#include "TransformNode.h"

class Camera: public TransformNode
{
public:
	Camera(const Camera& camera) = delete;
	Camera& operator=(const Camera&) = delete;

	Camera();

	inline const glm::mat4& GetProjectionMatrix() const;
	inline const glm::mat4& GetViewMatrix() const;
	inline const glm::mat4& Camera::GetViewProjectionMatrix() const
	{
		return m_ProjectionMatrix * m_ViewMatrix;
	}

	void UpdateViewMatrix();
protected:

	glm::mat4 m_ProjectionMatrix;
	glm::mat4 m_ViewMatrix;
};

class OrthoGraphicCamera : public Camera
{
public:
	OrthoGraphicCamera(const OrthoGraphicCamera& camera) = delete;
	OrthoGraphicCamera& operator=(const OrthoGraphicCamera&) = delete;

	OrthoGraphicCamera(float left, float right, float bottom, float top);
	OrthoGraphicCamera(float left, float right, float bottom, float top, float zNear, float zFar);
};

class LookAtCamera : public Camera
{
public:
	LookAtCamera(const OrthoGraphicCamera& camera) = delete;
	LookAtCamera& operator=(const OrthoGraphicCamera&) = delete;

	LookAtCamera(const glm::vec3& eye, const glm::vec3& center, const glm::vec3& up);

};

class PerspectiveCamera : public Camera
{
public:
	PerspectiveCamera(const PerspectiveCamera& camera) = delete;
	PerspectiveCamera& operator=(const PerspectiveCamera&) = delete;

	PerspectiveCamera(float fovy, float aspect,float zNear, float zFar);

};