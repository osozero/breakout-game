#include "Texture.h"


void Texture::Generate(GLuint _width, GLuint _height, unsigned char* data)
{
	glCreateTextures(GL_TEXTURE_2D, 1, &this->ID);
}

void Texture::Bind() const
{
}

Texture::Texture()
{
}


Texture::~Texture()
{
}
