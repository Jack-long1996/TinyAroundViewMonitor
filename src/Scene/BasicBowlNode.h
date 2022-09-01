#ifndef BASICBOWLNODE_H
#define BASICBOWLNODE_H

#include "../Platform/platform.h"
#include "../Core/buffer/Buffer.h"
#include "../Core/shader/Shader.h"
#include "../Bowl/AVMBowlBuffer.h"
#include "Node.h"

//--------------------------------------------------------------------------------------
// Name: class BasicBowlNode()
// Desc: BasicBowlNode class
//--------------------------------------------------------------------------------------
class BasicBowlNode : public Node
{
public:
    BasicBowlNode();
    bool Update() override;
    bool Render() override;
    inline void SetProjection(glm::mat4 &projection) {m_projection = projection;};
    inline void SetView(glm::mat4 &view) {m_view = view;};
    inline void SetModel(glm::mat4 &model) {m_model = model;};
    
    ~BasicBowlNode();
private:
    std::shared_ptr<AVMBowlBuffer> m_bowlbuffer;
    std::shared_ptr<Shader>        m_shader;
    std::shared_ptr<VertexArray>   m_buffer;
    
    glm::mat4 m_projection{};
    glm::mat4 m_view{};
    glm::mat4 m_model{};
};

#endif // BASICBOWLNODE_H
