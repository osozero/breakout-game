#pragma once

#include "Debug.h"
#include <map>
#include "Shader.h"
#include "Texture.h"

class ResourceManager
{
public:
	static std::map<std::string, Shader> Shaders;
	static std::map<std::string, Texture> Textures;

	static Shader LoadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile, std::string name);

	static Shader& GetShader(std::string name);

	static Texture LoadTexture(const GLchar *file, GLboolean alpha, std::string name);

	static Texture& GetTexture(std::string name);

	static void Clear();
	~ResourceManager();
private:
	ResourceManager();

	static Shader loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile = nullptr);

	static Texture loadImageFromFile(const GLchar *file, GLboolean alpha);

	static std::string read_from_file(const GLchar *file);
};

