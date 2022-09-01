#include "Application.h"

#include <memory>
#include <utility>

// 圆周率
const float pai = 3.141592657932385f;
// 半径
float g_fRadius = 16.0f;
// 旋转角
float g_fRotationAngle = pai;
// 俯仰角
float g_fPitchAngle = 0.25f * pai;
// 鼠标左键是否使能
bool g_bMouseButtonEnable = false;
// 灵明度设置
const float g_fSensitivity = 0.01f;

float g_fLastX = 0.0f;
float g_fLastY = 0.0f;

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    auto xpos = static_cast<float>(xposIn);
    auto ypos = static_cast<float>(yposIn);
    float xoffset = xpos - g_fLastX;
    float yoffset = ypos - g_fLastY; // reversed since y-coordinates go from bottom to top
    g_fLastX = xpos;
    g_fLastY = ypos;
    
    xoffset *= g_fSensitivity;
    yoffset *= g_fSensitivity;

    if (g_bMouseButtonEnable) 
    {
        g_fRotationAngle += xoffset;
        g_fPitchAngle    += yoffset;

        // make sure that when pitch is out of bounds, screen doesn't get flipped
        if (g_fRotationAngle > 2.0f * pai) {
            g_fRotationAngle = 0.01f;
        } else if (g_fRotationAngle < 0.01f) {
            g_fRotationAngle = 2.0f * pai;
        } 
            
        // make sure that when pitch is out of bounds, screen doesn't get flipped
        if (g_fPitchAngle > 0.5f * pai) {
            g_fPitchAngle = 0.5f * pai;
        } else if (g_fPitchAngle < 0.01f) {
            g_fPitchAngle = 0.01f;
        }
    }
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    if(g_fRadius >= 5.0f && g_fRadius <= 16.0f)
        g_fRadius -= yoffset;
    if(g_fRadius <= 5.0f)
        g_fRadius = 5.0f;
    if(g_fRadius >= 16.0f)
        g_fRadius = 16.0f;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) 
{
    if (action == GLFW_PRESS) 
    {
        switch(button)
        {
            case GLFW_MOUSE_BUTTON_LEFT:
                std::cout << "Mosue left button clicked!" << std::endl;
                g_bMouseButtonEnable = true;
                break;
            case GLFW_MOUSE_BUTTON_MIDDLE:
                std::cout << "Mosue middle button clicked!" << std::endl;
                break;
            case GLFW_MOUSE_BUTTON_RIGHT:
                std::cout << "Mosue right button clicked!" << std::endl;
                ;
            default:
                return;
        }
    } else if (action == GLFW_RELEASE) {
        switch(button)
        {
            case GLFW_MOUSE_BUTTON_LEFT:
                std::cout << "Mosue left button realseed!" << std::endl;
                g_bMouseButtonEnable = false;
                break;
            case GLFW_MOUSE_BUTTON_MIDDLE:
                std::cout << "Mosue middle button realseed!" << std::endl;
                break;
            case GLFW_MOUSE_BUTTON_RIGHT:
                std::cout << "Mosue right button realseed!" << std::endl;
                ;
            default:
                return;
        }
    }
	return;
}

//--------------------------------------------------------------------------------------
// Name: Application()
// Desc: Construction the application base class. The default values can be overrided
//       by the derived class.
//--------------------------------------------------------------------------------------
Application::Application(std::string strName)
    : m_strName(std::move(strName))
{
    m_nWidth  = 800;
    m_nHeight = 600;
    m_glfwWindow = nullptr;
    m_scene = nullptr;
}

//--------------------------------------------------------------------------------------
// Name: Initialize()
// Desc: 初始化窗口，创建context，创建场景
//--------------------------------------------------------------------------------------
bool Application::Initialize()
{
    if(!CreateRenderContext()){
        return false;
    }

    m_scene = std::make_shared<Scene>(m_strName, m_nWidth, m_nHeight);
    return true;
}

//--------------------------------------------------------------------------------------
// Name: Update()
// Desc: 更新窗口，更新场景
//--------------------------------------------------------------------------------------
bool Application::Update()
{   
    // render loop
    // -----------
    while (!glfwWindowShouldClose(m_glfwWindow))
    {
        // update
        m_scene->SetRadius(g_fRadius);
        m_scene->SetRotationAngle(g_fRotationAngle);
        m_scene->SetPitchAngle(g_fPitchAngle);
        m_scene->Update();
        // render
        m_scene->Render();
        SwapDrawBuffers();
    }
    return true;
}

//--------------------------------------------------------------------------------------
// Name: Destroy()
// Desc: 销毁场景，销毁context
//--------------------------------------------------------------------------------------
bool Application::Destroy()
{
    // Destroy the Scene
    m_scene = nullptr;
    // Destroy the render context
    DestroyRenderContext();
    m_glfwWindow = nullptr;
    return true;
}

//--------------------------------------------------------------------------------------
// Name: Create()
// Desc: Create a drawing context.
//--------------------------------------------------------------------------------------
bool Application::CreateRenderContext()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    m_glfwWindow = glfwCreateWindow(m_nWidth, m_nHeight, m_strName.c_str(), nullptr, nullptr);
    if (m_glfwWindow == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(m_glfwWindow);
    glfwSetFramebufferSizeCallback(m_glfwWindow, framebuffer_size_callback);
    glfwSetCursorPosCallback(m_glfwWindow, mouse_callback);
    glfwSetMouseButtonCallback(m_glfwWindow, mouse_button_callback);
    glfwSetScrollCallback(m_glfwWindow, scroll_callback);

    // tell GLFW to capture our mouse
    // glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }
    return true;
}

//--------------------------------------------------------------------------------------
// Name: SwapDrawBuffers()
// Desc: Swap color buffers.
//--------------------------------------------------------------------------------------
void Application::SwapDrawBuffers()
{
    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(m_glfwWindow);
    glfwPollEvents();
}

//--------------------------------------------------------------------------------------
// Name: DestroyRenderContext()
// Desc: Cleanup EGL.
//--------------------------------------------------------------------------------------
void Application::DestroyRenderContext()
{
    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
}

//--------------------------------------------------------------------------------------
// Name: ~Application()
// Desc: Destructor
//--------------------------------------------------------------------------------------
Application::~Application()
{

}