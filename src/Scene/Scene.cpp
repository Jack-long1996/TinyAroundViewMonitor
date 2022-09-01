#include "Scene.h"

#include <memory>
#include <utility>
//--------------------------------------------------------------------------------------
// Name: Scene()
// Desc: Construction the Scene base class. The default values can be overrided
//       by the derived class.
//--------------------------------------------------------------------------------------
Scene::Scene(std::string strName, int width, int height)
    : m_strName(std::move(strName)),
    m_nWidth(width),
    m_nHeight(height)
{
    m_basicBowlNode = nullptr;
    m_basicBowlNode = std::make_shared<BasicBowlNode>();
    m_nodes.push_back(m_basicBowlNode);

    // m_standardBowlNode = nullptr;
    // m_standardBowlNode = std::make_shared<StandardBowlNode>();
    // m_nodes.push_back(m_standardBowlNode);

    // m_lightCubeNode = nullptr;
    // m_lightCubeNode = std::make_shared<LightCubeNode>();
    // m_nodes.push_back(m_lightCubeNode);

    // m_simulationCarNode = nullptr;
    // m_simulationCarNode = std::make_shared<SimulationCarNode>();
    // m_nodes.push_back(m_simulationCarNode);

    // m_basicGLTFModelNode = nullptr;
    // m_basicGLTFModelNode = std::make_shared<BasicGLTFModelNode>();
    // m_nodes.push_back(m_basicGLTFModelNode);

    m_basicAssimpModelNode = nullptr;
    m_basicAssimpModelNode = std::make_shared<BasicAssimpModelNode>();
    m_nodes.push_back(m_basicAssimpModelNode);
}

bool Scene::Update()
{
    for (const auto& node : m_nodes) {
        node->Update();
    }
    return true;
}

bool Scene::Render()
{
    // pass projection matrix to shader (note that in this case it could change every frame)
    m_projection = glm::perspective(glm::radians(45.0f), (float)m_nWidth / (float)m_nHeight, 0.1f, 100.0f);

    // camera/view transformation
    m_view = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first

    // camera
    glm::vec3 cameraPos    = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 cameraCenter = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 cameraUp     = glm::vec3(0.0f, 0.0f, 0.0f);

    cameraPos.x = static_cast<float>(m_fRadius * glm::sin(m_fPitchAngle) * glm::cos(m_fRotationAngle));
    cameraPos.y = static_cast<float>(m_fRadius * glm::sin(m_fPitchAngle) * glm::sin(m_fRotationAngle));
    cameraPos.z = static_cast<float>(m_fRadius * glm::cos(m_fPitchAngle));

    glm::vec3 front;
    front.x = static_cast<float>(0.0f - glm::sin(m_fPitchAngle) * glm::cos(m_fRotationAngle));
    front.y = static_cast<float>(0.0f - glm::sin(m_fPitchAngle) * glm::sin(m_fRotationAngle));
    front.z = static_cast<float>(glm::sin(m_fPitchAngle));
    cameraUp = glm::normalize(front);

    m_view = glm::lookAt(cameraPos, cameraCenter, cameraUp);

    // calculate the model matrix for each object and pass it to shader before drawing
    m_model = glm::mat4(1.0f);
    // 平移
    m_model = glm::translate(m_model, glm::vec3(0.0f, 0.0f, 0.0f));
    // 缩放
    m_model = glm::scale(m_model, glm::vec3(1.0f)); 
    // 旋转
    // model = glm::rotate(model, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 0.0f));

    m_basicBowlNode->SetView(m_view);
    m_basicBowlNode->SetModel(m_model);
    m_basicBowlNode->SetProjection(m_projection);

    // m_standardBowlNode->SetView(m_view);
    // m_standardBowlNode->SetModel(m_model);
    // m_standardBowlNode->SetProjection(m_projection);

    // m_lightCubeNode->SetView(m_view);
    // m_lightCubeNode->SetModel(m_model);
    // m_lightCubeNode->SetProjection(m_projection);
    // m_lightCubeNode->SetPosition(m_simulationCarNode->m_light->GetPosition());

    // m_simulationCarNode->SetView(m_view);
    // m_simulationCarNode->SetModel(m_model);
    // m_simulationCarNode->SetProjection(m_projection);
    // m_simulationCarNode->SetCameraPosition(cameraPos);

    // m_basicGLTFModelNode->SetView(m_view);
    // m_basicGLTFModelNode->SetModel(m_model);
    // m_basicGLTFModelNode->SetProjection(m_projection);
    // m_basicGLTFModelNode->SetCameraPosition(cameraPos);

    m_basicAssimpModelNode->SetView(m_view);
    m_basicAssimpModelNode->SetModel(m_model);
    m_basicAssimpModelNode->SetProjection(m_projection);

    for (const auto& node : m_nodes) {
        node->Render();
    }
    return true;
}

//--------------------------------------------------------------------------------------
// Name: ~Scene()
// Desc: Destructor
//--------------------------------------------------------------------------------------
Scene::~Scene()
{
    m_basicBowlNode = nullptr;
    m_standardBowlNode = nullptr;
    m_lightCubeNode = nullptr;
    m_simulationCarNode = nullptr;
    m_basicGLTFModelNode = nullptr;
    m_nodes.clear();
}