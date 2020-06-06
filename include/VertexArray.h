#pragma once

template <typename T>
class VertexArray
{
public:
	VertexArray(int count, int stride, bool normalized);
	int GetCount() { return m_Count; }
	int GetSize() { return m_Data.size();  }
	int GetStride() { return m_Stride; }
	unsigned char GetNormalized() { return m_Normalized; }
	void SetData(std::vector<T>& data);
	void* GetData() { return m_Data; }
private:
	bool m_Normalized;
	int	m_Stride;
	std::vector<T> m_Data;
	int m_Count;
};

template<typename T>
inline VertexArray<T>::VertexArray(int count, int stride, bool normalized)
	: m_Count(count)
	, m_Normalized(normalized)
	, m_Stride(stride)
{
}

template<typename T>
inline void VertexArray<T>::SetData(std::vector<T>& data)
{
	m_Data = data;
}

