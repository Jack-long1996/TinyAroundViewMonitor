#ifndef LIGHTCUBENODE_H
#define LIGHTCUBENODE_H

#include "../Platform/platform.h"
#include "../Core/buffer/Buffer.h"
#include "../Core/shader/Shader.h"
#include "Node.h"

//--------------------------------------------------------------------------------------
// Name: class LightCubeNode()
// Desc: LightCubeNode class
//--------------------------------------------------------------------------------------
class LightCubeNode : public Node
{
public:
    LightCubeNode();
    bool Update() override;
    bool Render() override;
    inline void SetProjection(glm::mat4 &projection) {m_projection = projection;};
    inline void SetView(glm::mat4 &view) {m_view = view;};
    inline void SetModel(glm::mat4 &model) {m_model = model;};
    inline void SetPosition(glm::vec3 position) {m_positionCenter = position;};
    ~LightCubeNode();

private:
    std::shared_ptr<Shader>        m_shader;
    std::shared_ptr<VertexArray>   m_buffer;

    glm::vec3 m_positionCenter{};    // 模拟光源的中心位置
    float m_radius;                // 模拟光源的半径
    
    glm::mat4 m_projection{};
    glm::mat4 m_view{};
    glm::mat4 m_model{};
};

#endif // LIGHTCUBENODE_H