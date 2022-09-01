#include "Shader.h"
#include "Buffer.h"

// static library that contain render command
class RenderStaticLib
{
public:
	static void StartScence();
	static void EndeScence();

	static void SetBasicColor(glm::vec4& color);
	static void SetBasicColor(float r, float g, float b, float a);

	static void Draw(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& VAO);
};
