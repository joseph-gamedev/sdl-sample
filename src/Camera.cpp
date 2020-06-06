#include "Camera.h"
#include "TransformNode.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

Camera::Camera()
	: TransformNode()
	, m_ProjectionMatrix(glm::mat4(1.0f))
	, m_ViewMatrix(glm::mat4(1.0f))
{
}

inline const glm::mat4& Camera::GetProjectionMatrix() const
{
	return m_ProjectionMatrix;
}

inline const glm::mat4& Camera::GetViewMatrix() const
{
	return m_ViewMatrix;
}

void Camera::UpdateViewMatrix()
{
	m_ViewMatrix = glm::inverse(GetTransform());
}

OrthoGraphicCamera::OrthoGraphicCamera(float left, float right, float bottom, float top)
	: Camera()
{
	m_ProjectionMatrix = glm::ortho(left, right, bottom, top);
}

OrthoGraphicCamera::OrthoGraphicCamera(float left, float right, float bottom, float top, float zNear, float zFar)
{
	m_ProjectionMatrix = glm::ortho(left, right, bottom, top, zNear, zFar);
}

LookAtCamera::LookAtCamera(const glm::vec3& eye, const glm::vec3& center, const glm::vec3& up)
{
	m_ProjectionMatrix = glm::lookAt(eye, center, up);
}

PerspectiveCamera::PerspectiveCamera(float fovy, float aspect, float zNear, float zFar)
{
	m_ProjectionMatrix = glm::perspective(fovy, aspect, zNear, zFar);
}
