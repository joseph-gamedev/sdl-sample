#pragma once

class TransformNode
{
public:
	TransformNode();
	TransformNode(const glm::vec3& position, const glm::vec3& scale, const glm::vec3& rotation);

	inline const glm::vec3& GetPosition() const { return m_Position; }

	inline void SetPosition(const glm::vec3& position);

	inline const glm::vec3& GetScale() const { return m_Scale; }

	inline void SetScale(const glm::vec3& scale);

	inline const glm::vec3& GetRotation() const { return m_Rotation; }

	inline void SetRotation(const glm::vec3& rotation);

	inline const glm::mat4x4& GetTransform() const { return m_Transform; }

private:
	glm::vec3 m_Position;
	glm::vec3 m_Scale;
	glm::vec3 m_Rotation;
	glm::mat4x4 m_Transform;
};