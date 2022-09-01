#include "Texture.h"

Texture::Texture(std::string texturePath, int width, int height)
	:m_filepath(texturePath),
	m_Width(width),
	m_Height(height)
{
	m_textureData = nullptr;
	// load picture and convey data to texture which has generated
	// unsigned char* textureData = stbi_load(texturePath.c_str(), &m_Width, &m_Height, &m_NrChannel, 0);
	// free picture data
	// stbi_image_free(textureData);
}

bool Texture::Create()
{
	int grayBytes = m_Width * m_Height * 2;
    unsigned char* uyvybuffer = new unsigned char [grayBytes];
	FILE *fp = fopen(m_filepath.c_str(), "r");
    if (fp) {
        fseek(fp, 0, SEEK_END);
        size_t _file_len = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        fread(uyvybuffer, static_cast<size_t>(_file_len), 1, fp);
        fclose(fp);
    } else {
        std::cout<<"Get ImageBuffer fp is error. Path = "<<m_filepath<<std::endl;
		return false;
    }

	cv::Mat uyvyImage(m_Height, m_Width, CV_8UC2, uyvybuffer);
    cv::Mat bgraImage;
    cv::cvtColor(uyvyImage, bgraImage, cv::COLOR_YUV2BGRA_UYVY); // COLOR_YUV2BGRA_UYVY
	cv::Mat rgbaImage;
	cv::cvtColor(bgraImage, rgbaImage, cv::COLOR_BGRA2RGBA);     // COLOR_BGRA2RGBA
	delete [] uyvybuffer;
	m_textureData = (unsigned char*)malloc(m_Width * m_Height * 4);
	memcpy(m_textureData, (unsigned char*)rgbaImage.data, m_Width * m_Height * 4);

	// generate and bind texture
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);

	// set wrap type
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// set zoom filter type
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	if (m_textureData)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_textureData);
		glGenerateMipmap(GL_TEXTURE_2D);
		return true;
	}
	else
	{
		std::cout << "ERROR::Fail to load texture" << std::endl;
		return false;
	}
}

void Texture::SetTexture2DUnit(TextureUnit unit)
{
	glActiveTexture((GLenum)unit);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::SetTexture3DUnit(TextureUnit unit)
{
	glActiveTexture((GLenum)unit);
	glBindTexture(GL_TEXTURE_3D, ID);
}

Texture::~Texture()
{
	if (m_textureData)
	{
		free(m_textureData);
	}
}