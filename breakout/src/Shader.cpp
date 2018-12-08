#include "Shader.h"

#include <iostream>

Shader::Shader()
{
}


Shader::~Shader()
{
}

Shader& Shader::Use()
{
	glUseProgram(this->ID);
	return *this;
}

void Shader::Compile(const GLchar* vertexSource, const GLchar* fragmentSource, const GLchar* geometrySource)
{
	GLuint sVertex, sFragment, sGeo;

	sVertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(sVertex, 1, &vertexSource, nullptr);
	glCompileShader(sVertex);
	checkCompileError(sVertex, "VERTEX");

	sFragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(sFragment, 1, &fragmentSource, nullptr);
	glCompileShader(sFragment);
	checkCompileError(sFragment, "FRAGMENT");

	if(geometrySource!=nullptr)
	{
		sGeo = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(sGeo, 1, &geometrySource, nullptr);
		glCompileShader(sGeo);
		checkCompileError(sGeo, "GEOMETRY");
	}

	this->ID = glCreateProgram();
	glAttachShader(this->ID, sVertex);
	if(geometrySource!=nullptr)
	{
		glAttachShader(this->ID, sGeo);
	}

	glAttachShader(this->ID, sFragment);

	glLinkProgram(this->ID);

	checkCompileError(this->ID, "PROGRAM");

	glDeleteShader(sVertex);
	glDeleteShader(sFragment);

	if(geometrySource!=nullptr)
	{
		glDeleteShader(sGeo);
	}
}

void Shader::SetInteger(const GLchar* name, GLint value, GLboolean useShader)
{
	if (useShader)	this->Use();
	glUniform1i(glGetUniformLocation(this->ID, name), value);
}

void Shader::SetFloat(const GLchar* name, GLfloat value, GLboolean useShader)
{
	if (useShader)	this->Use();
	glUniform1f(glGetUniformLocation(this->ID, name), value);
}

void Shader::SetVector2f(const GLchar* name, glm::vec2& value, GLboolean useShader)
{
	if (useShader)	this->Use();
	glUniform2f(glGetUniformLocation(this->ID, name), value.x,value.y);
}

void Shader::SetVector2f(const GLchar* name, GLfloat x, GLfloat y, GLboolean useShader)
{
	if (useShader)	this->Use();
	glUniform2f(glGetUniformLocation(this->ID, name), x, y);
}

void Shader::SetVector3f(const GLchar* name, glm::vec3& value, GLboolean useShader)
{
	if (useShader)	this->Use();
	glUniform3f(glGetUniformLocation(this->ID, name), value.x, value.y,value.z);
}

void Shader::SetVector3f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader)
{
	if (useShader)	this->Use();
	glUniform3f(glGetUniformLocation(this->ID, name), x, y, z);
}

void Shader::SetVector4f(const GLchar* name, glm::vec4& value, GLboolean useShader)
{
	if (useShader)	this->Use();
	glUniform4f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z,value.w);
}

void Shader::SetVector4f(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader)
{
	if (useShader)	this->Use();
	glUniform4f(glGetUniformLocation(this->ID, name), x, y, z,w);
}

void Shader::SetMatrix4(const GLchar* name, glm::mat4& value, GLboolean useShader)
{
	if (useShader)	this->Use();
	glUniformMatrix4fv(glGetUniformLocation(this->ID, name),1,GL_FALSE,glm::value_ptr(value));
}

void Shader::checkCompileError(GLuint obj, std::string type)
{
	GLint success;
	GLchar infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(obj, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(obj, 1024, NULL, infoLog);
			std::cout << "| ERROR::SHADER: Compile-time error: Type: " << type << "\n"
				<< infoLog << "\n -- --------------------------------------------------- -- "
				<< std::endl;
		}
	}
	else
	{
		glGetProgramiv(obj, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(obj, 1024, NULL, infoLog);
			std::cout << "| ERROR::Shader: Link-time error: Type: " << type << "\n"
				<< infoLog << "\n -- --------------------------------------------------- -- "
				<< std::endl;
		}
	}
}
