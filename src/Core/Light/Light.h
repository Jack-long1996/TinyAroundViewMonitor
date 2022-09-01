#ifndef LIGHT_H
#define LIGHT_H

#include "../../Platform/platform.h"

class Light
{
public:
	Light();
    inline void SetPosition(glm::vec3 &position) {m_position = position;};
    inline void SetAmbient(glm::vec3 &ambient) {m_ambient = ambient;};
    inline void SetDiffuse(glm::vec3 &diffuse) {m_diffuse = diffuse;};
    inline void SetSpecular(glm::vec3 &specular) {m_specular = specular;};

    inline glm::vec3 GetPosition() {return m_position;};
    inline glm::vec3 GetAmbient() {return m_ambient;};
    inline glm::vec3 GetDiffuse() {return m_diffuse;};
    inline glm::vec3 GetSpecular() {return m_specular;};
    bool Update();
	~Light();
private:
	glm::vec3 m_position;  // 光源位置
    glm::vec3 m_ambient;   // 环境光照(Ambient Lighting)强度
    glm::vec3 m_diffuse;   // 漫反射光照(Diffuse Lighting)强度
    glm::vec3 m_specular;  // 镜面光照(Specular Lighting)强度
};

#endif /* LIGHT_H*/