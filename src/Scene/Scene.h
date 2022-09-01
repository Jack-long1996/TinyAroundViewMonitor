#ifndef SCENE_H
#define SCENE_H

#include "../Platform/platform.h"
#include "BasicBowlNode.h"
#include "StandardBowlNode.h"
#include "LightCubeNode.h"
#include "SimulationCarNode.h"
#include "BasicGLTFModelNode.h"
#include "BasicAssimpModelNode.h"
#include "Node.h"

//--------------------------------------------------------------------------------------
// Name: class Scene()
// Desc: Scene class
//--------------------------------------------------------------------------------------
class Scene
{
public:
    Scene(std::string strName, int width, int height);
    bool Update();
    bool Render();
    inline void SetRadius(float Radius) {m_fRadius = Radius;};
    inline void SetRotationAngle(float RotationAngle) {m_fRotationAngle = RotationAngle;};
    inline void SetPitchAngle(float PitchAngle) {m_fPitchAngle = PitchAngle;};
    ~Scene();
private:
    std::vector<std::shared_ptr<Node>> m_nodes;
    std::shared_ptr<BasicBowlNode>     m_basicBowlNode;
    std::shared_ptr<StandardBowlNode>  m_standardBowlNode;
    std::shared_ptr<LightCubeNode>     m_lightCubeNode;
    std::shared_ptr<SimulationCarNode> m_simulationCarNode;
    std::shared_ptr<BasicGLTFModelNode> m_basicGLTFModelNode;
    std::shared_ptr<BasicAssimpModelNode> m_basicAssimpModelNode;
    std::string                        m_strName;
    int    m_nWidth;
    int    m_nHeight;
    
    float  m_fRadius{};        // 半径
    float  m_fRotationAngle{}; // 旋转角
    float  m_fPitchAngle{};    // 俯仰角

    glm::mat4 m_projection{};
    glm::mat4 m_view{};
    glm::mat4 m_model{};
};

#endif // SCENE_H