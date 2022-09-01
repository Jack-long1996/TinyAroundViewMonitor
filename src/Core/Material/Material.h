#ifndef MATERIAL_H
#define MATERIAL_H

#include "../../Platform/platform.h"

class Material
{
public:
	Material();
    inline void SetAmbient(glm::vec3 &ambient) {m_ambient = ambient;};
    inline void SetDiffuse(glm::vec3 &diffuse) {m_diffuse = diffuse;};
    inline void SetSpecular(glm::vec3 &specular) {m_specular = specular;};
    inline void SetShininess(float &shininess) {m_shininess = shininess;};

    inline glm::vec3 GetAmbient() {return m_ambient;};
    inline glm::vec3 GetDiffuse() {return m_diffuse;};
    inline glm::vec3 GetSpecular() {return m_specular;};
    inline float GetShininess() {return m_shininess;};
	~Material();
private:
    // ambient材质向量定义了在环境光照下这个表面反射的是什么颜色，通常与表面的颜色相同。
    glm::vec3 m_ambient;   // 环境光照(Ambient Lighting)

    // diffuse材质向量定义了在漫反射光照下表面的颜色。漫反射颜色（和环境光照一样）也被设置为我们期望的物体颜色。
    glm::vec3 m_diffuse;   // 漫反射光照(Diffuse Lighting)

    // specular材质向量设置的是表面上镜面高光的颜色（或者甚至可能反映一个特定表面的颜色）
    glm::vec3 m_specular;  // 镜面光照(Specular Lighting)

    // shininess影响镜面高光的散射/半径。
    float m_shininess;
};

#endif /* MATERIAL_H*/