#include "Texture.h"

void Texture::Generate(GLuint _width, GLuint _height, unsigned char* data)
{
	this->Width = _width;
	this->Height = _height;

	GLCall(glBindTexture(GL_TEXTURE_2D, this->ID));

	GLCall(glTexImage2D(GL_TEXTURE_2D, 0, this->InternalFormat, this->Width, this->Height, 0, this->ImageFormat, GL_UNSIGNED_BYTE, data));


	GLCall(glGenerateMipmap(GL_TEXTURE_2D));

	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->WrapS));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->WrapT));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->FilterMin));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->FilterMax));

	GLCall(glBindTexture(GL_TEXTURE_2D, 0));

}

void Texture::Bind() const
{
	GLCall(glBindTexture(GL_TEXTURE_2D, this->ID));
}

Texture::Texture() :Width(0), Height(0), InternalFormat(GL_RGB), ImageFormat(GL_RGB), WrapS(GL_REPEAT), WrapT(GL_REPEAT), FilterMin(GL_REPEAT), FilterMax(GL_REPEAT)
{
	GLCall(glGenTextures(1, &this->ID));
}


Texture::~Texture()
{
}
