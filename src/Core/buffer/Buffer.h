#ifndef BUFFER_H
#define BUFFER_H

#include "../../Platform/platform.h"

/**
* This is a vertex attribute type enumeration that represents the size of the property. 
* For example, Postion is a vector of vec3, so the size is 3 
*
*/
enum class AttributeType // 顶点属性类型
{
	Postion   =		3,   // 位置为(X, Y, Z)向量，因此大小为3
	Color     =		3,   // 颜色为(R, G, B)向量，因此大小为3
    //  ColorAlpha                      // 带透明度的颜色为(R, G, B, A), 因此大小为4
	TexCoords =		2,
	Normal    =		3
};

/**
* This is a structure that describes a vertex attribute in the VBO memory layout.
* And is constructed by passing in 
* index: the vertex position index.
* name: the name of the attribute.
* type: the type of the attribute.
*/
struct VertexAttribute
{
    VertexAttribute(unsigned int index, const std::string& name, AttributeType type, bool isNormalize = false)
        : m_Index(index), m_Name(name), m_Type(type), m_IsNormalize(isNormalize)
    {}

	unsigned int m_Index;   // 顶点属性的索引

	std::string m_Name;     // 顶点属性的名称

	AttributeType m_Type;   // 顶点属性的类型

	bool m_IsNormalize;     // 顶点属性是否需要标准化
};

/**
* This is a class that describes memory layout .
* And is constructed to accept a VertexAttribute structure wrapped in a vector
*/
class VertexBufferLayout
{
public:
	VertexBufferLayout(std::vector<VertexAttribute>& attribute)
		: m_Attribute(attribute)
	{}

	inline std::vector<VertexAttribute>::iterator begin() const { return m_Attribute.begin(); }
	inline std::vector<VertexAttribute>::iterator end() const { return m_Attribute.end(); }

private:
	std::vector<VertexAttribute>& m_Attribute;
};


/**
* 
* 
* 
*/
class VertexBuffer
{
public:
	VertexBuffer(float* vertices, unsigned int size, const VertexBufferLayout& layout);
	~VertexBuffer();

	void Bind();
	void UnBind();

	inline VertexBufferLayout& GetVBOLayout() { return m_Layout; }

	inline unsigned int GetVertexNums() const { return m_VertexNums; }

	inline int GetStride() const { return m_Stride; }

private:
	unsigned int ID;

	// Used to describe the memory layout of the current buffer object
	VertexBufferLayout m_Layout;

	int m_Stride = 0;

	unsigned int m_VertexNums;

	void CalculateStride();
};


/**
* 
* 
* 
* 
*/
class IndexBuffer
{
public:
	IndexBuffer(unsigned int* vertices, unsigned int size);
	~IndexBuffer();

	void Bind();
	void UnBind();

	inline unsigned int GetIndexNums() const { return m_IndexNums; }

private:
    unsigned int ID;
    unsigned int m_IndexNums;
};


class VertexArray
{
public:
    VertexArray();
    ~VertexArray();

    void Bind();
    void UnBind();

    void SetVBO(const std::shared_ptr<VertexBuffer>& vbo);
    void SetVBO(float* vertices, unsigned int size, const VertexBufferLayout& layout);

    void SetEBO(const std::shared_ptr<IndexBuffer>& ebo);
    void SetEBO(unsigned int* vertices, unsigned int size);

    inline std::shared_ptr<VertexBuffer> GetVBO() const { return m_VertexBuffer; }
    inline std::shared_ptr<IndexBuffer>  GetEBO() const { return m_IndexBuffer; }

private:
    unsigned int ID;
    std::shared_ptr<VertexBuffer> m_VertexBuffer;
    std::shared_ptr<IndexBuffer> m_IndexBuffer;

    void ConfigAttribPointor();
};

#endif /* BUFFER_H*/