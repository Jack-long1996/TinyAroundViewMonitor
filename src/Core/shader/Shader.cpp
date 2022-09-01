#include "Shader.h"


Shader::Shader(const std::string& VertexFilePath, const std::string& FragmentFilePath)
{
	/* shader code which have some logical statement, language is GLSL */
	std::string vertexCode;
	std::string fragmentCode;
	
	/* files which storage GLSL statement */
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	
	/* read data from file should check exceptions */
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		/* open the shader file */
		vShaderFile.open(VertexFilePath);
		fShaderFile.open(FragmentFilePath);
	
		std::stringstream vShaderStream;
		std::stringstream fShaderStream;
	
		/* read buffer in file thought stream */
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
	
		vShaderFile.close();
		fShaderFile.close();
	
		/* stringstream to string */
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure& e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
	}

	/* string to char* */
	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	unsigned int VertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(VertexShader, 1, &vShaderCode, 0);
	glCompileShader(VertexShader);

	int success = 0;
	glGetShaderiv(VertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(VertexShader, 512, NULL, infoLog);

		glDeleteShader(VertexShader);

		std::cout << "error::shader::vertex::compile_fail\n" << std::endl;
		std::cout << infoLog << std::endl;

		return;
	}

	unsigned int FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(FragmentShader, 1, &fShaderCode, 0);
	glCompileShader(FragmentShader);

	glGetShaderiv(FragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(FragmentShader, 512, NULL, infoLog);

		glDeleteShader(FragmentShader);

		std::cout << "error::shader::Fragment::compile_fail\n" << std::endl;
		std::cout << infoLog << std::endl;

		return;
	}

	ID = glCreateProgram();
	unsigned int Program = ID;

	glAttachShader(Program, VertexShader);
	glAttachShader(Program, FragmentShader);

	glLinkProgram(Program);

	glGetProgramiv(Program, GL_LINK_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetProgramInfoLog(Program, 512, NULL, infoLog);

		glDeleteProgram(Program);
		glDeleteShader(VertexShader);
		glDeleteShader(FragmentShader);

		std::cout << "error::shader::Program::link_fail " << std::endl;
		std::cout << infoLog << std::endl;

		return;
	}

	glDetachShader(Program, VertexShader);
	glDetachShader(Program, VertexShader);
}

Shader::~Shader()
{
	glDeleteProgram(ID);
}

void Shader::Use() const
{
	glUseProgram(ID);
}

void Shader::UnUse() const
{
	glUseProgram(0);
}


void Shader::setUniformBool(const std::string& uniform, bool value) const
{
	unsigned int location = glGetUniformLocation(ID, uniform.c_str());
	glUniform1i(location, (int)value);
}

void Shader::setUniformInt(const std::string& uniform, int value) const
{
	unsigned int location = glGetUniformLocation(ID, uniform.c_str());
	glUniform1i(location, value);
}

void Shader::setUniformFloat(const std::string& uniform, float value) const
{
	unsigned int location = glGetUniformLocation(ID, uniform.c_str());
	glUniform1f(location, value);
}

void Shader::setUniformVec2(const std::string& uniform, const glm::vec2& value) const
{
	unsigned int location = glGetUniformLocation(ID, uniform.c_str());
	glUniform2fv(location, 1, &value[0]);
}

void Shader::setUniformVec2(const std::string& uniform, float x, float y) const
{
	unsigned int location = glGetUniformLocation(ID, uniform.c_str());
	glUniform2f(location, x, y);
}

void Shader::setUniformVec3(const std::string& uniform, const glm::vec3& value) const
{
	unsigned int location = glGetUniformLocation(ID, uniform.c_str());
	glUniform3fv(location, 1, &value[0]);
}

void Shader::setUniformVec3(const std::string& uniform, float x, float y, float z) const
{
	unsigned int location = glGetUniformLocation(ID, uniform.c_str());
	glUniform3f(location, x, y, z);
}

void Shader::setUniformVec4(const std::string& uniform, const glm::vec4& value) const
{
	unsigned int location = glGetUniformLocation(ID, uniform.c_str());
	glUniform4fv(location, 1, &value[0]);
}

void Shader::setUniformVec4(const std::string& uniform, float x, float y, float z, float w) const
{
	unsigned int location = glGetUniformLocation(ID, uniform.c_str());
	glUniform4f(location, x, y, z, w);
}

void Shader::setUniformMat2(const std::string& uniform, const glm::mat2& mat) const
{
	unsigned int location = glGetUniformLocation(ID, uniform.c_str());
	glUniformMatrix2fv(location, 1, GL_FALSE, &mat[0][0]);
}

void Shader::setUniformMat3(const std::string& uniform, const glm::mat3& mat) const
{
	unsigned int location = glGetUniformLocation(ID, uniform.c_str());
	glUniformMatrix3fv(location, 1, GL_FALSE, &mat[0][0]);
}

void Shader::setUniformMat4(const std::string& uniform, const glm::mat4& mat) const
{
	unsigned int location = glGetUniformLocation(ID, uniform.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, &mat[0][0]);
}
