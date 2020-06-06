#include "TransformNode.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

TransformNode::TransformNode()
	:m_Transform(glm::mat4x4(1.0f))
{
	SetPosition(glm::vec3(0));
	SetRotation(glm::vec3(0));
	SetScale(glm::vec3(1));
}

TransformNode::TransformNode(const glm::vec3& position, const glm::vec3& scale, const glm::vec3& rotation)
	:m_Transform(glm::mat4x4(1.0f))
{
	SetPosition(position);
	SetRotation(rotation);
	SetScale(scale);
}

inline void TransformNode::SetPosition(const glm::vec3& position)
{
	m_Position = position;
	m_Transform = glm::translate(m_Transform, m_Position);
}

inline void TransformNode::SetScale(const glm::vec3& scale)
{
	m_Scale = scale;
	m_Transform = glm::scale(m_Transform, m_Scale);
}

inline void TransformNode::SetRotation(const glm::vec3 & rotation)
{
	m_Rotation = rotation;
	m_Transform = glm::rotate(m_Transform, glm::radians(m_Rotation.x), glm::vec3(1, 0, 0));
	m_Transform = glm::rotate(m_Transform, glm::radians(m_Rotation.y), glm::vec3(0, 1, 0));
	m_Transform = glm::rotate(m_Transform, glm::radians(m_Rotation.z), glm::vec3(0, 0, 1));
}
