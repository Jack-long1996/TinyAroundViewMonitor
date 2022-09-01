#include "Material.h"

//--------------------------------------------------------------------------------------
// Name: Material()
// Desc: Construction the Material base class. The default values can be overrided
//       by the derived class.
//--------------------------------------------------------------------------------------
Material::Material()
{
    m_ambient = glm::vec3(220.0f/255.0f, 221.0f/255.0f, 227.0f/255.0f);
    m_diffuse = glm::vec3(220.0f/255.0f, 221.0f/255.0f, 227.0f/255.0f);
    m_specular = glm::vec3(220.0f/255.0f, 221.0f/255.0f, 227.0f/255.0f);
    m_shininess = 32.0f;
}

//--------------------------------------------------------------------------------------
// Name: Material()
// Desc: Construction the Material base class. The default values can be overrided
//       by the derived class.
//--------------------------------------------------------------------------------------
Material::~Material()
{

}
