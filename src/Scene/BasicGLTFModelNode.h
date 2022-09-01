#ifndef BASICGLTFMODELNODE_H
#define BASICGLTFMODELNODE_H

#include "../Platform/platform.h"
#include "../Core/shader/Shader.h"
#include "../Core/texture/Texture.h"
#include "../Core/buffer/Buffer.h"
#include "Node.h"
#include "tiny_gltf.h"


//--------------------------------------------------------------------------------------
// Name: class BasicGLTFModelNode()
// Desc: BasicGLTFModelNode class
//--------------------------------------------------------------------------------------
class BasicGLTFModelNode : public Node
{
public:
    BasicGLTFModelNode();
    bool Update() override;
    bool Render() override;    
    ~BasicGLTFModelNode();

    inline void SetProjection(glm::mat4 &projection) {m_projection = projection;};
    inline void SetView(glm::mat4 &view) {m_view = view;};
    inline void SetModel(glm::mat4 &model) {m_model = model;};
    inline void SetCameraPosition(glm::vec3 &position) {m_cameraPosition = position;};

private:
    std::string m_filename;
    std::shared_ptr<Shader> m_shader;

    glm::vec3 m_sun_position;
    glm::vec3 m_sun_color;

    glm::vec3 m_cameraPosition;
    glm::mat4 m_projection;
    glm::mat4 m_view;
    glm::mat4 m_model;
    tinygltf::Model model;
    std::pair<GLuint, std::map<int, GLuint>> vaoAndEbos;
};

#endif // BASICGLTFMODELNODE_H