#pragma once

#include <GL/glew.h>

class Texture
{
public:
	GLuint ID;

	//dimensions
	GLuint Width, Height;

	//format
	GLuint InternalFormat;
	GLuint ImageFormat;

	//configs
	GLuint WrapS;
	GLuint WrapT;
	GLuint FilterMin;
	GLuint FilterMax;

	void Generate(GLuint _width, GLuint _height, unsigned char* data);

	void Bind() const;

	Texture();
	~Texture();


};

