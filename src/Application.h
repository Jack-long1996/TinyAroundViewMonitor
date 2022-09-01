#ifndef APPLICATION_H
#define APPLICATION_H

#include "Platform/platform.h"
#include "Scene/Scene.h"

//--------------------------------------------------------------------------------------
// Name: class Application()
// Desc: Application class
//--------------------------------------------------------------------------------------
class Application
{
public:
    Application(std::string strName);
    bool Initialize();
    bool Update();
    bool Destroy();
    ~Application();
private:
    std::shared_ptr<Scene> m_scene;

private:
    bool CreateRenderContext();
    void DestroyRenderContext();
    void SwapDrawBuffers();

    std::string m_strName;
    uint64_t    m_nWidth;
    uint64_t    m_nHeight;
    GLFWwindow* m_glfwWindow;
};

//--------------------------------------------------------------------------------------
// Name: FrmCreateApplicationInstance()
// Desc: Global function to create the application instance
//--------------------------------------------------------------------------------------
extern Application* FrmCreateApplicationInstance();

#endif // APPLICATION_H