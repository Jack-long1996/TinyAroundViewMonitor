#ifndef SHADER_H
#define SHADER_H

#include "../../Platform/platform.h"

class Shader
{
public:
	Shader(const std::string& VertexFilePath, const std::string& FragmentFilePath);
	~Shader();

	void Use() const;
	void UnUse() const;

	/**
	* Set GLSL Shader Uniform
	* uniform  uniform name.
	* value  the value require to set
	* how to use:
	* setUniformVec3("diffuse", glm::vec3(0.1f, 0.1f, 0.1f));
	* setUniformVec3("diffuse", 0.1f, 0.1f, 0.1f);
	*/
	void setUniformBool(const std::string& uniform, bool value) const;

	void setUniformInt(const std::string& uniform, int value) const;

	void setUniformFloat(const std::string& uniform, float value) const;

	void setUniformVec2(const std::string& uniform, const glm::vec2& value) const;
	void setUniformVec2(const std::string& uniform, float x, float y) const;

	void setUniformVec3(const std::string& uniform, const glm::vec3& value) const;
	void setUniformVec3(const std::string& uniform, float x, float y, float z) const;

	void setUniformVec4(const std::string& uniform, const glm::vec4& value) const;
	void setUniformVec4(const std::string& uniform, float x, float y, float z, float w) const;

	void setUniformMat2(const std::string& uniform, const glm::mat2& mat) const;
	void setUniformMat3(const std::string& uniform, const glm::mat3& mat) const;
	void setUniformMat4(const std::string& uniform, const glm::mat4& mat) const;

private:
	unsigned int ID;   // ID of Program
};

#endif /* SHADER_H*/
