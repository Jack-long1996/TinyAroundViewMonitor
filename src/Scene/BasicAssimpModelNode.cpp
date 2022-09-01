#include "BasicAssimpModelNode.h"

BasicAssimpModelNode::BasicAssimpModelNode()
{
    m_shader = nullptr;
    // build and compile our shader zprogram
    // ------------------------------------
    m_shader = std::make_shared<Shader>("../source/shader/BasicAssimpModelNodeShader.vs","../source/shader/BasicAssimpModelNodeShader.fs");

    m_filename = "../source/models/Cube/Cube.gltf";
}

bool BasicAssimpModelNode::Update()
{
    return true;
}

bool BasicAssimpModelNode::Render()
{
    m_shader->Use();
    m_shader->setUniformMat4("view", m_view);
    m_shader->setUniformMat4("model", m_model);
    m_shader->setUniformMat4("projection", m_projection);
    m_shader->UnUse();
    return true;
}

BasicAssimpModelNode::~BasicAssimpModelNode()
{
    m_shader = nullptr;
}