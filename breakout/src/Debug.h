#pragma once

#define GLEW_STATIC

#include <GL/glew.h>
#include <iostream>



#define GLCall(x) x;\
	_checkError(#x,__FILE__,__LINE__)


static void _checkError(const char *function,const char* file,int line)
{
	GLenum errorCode;
	while((errorCode = glGetError() )!= GL_NO_ERROR)
	{
		std::cout << "ERROR: " << errorCode <<", "<<function << " " << file<< ":"<< line<<std::endl;
 	}
}