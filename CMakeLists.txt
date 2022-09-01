cmake_minimum_required(VERSION 3.23)
project(TinyEngine)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_OSX_ARCHITECTURES "arm64")
# Add header file
file(GLOB GLM_H ${PROJECT_SOURCE_DIR}/library/platform/macos_m1/glm/0.9.9.8/include)
file(GLOB GLEW_H ${PROJECT_SOURCE_DIR}/library/platform/macos_m1/glew/2.2.0_1/include)
file(GLOB GLFW_H ${PROJECT_SOURCE_DIR}/library/platform/macos_m1/glfw/3.3.6/include)
file(GLOB OPENCV_H ${PROJECT_SOURCE_DIR}/library/platform/macos_m1/opencv/4.6.0/include/opencv4)
file(GLOB ASSIMP_H ${PROJECT_SOURCE_DIR}library/platform/macos_m1/assimp/5.2.4/include)
include_directories(${GLM_H} ${GLEW_H} ${GLFW_H} ${OPENCV_H}${ASSIMP_H})

file(GLOB GLAD_H ${PROJECT_SOURCE_DIR}/library/platform/macos_m1/glad/include)
include_directories(${GLAD_H})

file(GLOB STB_H ${PROJECT_SOURCE_DIR}/library/stb)
include_directories(${STB_H})

file(GLOB GLTF_H ${PROJECT_SOURCE_DIR}/library/gltf)
include_directories(${GLTF_H})

file(GLOB JSON_H ${PROJECT_SOURCE_DIR}/library/json)
include_directories(${JSON_H})

# Add target link
file(GLOB OPENCV_LINK ${PROJECT_SOURCE_DIR}/library/platform/macos_m1/opencv/4.6.0/lib/*.dylib)
file(GLOB GLM_LINK ${PROJECT_SOURCE_DIR}/library/platform/macos_m1/glm/0.9.9.8/lib/*.dylib)
file(GLOB GLEW_LINK ${PROJECT_SOURCE_DIR}/library/platform/macos_m1/glew/2.2.0_1/lib/*.dylib)
file(GLOB GLFW_LINK ${PROJECT_SOURCE_DIR}/library/platform/macos_m1/glfw/3.3.6/lib/*.dylib)
file(GLOB ASSIMP_LINK ${PROJECT_SOURCE_DIR}/library/platform/macos_m1/assimp/5.2.4/lib/*.dylib)
link_libraries(${GLM_LINK} ${GLEW_LINK} ${GLFW_LINK} ${OPENCV_LINK} ${ASSIMP_LINK})

# Execute compilation command
file(GLOB GLAD_SRC ${PROJECT_SOURCE_DIR}/library/platform/macos_m1/glad/src/*.c)

add_executable(TinyEngine ${GLAD_SRC}
        ${PROJECT_SOURCE_DIR}/src/main.cpp
        ${PROJECT_SOURCE_DIR}/src/Platform/Platform.h
        ${PROJECT_SOURCE_DIR}/src/Application.h          src/Application.cpp
        ${PROJECT_SOURCE_DIR}/src/Scene/Scene.h          src/Scene/Scene.cpp
        ${PROJECT_SOURCE_DIR}/src/Scene/Node.h           src/Scene/Node.cpp
        ${PROJECT_SOURCE_DIR}/src/Scene/BasicBowlNode.h  src/Scene/BasicBowlNode.cpp
        ${PROJECT_SOURCE_DIR}/src/Scene/BasicGLTFModelNode.h  src/Scene/BasicGLTFModelNode.cpp
        ${PROJECT_SOURCE_DIR}/src/Scene/BasicAssimpModelNode.h  src/Scene/BasicAssimpModelNode.cpp
        ${PROJECT_SOURCE_DIR}/src/Scene/StandardBowlNode.h  src/Scene/StandardBowlNode.cpp
        ${PROJECT_SOURCE_DIR}/src/Scene/LightCubeNode.h  src/Scene/LightCubeNode.cpp
        ${PROJECT_SOURCE_DIR}/src/Scene/SimulationCarNode.h src/Scene/SimulationCarNode.cpp
        ${PROJECT_SOURCE_DIR}/src/Core/buffer/Buffer.h   src/Core/buffer/Buffer.cpp
        ${PROJECT_SOURCE_DIR}/src/Core/shader/Shader.h   src/Core/shader/Shader.cpp
        ${PROJECT_SOURCE_DIR}/src/Core/Light/Light.h     src/Core/Light/Light.cpp
        ${PROJECT_SOURCE_DIR}/src/Core/Material/Material.h  src/Core/Material/Material.cpp
        ${PROJECT_SOURCE_DIR}/src/Core/texture/Texture.h src/Core/texture/Texture.cpp
        ${PROJECT_SOURCE_DIR}/src/Bowl/AVMBowlBuffer.h   src/Bowl/AVMBowlBuffer.cpp
        ${PROJECT_SOURCE_DIR}/src/Bowl/AVMCamera.h       src/Bowl/AVMCamera.cpp)

if (APPLE)
    target_link_libraries(TinyEngine "-framework OpenGL")
    target_link_libraries(TinyEngine "-framework GLUT")
endif()
