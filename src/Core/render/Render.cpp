#include "Render.h"
#include "glad/glad.h"


void RenderStaticLib::StartScence()
{
}

void RenderStaticLib::EndeScence()
{
}

void RenderStaticLib::SetBasicColor(glm::vec4& color)
{
	glClearColor(color.r, color.g, color.b, color.a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void RenderStaticLib::SetBasicColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void RenderStaticLib::Draw(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& VAO)
{
	shader->Use();
	VAO->Bind();

	glDrawElements(GL_TRIANGLES, VAO->GetEBO()->GetIndexNums(), GL_UNSIGNED_INT, 0);

	VAO->UnBind();
	shader->UnUse();
}
