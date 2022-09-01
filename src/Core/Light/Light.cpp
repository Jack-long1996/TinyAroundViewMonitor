#include "Light.h"

//--------------------------------------------------------------------------------------
// Name: Light()
// Desc: Construction the Light base class. The default values can be overrided
//       by the derived class.
//--------------------------------------------------------------------------------------
Light::Light()
{
    m_position = glm::vec3(5.0f, 0.0f, 3.0f);
    m_ambient = glm::vec3(0.2f, 0.2f, 0.2f);
    m_diffuse = glm::vec3(0.5f, 0.5f, 0.5f);
    m_specular = glm::vec3(1.0f, 1.0f, 1.0f);
}

bool Light::Update()
{
    // m_position = glm::vec3(5.0f, 0.0f, 3.0f);
    m_position.x = sin(glfwGetTime()) * 10.0f;
    m_position.y = sin(glfwGetTime()) * 5.0f;
    // m_position.z = sin(glfwGetTime());
    return true;
}
//--------------------------------------------------------------------------------------
// Name: Light()
// Desc: Construction the Light base class. The default values can be overrided
//       by the derived class.
//--------------------------------------------------------------------------------------
Light::~Light()
{

}