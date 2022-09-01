#ifndef STANDARDBOWLNODE_H
#define STANDARDBOWLNODE_H

#include "../Platform/platform.h"
#include "../Core/buffer/Buffer.h"
#include "../Core/shader/Shader.h"
#include "../Core/texture/Texture.h"
#include "../Bowl/AVMBowlBuffer.h"
#include "../Bowl/AVMCamera.h"
#include "Node.h"

struct PointTexture {
    float world_x;
    float world_y;
    float world_z;
    float texture_u;
    float texture_v;
    
    PointTexture() {
        world_x = 0.0f;
        world_y = 0.0f;
        world_z = 0.0f;
        texture_u = 0.0f;
        texture_v = 0.0f;
    }
};

//--------------------------------------------------------------------------------------
// Name: class StandardBowlNode()
// Desc: StandardBowlNode class
//--------------------------------------------------------------------------------------
class StandardBowlNode : public Node
{
public:
    StandardBowlNode();
    bool Update() override;
    bool Render() override;
    inline void SetProjection(glm::mat4 &projection) {m_projection = projection;};
    inline void SetView(glm::mat4 &view) {m_view = view;};
    inline void SetModel(glm::mat4 &model) {m_model = model;};
    
    ~StandardBowlNode();
private:
    std::shared_ptr<AVMBowlBuffer> m_bowlbuffer;
    std::shared_ptr<AVMCamera>     m_camera;
    std::shared_ptr<Shader>        m_shader;

    std::shared_ptr<VertexArray>   m_frontbuffer;
    std::shared_ptr<VertexArray>   m_frontrightbuffer;
    std::shared_ptr<VertexArray>   m_rightbuffer;
    std::shared_ptr<VertexArray>   m_backrightbuffer;
    std::shared_ptr<VertexArray>   m_backbuffer;
    std::shared_ptr<VertexArray>   m_backleftbuffer;
    std::shared_ptr<VertexArray>   m_leftbuffer;
    std::shared_ptr<VertexArray>   m_frontleftbuffer;

    std::shared_ptr<Texture>       m_frontShortTexture;
    std::shared_ptr<Texture>       m_rightShortTexture;
    std::shared_ptr<Texture>       m_rearShortTexture;
    std::shared_ptr<Texture>       m_leftShortTexture;
    
    glm::mat4 m_projection{};
    glm::mat4 m_view{};
    glm::mat4 m_model{};
};

#endif // STANDARDBOWLNODE_H