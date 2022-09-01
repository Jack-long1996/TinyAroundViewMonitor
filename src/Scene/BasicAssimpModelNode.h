#ifndef BASICASSIMPMODELNODE_H
#define BASICASSIMPMODELNODE_H

#include "../Platform/platform.h"
#include "../Core/shader/Shader.h"
#include "Node.h"

//--------------------------------------------------------------------------------------
// Name: class BasicAssimpModelNode()
// Desc: BasicAssimpModelNode class
//--------------------------------------------------------------------------------------
class BasicAssimpModelNode : public Node
{
public:
    BasicAssimpModelNode();
    bool Update() override;
    bool Render() override;    
    ~BasicAssimpModelNode();

    inline void SetProjection(glm::mat4 &projection) {m_projection = projection;};
    inline void SetView(glm::mat4 &view) {m_view = view;};
    inline void SetModel(glm::mat4 &model) {m_model = model;};

private:
    std::string m_filename;
    std::shared_ptr<Shader> m_shader;

    glm::mat4 m_projection{};
    glm::mat4 m_view{};
    glm::mat4 m_model{};
};

#endif // BASICASSIMPMODELNODE_H