#ifndef SIMULATIONCARNODE_H
#define SIMULATIONCARNODE_H

#include "../Platform/platform.h"
#include "../Core/buffer/Buffer.h"
#include "../Core/shader/Shader.h"
#include "../Core/Light/Light.h"
#include "../Core/Material/Material.h"
#include "Node.h"

//--------------------------------------------------------------------------------------
// Name: class SimulationCarNode()
// Desc: SimulationCarNode class
//--------------------------------------------------------------------------------------
class SimulationCarNode : public Node
{
public:
    SimulationCarNode();
    bool Update() override;
    bool Render() override;
    inline void SetProjection(glm::mat4 &projection) {m_projection = projection;};
    inline void SetView(glm::mat4 &view) {m_view = view;};
    inline void SetModel(glm::mat4 &model) {m_model = model;};
    inline void SetCameraPosition(glm::vec3 &position) {m_cameraPosition = position;};
    ~SimulationCarNode();

public:
    std::shared_ptr<Light>       m_light;

private:
    std::shared_ptr<Shader>      m_shader;
    std::shared_ptr<VertexArray> m_buffer;
    // std::shared_ptr<Light>       m_light;
    std::shared_ptr<Material>    m_material;

    glm::vec3 m_positionCenter{};    // 中心位置
    float m_widthRadius;           // 
    float m_lengthRadius;          // 
    float m_highthRadius;          // 
    
    glm::vec3 m_cameraPosition{};
    glm::mat4 m_projection{};
    glm::mat4 m_view{};
    glm::mat4 m_model{};
};

#endif // SIMULATIONCARNODE_H