#include "BasicBowlNode.h"

#include <memory>

BasicBowlNode::BasicBowlNode()
{
    m_shader  = nullptr;
    m_buffer  = nullptr;
    m_bowlbuffer = nullptr;

    // build and compile our shader zprogram
    // ------------------------------------
    m_shader = std::make_shared<Shader>("../source/shader/BasicBowlModelShader.vs","../source/shader/BasicBowlModelShader.fs");
    m_bowlbuffer = std::make_shared<AVMBowlBuffer>();
    m_bowlbuffer->Initialize();
    m_bowlbuffer->Build();

    std::vector<float> squareVertices;
    std::vector<unsigned int> squareIndices;
    m_bowlbuffer->getAllPointBuffer(squareVertices);
    m_bowlbuffer->getAllIndexBuffer(squareIndices);

    std::vector<VertexAttribute> v_layout;
    v_layout.emplace_back(0, "Position", AttributeType::Postion);
    VertexBufferLayout bufferLayout(v_layout);

    m_buffer = std::make_shared<VertexArray>();
    m_buffer->Bind();

    m_buffer->SetVBO((float*)&squareVertices[0], squareVertices.size() * sizeof(squareVertices[0]), bufferLayout);
    m_buffer->SetEBO(&squareIndices[0], squareIndices.size() * sizeof(unsigned int));

    m_buffer->UnBind();
}

bool BasicBowlNode::Update()
{
    return true;
}

bool BasicBowlNode::Render()
{
    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render
    // ------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // glViewport(400, 0, 800, 600);
    // glViewport(0, 0, 400, 600);
    
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

BasicBowlNode::~BasicBowlNode()
{
    m_shader  = nullptr;
    m_buffer  = nullptr;
    m_bowlbuffer = nullptr;
}
