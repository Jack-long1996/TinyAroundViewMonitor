#include "SimulationCarNode.h"

#include <memory>

SimulationCarNode::SimulationCarNode()
{
    m_shader = nullptr;
    m_buffer = nullptr;
    m_light = nullptr;
    m_material = nullptr;

    m_light = std::make_shared<Light>();
    m_material = std::make_shared<Material>();

    m_positionCenter = glm::vec3(0.0f, 0.0f, 0.5f);
    m_widthRadius = 2.25f/2.0f;          
    m_lengthRadius = 4.95f/2.0f;         
    m_highthRadius = 0.5f;         

    // build and compile our shader zprogram
    // ------------------------------------
    m_shader = std::make_shared<Shader>("../source/shader/SimulationCarShader.vs","../source/shader/SimulationCarShader.fs");

    std::vector<VertexAttribute> v_layout;
    v_layout.emplace_back(0, "Position", AttributeType::Postion);
    v_layout.emplace_back(1, "Normal", AttributeType::Normal);
    VertexBufferLayout bufferLayout(v_layout);

    m_buffer = std::make_shared<VertexArray>();
    m_buffer->Bind();

    // 顶点数据
    std::vector<glm::vec3> vertices;
    vertices.emplace_back(m_positionCenter.x - m_lengthRadius, m_positionCenter.y + m_widthRadius, m_positionCenter.z - m_highthRadius);
    vertices.emplace_back(m_positionCenter.x + m_lengthRadius, m_positionCenter.y + m_widthRadius, m_positionCenter.z - m_highthRadius);
    vertices.emplace_back(m_positionCenter.x + m_lengthRadius, m_positionCenter.y - m_widthRadius, m_positionCenter.z - m_highthRadius);
    vertices.emplace_back(m_positionCenter.x - m_lengthRadius, m_positionCenter.y - m_widthRadius, m_positionCenter.z - m_highthRadius);
    vertices.emplace_back(m_positionCenter.x - m_lengthRadius, m_positionCenter.y - m_widthRadius, m_positionCenter.z + m_highthRadius);
    vertices.emplace_back(m_positionCenter.x - m_lengthRadius, m_positionCenter.y + m_widthRadius, m_positionCenter.z + m_highthRadius);
    vertices.emplace_back(m_positionCenter.x + m_lengthRadius, m_positionCenter.y + m_widthRadius, m_positionCenter.z + m_highthRadius);
    vertices.emplace_back(m_positionCenter.x + m_lengthRadius, m_positionCenter.y - m_widthRadius, m_positionCenter.z + m_highthRadius);
    
    // float squareVertices[] = {
    //     m_positionCenter.x - m_lengthRadius, m_positionCenter.y + m_widthRadius, m_positionCenter.z - m_highthRadius,  // bottom left  down 0
    //     m_positionCenter.x + m_lengthRadius, m_positionCenter.y + m_widthRadius, m_positionCenter.z - m_highthRadius,  // bottom left  up   1
    //     m_positionCenter.x + m_lengthRadius, m_positionCenter.y - m_widthRadius, m_positionCenter.z - m_highthRadius,  // bottom right up   2
    //     m_positionCenter.x - m_lengthRadius, m_positionCenter.y - m_widthRadius, m_positionCenter.z - m_highthRadius,  // bottom right down 3
    //     m_positionCenter.x - m_lengthRadius, m_positionCenter.y - m_widthRadius, m_positionCenter.z + m_highthRadius,  // top    right down 4
    //     m_positionCenter.x - m_lengthRadius, m_positionCenter.y + m_widthRadius, m_positionCenter.z + m_highthRadius,  // top    left  down 5
    //     m_positionCenter.x + m_lengthRadius, m_positionCenter.y + m_widthRadius, m_positionCenter.z + m_highthRadius,  // top    left  up   6
    //     m_positionCenter.x + m_lengthRadius, m_positionCenter.y - m_widthRadius, m_positionCenter.z + m_highthRadius   // top    right up   7
    // };
    // 索引数据
    // unsigned int squareIndices[] = {
	// 	0, 1, 2, 2, 3, 0,    // 底面
    //     0, 5, 4, 4, 3, 0,    // 正面
    //     1, 6, 5, 5, 0, 1,    // 左面
    //     2, 7, 6, 6, 1, 2,    // 背面
    //     3, 4, 7, 7, 2, 3,    // 右面
    //     5, 6, 7, 7, 4, 5     // 顶面
    // };

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float squareVertices[] = {
        // 底面
        vertices[0].x, vertices[0].y, vertices[0].z, 0.0f,  0.0f, -1.0f,
        vertices[1].x, vertices[1].y, vertices[1].z, 0.0f,  0.0f, -1.0f,
        vertices[2].x, vertices[2].y, vertices[2].z, 0.0f,  0.0f, -1.0f,
        vertices[2].x, vertices[2].y, vertices[2].z, 0.0f,  0.0f, -1.0f,
        vertices[3].x, vertices[3].y, vertices[3].z, 0.0f,  0.0f, -1.0f,
        vertices[0].x, vertices[0].y, vertices[0].z, 0.0f,  0.0f, -1.0f,

        // 正面
        vertices[0].x, vertices[0].y, vertices[0].z, -1.0f,  0.0f,  0.0f,
        vertices[5].x, vertices[5].y, vertices[5].z, -1.0f,  0.0f,  0.0f,
        vertices[4].x, vertices[4].y, vertices[4].z, -1.0f,  0.0f,  0.0f,
        vertices[4].x, vertices[4].y, vertices[4].z, -1.0f,  0.0f,  0.0f,
        vertices[3].x, vertices[3].y, vertices[3].z, -1.0f,  0.0f,  0.0f,
        vertices[0].x, vertices[0].y, vertices[0].z, -1.0f,  0.0f,  0.0f,

        // 左面
        vertices[1].x, vertices[1].y, vertices[1].z, 0.0f,  1.0f,  0.0f,
        vertices[6].x, vertices[6].y, vertices[6].z, 0.0f,  1.0f,  0.0f,
        vertices[5].x, vertices[5].y, vertices[5].z, 0.0f,  1.0f,  0.0f,
        vertices[5].x, vertices[5].y, vertices[5].z, 0.0f,  1.0f,  0.0f,
        vertices[0].x, vertices[0].y, vertices[0].z, 0.0f,  1.0f,  0.0f,
        vertices[1].x, vertices[1].y, vertices[1].z, 0.0f,  1.0f,  0.0f,

        // 背面
        vertices[2].x, vertices[2].y, vertices[2].z, 1.0f,  0.0f,  0.0f,
        vertices[7].x, vertices[7].y, vertices[7].z, 1.0f,  0.0f,  0.0f,
        vertices[6].x, vertices[6].y, vertices[6].z, 1.0f,  0.0f,  0.0f,
        vertices[6].x, vertices[6].y, vertices[6].z, 1.0f,  0.0f,  0.0f,
        vertices[1].x, vertices[1].y, vertices[1].z, 1.0f,  0.0f,  0.0f,
        vertices[2].x, vertices[2].y, vertices[2].z, 1.0f,  0.0f,  0.0f,

        // 右面
        vertices[3].x, vertices[3].y, vertices[3].z, 0.0f, -1.0f,  0.0f,
        vertices[4].x, vertices[4].y, vertices[4].z, 0.0f, -1.0f,  0.0f,
        vertices[7].x, vertices[7].y, vertices[7].z, 0.0f, -1.0f,  0.0f,
        vertices[7].x, vertices[7].y, vertices[7].z, 0.0f, -1.0f,  0.0f,
        vertices[2].x, vertices[2].y, vertices[2].z, 0.0f, -1.0f,  0.0f,
        vertices[3].x, vertices[3].y, vertices[3].z, 0.0f, -1.0f,  0.0f,

        // 顶面
        vertices[5].x, vertices[5].y, vertices[5].z, 0.0f,  0.0f,  1.0f,
        vertices[6].x, vertices[6].y, vertices[6].z, 0.0f,  0.0f,  1.0f,
        vertices[7].x, vertices[7].y, vertices[7].z, 0.0f,  0.0f,  1.0f,
        vertices[7].x, vertices[7].y, vertices[7].z, 0.0f,  0.0f,  1.0f,
        vertices[4].x, vertices[4].y, vertices[4].z, 0.0f,  0.0f,  1.0f,
        vertices[5].x, vertices[5].y, vertices[5].z, 0.0f,  0.0f,  1.0f
    };

    m_buffer->SetVBO(squareVertices, sizeof(squareVertices), bufferLayout);

    m_buffer->UnBind();
}

bool SimulationCarNode::Update()
{
    m_light->Update();
    return true;
}

bool SimulationCarNode::Render()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    // render
    // ------    
    m_shader->Use();
    m_shader->setUniformMat4("view", m_view);
    m_shader->setUniformMat4("model", m_model);
    m_shader->setUniformMat4("projection", m_projection);

    // light properties
    m_shader->setUniformVec3("light.position", m_light->GetPosition());
    m_shader->setUniformVec3("light.ambient", m_light->GetAmbient());
    m_shader->setUniformVec3("light.diffuse", m_light->GetDiffuse());
    m_shader->setUniformVec3("light.specular", m_light->GetSpecular());

    // material properties
    m_shader->setUniformVec3("material.ambient",m_material->GetAmbient());
    m_shader->setUniformVec3("material.diffuse", m_material->GetDiffuse());
    m_shader->setUniformVec3("material.specular", m_material->GetSpecular());
    m_shader->setUniformFloat("material.shininess", m_material->GetShininess());

    m_shader->setUniformVec3("viewPos", m_cameraPosition);
    m_buffer->Bind();
    glDrawArrays(GL_TRIANGLES, 0, m_buffer->GetVBO()->GetVertexNums());
    m_buffer->UnBind();
	m_shader->UnUse();
    return true;
}

SimulationCarNode::~SimulationCarNode()
{
    m_shader = nullptr;
    m_buffer = nullptr;
}