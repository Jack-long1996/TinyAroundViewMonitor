#include "StandardBowlNode.h"

#include <memory>

StandardBowlNode::StandardBowlNode()
{
    m_shader  = nullptr;
    m_bowlbuffer = nullptr;
    m_camera = nullptr;

    m_frontbuffer = nullptr;
    m_frontrightbuffer = nullptr;
    m_rightbuffer = nullptr;
    m_backrightbuffer = nullptr;
    m_backbuffer = nullptr;
    m_backleftbuffer = nullptr;
    m_leftbuffer = nullptr;
    m_frontleftbuffer = nullptr;

    m_frontShortTexture = nullptr;
    m_rightShortTexture = nullptr;
    m_rearShortTexture  = nullptr;
    m_leftShortTexture  = nullptr;

    // build and compile our shader zprogram
    // ------------------------------------
    m_shader = std::make_shared<Shader>("../source/shader/StandardBowlNodeShader.vs","../source/shader/StandardBowlNodeShader.fs");
    m_frontShortTexture = std::make_shared<Texture>("../source/wideAngleMaster/1_0.yuv", 1280, 720);
    m_frontShortTexture->Create();
    m_rightShortTexture = std::make_shared<Texture>("../source/wideAngleMaster/2_0.yuv", 1280, 720);
    m_rightShortTexture->Create();
    m_rearShortTexture = std::make_shared<Texture>("../source/wideAngleMaster/3_0.yuv", 1280, 720);
    m_rearShortTexture->Create();
    m_leftShortTexture = std::make_shared<Texture>("../source/wideAngleMaster/0_0.yuv", 1280, 720);
    m_leftShortTexture->Create();

    m_camera = std::make_shared<AVMCamera>();
    m_bowlbuffer = std::make_shared<AVMBowlBuffer>();
    m_bowlbuffer->Initialize();
    m_bowlbuffer->Build();

    std::vector<VertexAttribute> v_layout;
    v_layout.emplace_back(0, "Position", AttributeType::Postion);
    v_layout.emplace_back(1, "TexCoords", AttributeType::TexCoords);
    VertexBufferLayout bufferLayout(v_layout);

    // 前
    std::vector<float> squareVertices;
    std::vector<unsigned int> squareIndices;
    m_bowlbuffer->getFrontPointBuffer(squareVertices);
    
    std::vector<PointTexture> ResultVertices;
    int offset = sizeof(Point)/sizeof(float);
    for (size_t i = 0; i < squareVertices.size()/offset; i++)
    {
        PointTexture pointTexture;
        pointTexture.world_x = squareVertices[i * offset + 0];
        pointTexture.world_y = squareVertices[i * offset + 1];
        pointTexture.world_z = squareVertices[i * offset + 2];
        Point point;
        point.world_x = squareVertices[i * offset + 0];
        point.world_y = squareVertices[i * offset + 1];
        point.world_z = squareVertices[i * offset + 2];
        m_camera->CalculatePointToUVForMei(m_camera->front_short_camera, point, pointTexture.texture_u, pointTexture.texture_v);
        ResultVertices.push_back(pointTexture);
    }
    
    m_frontbuffer = std::make_shared<VertexArray>();
    m_frontbuffer->Bind();
    m_frontbuffer->SetVBO((float*)&ResultVertices[0], ResultVertices.size() * sizeof(ResultVertices[0]), bufferLayout);
    m_bowlbuffer->getFrontIndexBuffer(squareIndices);
    m_frontbuffer->SetEBO(&squareIndices[0], squareIndices.size() * sizeof(unsigned int));
    m_frontbuffer->UnBind();

    // 右前
    squareVertices.clear();
    m_bowlbuffer->getFrontRightPointBuffer(squareVertices);
    
    ResultVertices.clear();
    for (size_t i = 0; i < squareVertices.size()/offset; i++)
    {
        PointTexture pointTexture;
        pointTexture.world_x = squareVertices[i * offset + 0];
        pointTexture.world_y = squareVertices[i * offset + 1];
        pointTexture.world_z = squareVertices[i * offset + 2];
        Point point;
        point.world_x = squareVertices[i * offset + 0];
        point.world_y = squareVertices[i * offset + 1];
        point.world_z = squareVertices[i * offset + 2];
        m_camera->CalculatePointToUVForMei(m_camera->front_short_camera, point, pointTexture.texture_u, pointTexture.texture_v);
        ResultVertices.push_back(pointTexture);
    }
    m_frontrightbuffer = std::make_shared<VertexArray>();
    m_frontrightbuffer->Bind();
    m_frontrightbuffer->SetVBO((float*)&ResultVertices[0], ResultVertices.size() * sizeof(ResultVertices[0]), bufferLayout);
    m_bowlbuffer->getFrontRightIndexBuffer(squareIndices);
    m_frontrightbuffer->SetEBO(&squareIndices[0], squareIndices.size() * sizeof(unsigned int));
    m_frontrightbuffer->UnBind();

    // 右
    squareVertices.clear();
    m_bowlbuffer->getRightPointBuffer(squareVertices);

    ResultVertices.clear();
    for (size_t i = 0; i < squareVertices.size()/offset; i++)
    {
        PointTexture pointTexture;
        pointTexture.world_x = squareVertices[i * offset + 0];
        pointTexture.world_y = squareVertices[i * offset + 1];
        pointTexture.world_z = squareVertices[i * offset + 2];
        Point point;
        point.world_x = squareVertices[i * offset + 0];
        point.world_y = squareVertices[i * offset + 1];
        point.world_z = squareVertices[i * offset + 2];
        m_camera->CalculatePointToUVForMei(m_camera->right_short_camera, point, pointTexture.texture_u, pointTexture.texture_v);
        ResultVertices.push_back(pointTexture);
    }
    m_rightbuffer = std::make_shared<VertexArray>();
    m_rightbuffer->Bind();
    m_rightbuffer->SetVBO((float*)&ResultVertices[0], ResultVertices.size() * sizeof(ResultVertices[0]), bufferLayout);
    m_bowlbuffer->getRightIndexBuffer(squareIndices);
    m_rightbuffer->SetEBO(&squareIndices[0], squareIndices.size() * sizeof(unsigned int));
    m_rightbuffer->UnBind();

    // 右后
    squareVertices.clear();
    m_bowlbuffer->getBackRightPointBuffer(squareVertices);

    ResultVertices.clear();
    for (size_t i = 0; i < squareVertices.size()/offset; i++)
    {
        PointTexture pointTexture;
        pointTexture.world_x = squareVertices[i * offset + 0];
        pointTexture.world_y = squareVertices[i * offset + 1];
        pointTexture.world_z = squareVertices[i * offset + 2];
        Point point;
        point.world_x = squareVertices[i * offset + 0];
        point.world_y = squareVertices[i * offset + 1];
        point.world_z = squareVertices[i * offset + 2];
        m_camera->CalculatePointToUVForMei(m_camera->rear_short_camera, point, pointTexture.texture_u, pointTexture.texture_v);
        ResultVertices.push_back(pointTexture);
    }
    m_backrightbuffer = std::make_shared<VertexArray>();
    m_backrightbuffer->Bind();
    m_backrightbuffer->SetVBO((float*)&ResultVertices[0], ResultVertices.size() * sizeof(ResultVertices[0]), bufferLayout);
    m_bowlbuffer->getBackRightIndexBuffer(squareIndices);
    m_backrightbuffer->SetEBO(&squareIndices[0], squareIndices.size() * sizeof(unsigned int));
    m_backrightbuffer->UnBind();

    // 后
    squareVertices.clear();
    m_bowlbuffer->getBackPointBuffer(squareVertices);

    ResultVertices.clear();
    for (size_t i = 0; i < squareVertices.size()/offset; i++)
    {
        PointTexture pointTexture;
        pointTexture.world_x = squareVertices[i * offset + 0];
        pointTexture.world_y = squareVertices[i * offset + 1];
        pointTexture.world_z = squareVertices[i * offset + 2];
        Point point;
        point.world_x = squareVertices[i * offset + 0];
        point.world_y = squareVertices[i * offset + 1];
        point.world_z = squareVertices[i * offset + 2];
        m_camera->CalculatePointToUVForMei(m_camera->rear_short_camera, point, pointTexture.texture_u, pointTexture.texture_v);
        ResultVertices.push_back(pointTexture);
    }
    m_backbuffer = std::make_shared<VertexArray>();
    m_backbuffer->Bind();
    m_backbuffer->SetVBO((float*)&ResultVertices[0], ResultVertices.size() * sizeof(ResultVertices[0]), bufferLayout);
    m_bowlbuffer->getBackIndexBuffer(squareIndices);
    m_backbuffer->SetEBO(&squareIndices[0], squareIndices.size() * sizeof(unsigned int));
    m_backbuffer->UnBind();

    // 左后
    squareVertices.clear();
    m_bowlbuffer->getBackLeftPointBuffer(squareVertices);

    ResultVertices.clear();
    for (size_t i = 0; i < squareVertices.size()/offset; i++)
    {
        PointTexture pointTexture;
        pointTexture.world_x = squareVertices[i * offset + 0];
        pointTexture.world_y = squareVertices[i * offset + 1];
        pointTexture.world_z = squareVertices[i * offset + 2];
        Point point;
        point.world_x = squareVertices[i * offset + 0];
        point.world_y = squareVertices[i * offset + 1];
        point.world_z = squareVertices[i * offset + 2];
        m_camera->CalculatePointToUVForMei(m_camera->rear_short_camera, point, pointTexture.texture_u, pointTexture.texture_v);
        ResultVertices.push_back(pointTexture);
    }
    m_backleftbuffer = std::make_shared<VertexArray>();
    m_backleftbuffer->Bind();
    m_backleftbuffer->SetVBO((float*)&ResultVertices[0], ResultVertices.size() * sizeof(ResultVertices[0]), bufferLayout);
    m_bowlbuffer->getBackLeftIndexBuffer(squareIndices);
    m_backleftbuffer->SetEBO(&squareIndices[0], squareIndices.size() * sizeof(unsigned int));
    m_backleftbuffer->UnBind();

    // 左
    squareVertices.clear();
    m_bowlbuffer->getLeftPointBuffer(squareVertices);

    ResultVertices.clear();
    for (size_t i = 0; i < squareVertices.size()/offset; i++)
    {
        PointTexture pointTexture;
        pointTexture.world_x = squareVertices[i * offset + 0];
        pointTexture.world_y = squareVertices[i * offset + 1];
        pointTexture.world_z = squareVertices[i * offset + 2];
        Point point;
        point.world_x = squareVertices[i * offset + 0];
        point.world_y = squareVertices[i * offset + 1];
        point.world_z = squareVertices[i * offset + 2];
        m_camera->CalculatePointToUVForMei(m_camera->left_short_camera, point, pointTexture.texture_u, pointTexture.texture_v);
        ResultVertices.push_back(pointTexture);
    }
    m_leftbuffer = std::make_shared<VertexArray>();
    m_leftbuffer->Bind();
    m_leftbuffer->SetVBO((float*)&ResultVertices[0], ResultVertices.size() * sizeof(ResultVertices[0]), bufferLayout);
    m_bowlbuffer->getLeftIndexBuffer(squareIndices);
    m_leftbuffer->SetEBO(&squareIndices[0], squareIndices.size() * sizeof(unsigned int));
    m_leftbuffer->UnBind();

    // 左前
    squareVertices.clear();
    m_bowlbuffer->getFrontLeftPointBuffer(squareVertices);
    
    ResultVertices.clear();
    for (size_t i = 0; i < squareVertices.size()/offset; i++)
    {
        PointTexture pointTexture;
        pointTexture.world_x = squareVertices[i * offset + 0];
        pointTexture.world_y = squareVertices[i * offset + 1];
        pointTexture.world_z = squareVertices[i * offset + 2];
        Point point;
        point.world_x = squareVertices[i * offset + 0];
        point.world_y = squareVertices[i * offset + 1];
        point.world_z = squareVertices[i * offset + 2];
        m_camera->CalculatePointToUVForMei(m_camera->front_short_camera, point, pointTexture.texture_u, pointTexture.texture_v);
        ResultVertices.push_back(pointTexture);
    }
    m_frontleftbuffer = std::make_shared<VertexArray>();
    m_frontleftbuffer->Bind();
    m_frontleftbuffer->SetVBO((float*)&ResultVertices[0], ResultVertices.size() * sizeof(ResultVertices[0]), bufferLayout);
    m_bowlbuffer->getFrontLeftIndexBuffer(squareIndices);
    m_frontleftbuffer->SetEBO(&squareIndices[0], squareIndices.size() * sizeof(unsigned int));
    m_frontleftbuffer->UnBind();
}

bool StandardBowlNode::Update()
{
    return true;
}

bool StandardBowlNode::Render()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    // render
    // ------
    // draw our first triangle
    m_shader->Use();
    m_shader->setUniformMat4("view", m_view);
    m_shader->setUniformMat4("model", m_model);
    m_shader->setUniformMat4("projection", m_projection);

    m_frontShortTexture->SetTexture2DUnit(TextureUnit::_0);

    m_frontbuffer->Bind();
    glDrawElements(GL_TRIANGLES, m_frontbuffer->GetEBO()->GetIndexNums(), GL_UNSIGNED_INT, nullptr);
    m_frontbuffer->UnBind();

    m_frontrightbuffer->Bind();
    glDrawElements(GL_TRIANGLES, m_frontrightbuffer->GetEBO()->GetIndexNums(), GL_UNSIGNED_INT, nullptr);
    m_frontrightbuffer->UnBind();

    m_rightShortTexture->SetTexture2DUnit(TextureUnit::_0);
    m_rightbuffer->Bind();
    glDrawElements(GL_TRIANGLES, m_rightbuffer->GetEBO()->GetIndexNums(), GL_UNSIGNED_INT, nullptr);
    m_rightbuffer->UnBind();

    m_rearShortTexture->SetTexture2DUnit(TextureUnit::_0);
    m_backrightbuffer->Bind();
    glDrawElements(GL_TRIANGLES, m_backrightbuffer->GetEBO()->GetIndexNums(), GL_UNSIGNED_INT, nullptr);
    m_backrightbuffer->UnBind();

    m_backbuffer->Bind();
    glDrawElements(GL_TRIANGLES, m_backbuffer->GetEBO()->GetIndexNums(), GL_UNSIGNED_INT, nullptr);
    m_backbuffer->UnBind();

    m_backleftbuffer->Bind();
    glDrawElements(GL_TRIANGLES, m_backleftbuffer->GetEBO()->GetIndexNums(), GL_UNSIGNED_INT, nullptr);
    m_backleftbuffer->UnBind();

    m_leftShortTexture->SetTexture2DUnit(TextureUnit::_0);
    m_leftbuffer->Bind();
    glDrawElements(GL_TRIANGLES, m_leftbuffer->GetEBO()->GetIndexNums(), GL_UNSIGNED_INT, nullptr);
    m_leftbuffer->UnBind();

    m_frontShortTexture->SetTexture2DUnit(TextureUnit::_0);
    m_frontleftbuffer->Bind();
    glDrawElements(GL_TRIANGLES, m_frontleftbuffer->GetEBO()->GetIndexNums(), GL_UNSIGNED_INT, nullptr);
    m_frontleftbuffer->UnBind();

	m_shader->UnUse();
    return true;
}

StandardBowlNode::~StandardBowlNode()
{
    m_shader  = nullptr;
    m_bowlbuffer = nullptr;
    m_camera = nullptr;

    m_frontbuffer = nullptr;
    m_frontrightbuffer = nullptr;
    m_rightbuffer = nullptr;
    m_backrightbuffer = nullptr;
    m_backbuffer = nullptr;
    m_backleftbuffer = nullptr;
    m_leftbuffer = nullptr;
    m_frontleftbuffer = nullptr;

    m_frontShortTexture = nullptr;
    m_rightShortTexture = nullptr;
    m_rearShortTexture  = nullptr;
    m_leftShortTexture  = nullptr;
}
