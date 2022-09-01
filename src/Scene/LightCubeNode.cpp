#include "LightCubeNode.h"

#include <memory>

LightCubeNode::LightCubeNode()
{
    m_shader  = nullptr;
    m_buffer  = nullptr;

    m_positionCenter = glm::vec3(3.0f, 0.0f, 3.0f);
    m_radius = 0.1f;

    // build and compile our shader zprogram
    // ------------------------------------
    m_shader = std::make_shared<Shader>("../source/shader/LightCubeShader.vs","../source/shader/LightCubeShader.fs");

    m_buffer = std::make_shared<VertexArray>();
}

bool LightCubeNode::Update()
{
    std::vector<VertexAttribute> v_layout;
    v_layout.emplace_back(0, "Position", AttributeType::Postion);
    VertexBufferLayout bufferLayout(v_layout);

    m_buffer->Bind();

    // 顶点数据
    float squareVertices[] = {
        m_positionCenter.x - m_radius, m_positionCenter.y + m_radius, m_positionCenter.z - m_radius,  // bottom left  down
        m_positionCenter.x + m_radius, m_positionCenter.y + m_radius, m_positionCenter.z - m_radius,  // bottom left  up
        m_positionCenter.x + m_radius, m_positionCenter.y - m_radius, m_positionCenter.z - m_radius,  // bottom right up
        m_positionCenter.x - m_radius, m_positionCenter.y - m_radius, m_positionCenter.z - m_radius,  // bottom right down
        m_positionCenter.x - m_radius, m_positionCenter.y - m_radius, m_positionCenter.z + m_radius,  // top    right down
        m_positionCenter.x - m_radius, m_positionCenter.y + m_radius, m_positionCenter.z + m_radius,  // top    left  down
        m_positionCenter.x + m_radius, m_positionCenter.y + m_radius, m_positionCenter.z + m_radius,  // top    left  up
        m_positionCenter.x + m_radius, m_positionCenter.y - m_radius, m_positionCenter.z + m_radius   // top    right up
    };
    // 索引数据
    unsigned int squareIndices[] = {
		0, 1, 2, 2, 3, 0,    // 底面
        0, 5, 4, 4, 3, 0,    // 正面
        1, 6, 5, 5, 0, 1,    // 左面
        2, 7, 6, 6, 1, 2,    // 背面
        3, 4, 7, 7, 2, 3,    // 右面
        5, 6, 7, 7, 4, 5     // 顶面
    };

    m_buffer->SetVBO(squareVertices, sizeof(squareVertices), bufferLayout);
    m_buffer->SetEBO(squareIndices, sizeof(squareIndices));

    m_buffer->UnBind();
    return true;
}

bool LightCubeNode::Render()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // render
    // ------
    m_shader->Use();
    m_shader->setUniformMat4("view", m_view);
    m_shader->setUniformMat4("model", m_model);
    m_shader->setUniformMat4("projection", m_projection);
    m_buffer->Bind();
    glDrawElements(GL_TRIANGLES, m_buffer->GetEBO()->GetIndexNums(), GL_UNSIGNED_INT, nullptr);
    m_buffer->UnBind();
	m_shader->UnUse();
    return true;
}

LightCubeNode::~LightCubeNode()
{
    m_shader  = nullptr;
    m_buffer  = nullptr;
}

